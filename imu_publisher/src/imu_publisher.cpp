/*
    IMU Publisher

    Jinsun Park
    (zzangjinsun@3secondz.com)
*/

#include <iostream>
#include <string>
#include <csignal>
#include <unistd.h>

#include <termios.h>
#include <fcntl.h>

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>

#define BUF_SIZE 1024
#define NUM_DATA 9
#define G_VALUE 9.80665

using namespace std;


// Global variables
bool request_stop = false;
int freq_imu, baud_rate;
string topic_imu, dev_imu;
double acc_fsr, gyr_fsr;


// Functions
void requestStopHandler(int s){
    request_stop = true;
}

string read_line_check(int fd, char* buf, int buf_size){
    bool found = false;

    while(!found){
        int cnt = 0;
        while(cnt <= 0){
            cnt = read(fd, buf, 1);
        }

        if(*buf == '$'){
            found = true;
        }
    }

    int num_space = 0;

    for(int k=1; k < buf_size; k++){
        int cnt = 0;
        while(cnt <= 0){
            cnt = read(fd, buf+k, 1);
        }

        if(*(buf+k) == ' '){
            num_space++;
        }

        if(*(buf+k) == '\n'){
            if(num_space != (NUM_DATA-1)){
                return string();
            }

            // *(buf+k) = '\0';
            string out = string(buf);
            *buf = '\0';
            return out;
        }
    }

    *buf = '\0';
    return string();
}

