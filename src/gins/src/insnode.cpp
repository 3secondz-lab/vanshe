/*
    GPSINS

    Yunjin Hwang
    (yoonjinh@3secondz.com)
*/

// #include <Sins/Loosely.h>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <ublox_msgs/ublox_msgs.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
// #include <gins/ins.h>
#include "Sins/kf.h"
#include "Sins/Loosely.h"
#include "Eigen/Dense"
#include <math.h>

#define R0 6378137.0
#define E 0.003352810664747
#define sind(x) (sin(x*M_PI/180.0))
#define cosd(x) (cos(x*M_PI/180.0))

double Rn;
double Re;
double Ra;

Loosely lckf;

geometry_msgs::PoseStamped mPoseStamped;
geometry_msgs::Pose mPose;
nav_msgs::Path mPath;



ros::Publisher* pub;


void insCallback(sensor_msgs::Imu imu)
{
    // std::cout << "Linear Acceleration : " << std::endl;
    // std::cout << "  x:" << imu.linear_acceleration.x << std::endl;
    // std::cout << "  y:" << imu.linear_acceleration.x << std::endl;
    // std::cout << "  z:" << imu.linear_acceleration.x << std::endl;

    // std::cout << "Anglular Velocity : " << std::endl;
    // std::cout << "  x:" << imu.angular_velocity.x << std::endl;
    // std::cout << "  y:" << imu.angular_velocity.x << std::endl;
    // std::cout << "  z:" << imu.angular_velocity.x << std::endl;
    Eigen::VectorXd measure(7);
    measure << (double)imu.linear_acceleration.x,
               (double)imu.linear_acceleration.y,
               (double)imu.linear_acceleration.z,
               (double)imu.angular_velocity.x,
               (double)imu.angular_velocity.y,
               (double)imu.angular_velocity.z,
               (double)imu.header.stamp.toSec();
    lckf.Estimate(measure, "imu");
    mPoseStamped.header = imu.header;
    // Set ins message


    // Set Pose/position message
    mPose.position.x = lckf.x[0];
    mPose.position.y = lckf.x[1];
    mPose.position.y = lckf.x[2];
    // Set Pose/Quaternion message
    mPose.orientation.x = lckf.q.vec()[0];
    mPose.orientation.y = lckf.q.vec()[1];
    mPose.orientation.z = lckf.q.vec()[2];
    mPose.orientation.w = lckf.q.w();

    mPoseStamped.pose = mPose;

    pub->publish(mPose);

    // mPath.header = imu.header;
    // mPath.poses = 
    // std::cout<< "ATT: " << lckf.x.segment<3>(6)<<std::endl;
}

void gpsCallback(ublox_msgs::NavPVT navpvt)
{
    if (!lckf.is_initialized_)
    {
        lckf.lat = (double)navpvt.lat/1e7;
        lckf.lon = (double)navpvt.lon/1e7;
        
        Rn = R0*(1-E*E) / (std::pow(1-E*E*std::pow(sind(lckf.lat),2),1.5));
        Re = R0/(std::pow(1-E*E*std::pow(sind(lckf.lat),2),0.5));
        Ra = Re*Rn / sqrt(Re*Re*std::pow(sind(lckf.lat),2) + Rn*Rn*std::pow(cosd(lckf.lat),2));
        // std::cout << "Re" << Re << std::endl << "Ra" << Ra << std::endl;
    }
    // Convert (lat, lon) to ECEF XY
    double lat = (double)navpvt.lat/1e7;
    double lon = (double)navpvt.lon/1e7;
    double height = (double)navpvt.height/1e3;

    double deltaLat = M_PI*(lat - lckf.lat)/180.0;
    double deltaLon = M_PI*(lon - lckf.lon)/180.0;

    double px = Ra*cosd(lckf.lat)*deltaLon;
    double py = Rn*deltaLat;
    Eigen::VectorXd measure(12);
    measure << px,
               py,
               (double)navpvt.height/1e3,
               (double)navpvt.velE/1e3,
               (double)navpvt.velN/1e3,
               -(double)navpvt.velD/1e3,
               M_PI*(-(double)navpvt.heading/1e5 + 90.0)/180.0,
               (double)navpvt.hAcc/1e3,
               (double)navpvt.vAcc/1e3,
               (double)navpvt.sAcc/1e3,
               (double)navpvt.headAcc/1e5,
               (double)ros::Time::now().toSec();
    // std::cout << measure << std::endl;
    lckf.Estimate(measure, "gnss");
    
    std::cout<< "POS: " << lckf.x.segment<3>(0)<<std::endl;
    std::cout<< "VEL: " << lckf.x.segment<3>(3)<<std::endl;
    std::cout<< "ATT: " << lckf.x.segment<3>(6)<<std::endl;
    std::cout<< "ACCB: " << lckf.x.segment<3>(9)<<std::endl;
    std::cout<< "GYRB: " << lckf.x.segment<3>(12)<<std::endl;
    std::cout<< "LEVA: " << lckf.x.segment<3>(15)<<std::endl;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ins_publisher");
    ros::NodeHandle nh("~");

    ros::Rate r(100); // 프리퀀시 없이 imu 들어오면 ㄱㄱ하도록

    int queue_size = 1;

    ros::Publisher pub_ins = nh.advertise<geometry_msgs::Pose>("/gins/pose", queue_size);
    pub = &pub_ins;
    ros::Subscriber sub_imu = nh.subscribe("/imu/imu", queue_size, insCallback);
    ros::Subscriber sub_gps = nh.subscribe("/gps/navpvt", queue_size, gpsCallback);

    ros::spin();
}