sensor_msgs::Imu gen_msg_from_data(char data[][BUF_SIZE], uint64_t tOffset){
    sensor_msgs::Imu imu;

    // Expected data format :
    // [$ Timestamp AccX AccY AccZ Temp GyrX GyrY GyrZ]

    // Sensor time : us -> ns
    // Ros time : ns
    uint64_t tSensor = 1000 * (uint64_t) atoi(data[1]);
    uint64_t t = tSensor + tOffset;

    imu.header.stamp.fromNSec(t);
    imu.header.frame_id = "base_link";

    // No orientation
    imu.orientation.w = 1.0;
    imu.orientation.x = 0.0;
    imu.orientation.y = 0.0;
    imu.orientation.z = 0.0;
    imu.orientation_covariance = {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    // Check Acc
    string ax = string(data[2]);
    string ay = string(data[3]);
    string az = string(data[4]);

    if((ax == "NA") || (ay == "NA") || (az == "NA")){
        imu.linear_acceleration.x = 0.0;
        imu.linear_acceleration.y = 0.0;
        imu.linear_acceleration.z = 0.0;

        imu.linear_acceleration_covariance = {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    }else{
        double axd = stod(ax);
        double ayd = stod(ay);
        double azd = stod(az);

        if((axd < INT16_MIN) || (axd > INT16_MAX) || (ayd < INT16_MIN)
            || (ayd > INT16_MAX) || (azd < INT16_MIN) || (azd > INT16_MAX)){
                imu.linear_acceleration.x = 0.0;
                imu.linear_acceleration.y = 0.0;
                imu.linear_acceleration.z = 0.0;

                imu.linear_acceleration_covariance = {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        }else{
            imu.linear_acceleration.x = axd*acc_fsr/((double) INT16_MAX);
            imu.linear_acceleration.y = ayd*acc_fsr/((double) INT16_MAX);
            imu.linear_acceleration.z = azd*acc_fsr/((double) INT16_MAX);

            // imu.linear_acceleration.x = axd;
            // imu.linear_acceleration.y = ayd;
            // imu.linear_acceleration.z = azd;

            imu.linear_acceleration_covariance = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
        }
    }

    // Check Temp
    // string temp = string(data[4]);

    // Check Gyr
    string gx = string(data[6]);
    string gy = string(data[7]);
    string gz = string(data[8]);

    if((gx == "NA") || (gy == "NA") || (gz == "NA")){
        imu.angular_velocity.x = 0.0;
        imu.angular_velocity.y = 0.0;
        imu.angular_velocity.z = 0.0;

        imu.angular_velocity_covariance = {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    }else{
        double gxd = stod(gx);
        double gyd = stod(gy);
        double gzd = stod(gz);

        if((gxd < INT16_MIN) || (gxd > INT16_MAX) || (gyd < INT16_MIN)
            || (gyd > INT16_MAX) || (gzd < INT16_MIN) || (gzd > INT16_MAX)){
                imu.angular_velocity.x = 0.0;
                imu.angular_velocity.y = 0.0;
                imu.angular_velocity.z = 0.0;

                imu.angular_velocity_covariance = {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        }else{
            imu.angular_velocity.x = gxd*gyr_fsr/((double) INT16_MAX);
            imu.angular_velocity.y = gyd*gyr_fsr/((double) INT16_MAX);
            imu.angular_velocity.z = gzd*gyr_fsr/((double) INT16_MAX);

            // imu.angular_velocity.x = gxd;
            // imu.angular_velocity.y = gyd;
            // imu.angular_velocity.z = gzd;

            imu.angular_velocity_covariance = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
        }
    }

    return imu;
}


int main(int argc, char** argv){
    ros::init(argc, argv, "imu_publisher", ros::init_options::NoSigintHandler);
    ros::NodeHandle nh("~");

    signal(SIGINT, requestStopHandler);

    nh.param("freq_imu", freq_imu, 100);
    nh.param("topic_imu", topic_imu, string("imu"));
    nh.param("dev_imu", dev_imu, string("/dev/ttyUSB0"));

    nh.param("acc_fsr", acc_fsr, 2.0);
    nh.param("gyr_fsr", gyr_fsr, 125.0);

    cout << "freq_imu           : " << freq_imu << endl;
    cout << "topic_imu          : " << topic_imu << endl;
    cout << "dev_imu            : " << dev_imu << endl;

    cout << "acc_fsr (g)        : " << acc_fsr << endl;
    acc_fsr = acc_fsr*G_VALUE;
    cout << "acc_fsr (m/s^2)    : " << acc_fsr << endl;
    cout << "gyr_fsr            : " << gyr_fsr << endl;

    // Connect to IMU device
    int fd;
    fd = open(dev_imu.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK);
    if(fd < 0){
        cout << "Failed to open " << dev_imu << endl;
        return -1;
    }
    cout << "Connected to " << dev_imu << endl;

    struct termios newtio;
    memset(&newtio, 0, sizeof(newtio));
    newtio.c_cflag = B921600 | CS8 | CLOCAL | CREAD;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 0;

    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &newtio);
    fcntl(fd, F_SETFL, FNDELAY);

    int cnt = 0;
    char buf[BUF_SIZE] = {0};
    string str_line;
    string data[NUM_DATA];

    ros::Publisher pub = nh.advertise<sensor_msgs::Imu>(topic_imu, 1);
    ros::Rate r(freq_imu);

    // Timestamp synchronization
    uint64_t tOffset = 0;

    cout << "Try time synchronization..." << endl;

    bool isInitialized = false;
    while(!isInitialized && nh.ok() && !request_stop){
        try{
            ros::Time tRos = ros::Time::now();

            str_line = read_line_check(fd, buf, BUF_SIZE);

            if(str_line.empty()){
                continue;
            }

            // Expected data format :
            // [$ Timestamp AccX AccY AccZ Temp GyrX GyrY GyrZ]
            char vals[NUM_DATA][BUF_SIZE] = {0};
            int num = sscanf(str_line.c_str(), "%s %s %s %s %s %s %s %s %s",
                                vals[0], vals[1], vals[2], vals[3],
                                vals[4], vals[5], vals[6], vals[7], vals[8]);

            if(num != NUM_DATA){
                continue;
            }

            // Sensor time : us -> ns
            // Ros time : ns
            uint64_t tSensor = 1000 * (uint64_t) atoi(vals[1]);
            uint64_t tRosNs = tRos.toNSec();
            tOffset = tRosNs - tSensor;

            ROS_INFO_STREAM_NAMED(__FILE__, "Initialization done - Sensor time : " << tSensor << ", ROS time : " << tRosNs << ", Offset : " << tOffset);

            isInitialized = true;
        }catch(exception& e){
            cout << "Exception occured : " << e.what() << endl;
        }
        
        if(isInitialized){
            cout << "Time synchronization is finished." << endl;
        }else{
            cout << "Try time synchronization again..." << endl;
        }
        r.sleep();
    }

    while(nh.ok() && !request_stop){
        try{
            str_line = read_line_check(fd, buf, BUF_SIZE);

            if(str_line.empty()){
                continue;
            }

            // Expected data format :
            // [$ Timestamp AccX AccY AccZ Temp GyrX GyrY GyrZ]
            char vals[NUM_DATA][BUF_SIZE] = {0};
            int num = sscanf(str_line.c_str(), "%s %s %s %s %s %s %s %s %s",
                                vals[0], vals[1], vals[2], vals[3],
                                vals[4], vals[5], vals[6], vals[7], vals[8]);

            if(num != NUM_DATA){
                continue;
            }

            sensor_msgs::Imu msg = gen_msg_from_data(vals, tOffset);

            pub.publish(msg);
        }catch(exception& e){
            cout << "Exception occured : " << e.what() << endl;
        }
        
        r.sleep();
    }

    cout << "imu_publisher finished" << endl;
    return 0;

}