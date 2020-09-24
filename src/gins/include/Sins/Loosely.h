#ifndef LOOSELY_H_
#define LOOSELY_H_
#define _USE_MATH_DEFINES

#include <math.h>
#include <cstddef>
#include "Sins/kf.h"
#include "Tools.h"
// #include <yaml-cpp/yaml.h>

class Loosely : public KF
{
public:

    int n_state = 18;
    int n_measure = 6;
    int n_noise = 12;


    double freq = 100.0;
    // double std_gyr_rw = sqrt(freq)*0.0038*M_PI/180.0;
    // double std_acc_rw = sqrt(freq)*0.00007*9.81;
    // double std_gyr_bs = 0.0038*M_PI/180.0;
    // double std_acc_bs = 0.00007*9.81;
    // double std_gyr_bias = sqrt(0.5*M_PI/180.0);
    // double std_acc_bias = sqrt(0.002*9.81);
    // double std_lg = 0.2;
    // double std_gnss_v = 0.4;

    double std_gyr_rw = 0.01;
    double std_acc_rw = 0.15;
    double std_gyr_bs = 0.00005;
    double std_acc_bs = 0.0005;
    // double std_gyr_bias = std_gyr_bs*100;
    // double std_acc_bias = std_acc_bs*1000;

    double std_gyr_bias = std_gyr_bs*10;
    double std_acc_bias = std_acc_bs*10;

    double std_lg = 0.01;
    double std_gnss_v = 0.1;

    double std_att = 0.1;

    // Cartesian origin

    double lat = -1;
    double lon = -1;

    // YAML::Node config = YAML::LoadFile("LCconfig.yaml");
    // Global Position
    static constexpr size_t LAT = 0;
    static constexpr size_t LON = 1;
    static constexpr size_t ALT = 2;

    // Global Velocity (ENU)
    static constexpr size_t VELX = 3;
    static constexpr size_t VELY = 4;
    static constexpr size_t VELZ = 5;

    // Euler Angles (ENU)
    static constexpr size_t PHI = 6;
    static constexpr size_t THETA = 7;
    static constexpr size_t PSI = 8;

    // Accelerometer Bias (m/s2)
    static constexpr size_t BAX = 9;
    static constexpr size_t BAY = 10;
    static constexpr size_t BAZ = 11;

    // Gyroscope Bias (m/s2)
    static constexpr size_t BGX = 12;
    static constexpr size_t BGY = 13;
    static constexpr size_t BGZ = 14;

    // GPS Ant. Lever Arm (m)
    static constexpr size_t LGX = 15;
    static constexpr size_t LGY = 16;
    static constexpr size_t LGZ = 17;

    // Matrix Constants

    const Eigen::Matrix3d O_ = Eigen::Matrix3d::Zero(3, 3);
    const Eigen::Matrix3d I_ = Eigen::Matrix3d::Identity(3, 3);

    // System State x
    // Caution : kalman filter state x_ : error state
    //           system state x : INS mechanization state
    Eigen::VectorXd x;
    Eigen::Quaterniond q;
    // Sensor Measurements
    Eigen::Vector3d a;
    Eigen::Vector3d w;

    Eigen::Vector3d p_gps;
    Eigen::Vector3d v_gps;
    Eigen::Vector3d dop_gps;

    double imu_t;
    double gnss_t;

    int count = 0;

    Loosely(){
        x = Eigen::VectorXd(n_state);
        x_ = Eigen::VectorXd(n_state);
        xpred_ = Eigen::VectorXd(n_state);
        z_ = Eigen::VectorXd(n_measure);
        zpred_ = Eigen::VectorXd(n_measure);

        F_ = Eigen::MatrixXd(n_state,n_state);
        H_ = Eigen::MatrixXd(n_measure,n_state);
        P_ = Eigen::MatrixXd(n_state,n_state);
        Q_ = Eigen::MatrixXd(n_noise,n_noise);
        R_ = Eigen::MatrixXd(n_measure,n_measure);
        G_ = Eigen::MatrixXd(n_state,n_noise);

        is_initialized_ = false;

    }

    void SysModel(double delta_t)
    {   
        a = a - ab;
        w = w - wb;

        AttUpdate(delta_t);

        f = ctm*a - g;

        VelUpdate(delta_t);
        PosUpdate(delta_t);

        x << p, v, r, ab, wb, lg;

        UpdateF();
    }

    void MeasModel(void)
    {
        z_ << p_gps, v_gps;
        zpred_ << p+ctm*lg, v+ctm*Skew(w)*lg;
        z_ = zpred_ - z_;

        UpdateH();
    }
    // gnss << px, py, pz, vx, vy, vz, cog, horizontalaccu, verticalaccu, speedaccu, headingacc, 
    void InitState(Eigen::VectorXd gnss)
    {
        is_initialized_ = true;

        time_ = gnss[11];
        gnss_t = time_;

        x << gnss.segment<3>(0),    
             gnss.segment<3>(3), 
             0, 0, gnss.segment<1>(6), 
             0.2, -0.2, 0.15, 0.005, -0.008, 0.004,
             -0.2, 0, 0.7;

        x_ << Eigen::VectorXd::Zero(9), 
              0.2, -0.2, 0.15, 0.005,
              -0.008, 0.004, 0,0,0;

        g << 0,0,9.81;

        Eigen::VectorXd P_vec(n_state);

        P_vec << gnss[7], gnss[7], gnss[8],
                 gnss[8], gnss[8], gnss[8],
                 std_att, std_att, std_att,
                 std_acc_bias, std_acc_bias, std_acc_bias,
                 std_gyr_bias, std_gyr_bias, std_gyr_bias,
                 std_lg, std_lg, std_lg;
        P_ = P_vec.asDiagonal();
        P_ = P_*P_;
        Eigen::VectorXd Q_vec(n_noise);

        Q_vec << std_acc_rw, std_acc_rw, std_acc_rw,
                 std_gyr_rw, std_gyr_rw, std_gyr_rw,
                 std_acc_bs, std_acc_bs, std_acc_bs,
                 std_gyr_bs, std_gyr_bs, std_gyr_bs;
        Q_ = Q_vec.asDiagonal();
        Q_ = Q_*Q_;
        std::cout << gnss << std::endl;
        ctm = eulerToCtm(x.segment<3>(6)).transpose();
        q = ctmToQua(ctm);

        p = x.segment<3>(0);
        v = x.segment<3>(3);
        r = x.segment<3>(6);
        ab = x.segment<3>(9);
        wb = x.segment<3>(12);
        lg = x.segment<3>(15);



    }
    
    void Estimate(Eigen::VectorXd measure, std::string type)
    {   
        if(is_initialized_)
        {
            if(type == "gnss")
            {
                Eigen::VectorXd gnss = measure;
                time_ = gnss[11];
                double delta_t = time_-gnss_t;
                gnss_t = time_;
                // Kalman Filtering with gnss
                p_gps = gnss.segment<3>(0);
                v_gps = gnss.segment<3>(3);
                // SysModel(delta_t);
                // Prediction(delta_t);

                Eigen::VectorXd R_vec(n_measure);

                R_vec << gnss[7], gnss[7], gnss[8],
                        std_gnss_v, std_gnss_v, std_gnss_v;

                R_ = R_vec.asDiagonal();
                R_ = R_*R_;

                

                MeasModel();
                Update();

                PvtComp();
            }
            else
            {
                Eigen::VectorXd imu = measure;
                // Only integrate imu signals
                double delta_t = imu[6]-imu_t;
                // std::cout<<delta_t<<std::endl;
                imu_t = imu[6];
                a = imu.segment<3>(0);
                w = imu.segment<3>(3);

                SysModel(delta_t);
                Prediction(delta_t);
            }
        }
        else
        {
            if(type == "gnss")
            {
                if (count < 30)
                {
                    count++;
                    return;
                }
                Eigen::VectorXd gnss = measure;
                InitState(gnss);
            }
            else
            {
                Eigen::VectorXd imu = measure;
                imu_t = imu[6];
                a = 0.9*a + 0.1*imu.segment<3>(0);
                w = 0.9*w + 0.1*imu.segment<3>(3);
                if (count == 2)
                {
                    a = imu.segment<3>(0);
                    w = imu.segment<3>(3);
                }
            }
            
        }

    }

protected:
    Eigen::Vector3d dp;
    Eigen::Vector3d dv;
    Eigen::Vector3d dr;
    Eigen::Vector3d dab;
    Eigen::Vector3d dwb;
    Eigen::Vector3d dlg;

    Eigen::Vector3d p;
    Eigen::Vector3d v;
    Eigen::Vector3d r;
    Eigen::Vector3d ab;
    Eigen::Vector3d wb;
    Eigen::Vector3d lg;


    Eigen::Quaterniond dq;

    Eigen::Vector3d f;
    Eigen::Vector3d g;

    Eigen::Matrix3d ctm;

    void AttUpdate(double delta_t)
    {
        if (w.norm() < 0.0001)
        {
            return;
        }
        else
        {
            double co = cos(0.5 * w.norm() * delta_t);
            double si = sin(0.5 * w.norm() * delta_t);

            Eigen::Vector3d nw = w.normalized();

            Eigen::Quaterniond qw;

            qw.w() = co;
            qw.vec() = nw * si;

            qw = qw.normalized();

            q = q * qw;


            ctm = quaToCtm(q);
            r = quaToEuler(q);
            return;
        }
    }

    void VelUpdate(double delta_t)
    {
        v = v + f * delta_t;
        return;
    }

    void PosUpdate(double delta_t)
    {
        p = p + v * delta_t;
        return;
    }

    void PvtComp()
    {
        dp = x_.segment<3>(0);
        dv = x_.segment<3>(3);
        dr = x_.segment<3>(6);
        dab = x_.segment<3>(9);
        dwb = x_.segment<3>(12);
        dlg = x_.segment<3>(15);

        p = x.segment<3>(0);
        v = x.segment<3>(3);
        r = x.segment<3>(6);
        ab = x.segment<3>(9);
        wb = x.segment<3>(12);
        lg = x.segment<3>(15);

        /*
        Attitude Correction
        */

        Eigen::Matrix3d antm;

        antm = -1.0*Skew(q.vec());
        
        q.vec() = q.vec() + 0.5* (q.w()*Eigen::Matrix3d::Identity() + antm)*dr;
        q.w() = q.w() - 0.5*q.vec().dot(dr);
        q = q.normalized();

        ctm = quaToCtm(q);
        r = quaToEuler(q);

        /*
        Velocity Correction
        */
        v = v - dv;

        /*
        Position Correction
        */
        p = p - dp;
        /*
        Bias Correction
        */
        ab = dab;
        wb = dwb;

        /*
        GPS Leverarm Correction
        */
        lg = lg - dlg;

        x << p, v, r, ab, wb, lg;
        x_ = Eigen::VectorXd::Zero(x.size());
        x_.segment<6>(BAX) << ab, wb;
    }

    void UpdateF()
    {

        F_ << O_, I_, O_, O_, O_, O_,
              O_, O_, Skew(f), ctm, O_, O_,
              O_, O_, O_, O_, -ctm, O_,
              O_, O_, O_, O_, O_, O_,
              O_, O_, O_, O_, O_, O_,
              O_, O_, O_, O_, O_, O_;
/* Bias Estimation Sign Check F_, G_, H_ */
        G_ << O_, O_, O_, O_,
              ctm, O_, O_, O_,
              O_, -ctm, O_, O_,
              O_, O_, I_, O_,
              O_, O_, O_, I_,
              O_, O_, O_, O_;
    }

    void UpdateH()
    {
        H_ << I_, O_, ctm*Skew(lg)*ctm.transpose(), O_, O_, ctm,
              O_, I_, -ctm*(Skew(lg)*Skew(w)-Skew(w)*Skew(lg))*ctm.transpose(), O_, -ctm*Skew(lg), ctm*Skew(w);
    }

    Eigen::Matrix3d Skew(Eigen::Vector3d v)
    {
        Eigen::Matrix3d S;
        S << 0.0, -v[2], v[1],
            v[2], 0.0, -v[0],
            -v[1], v[0], 0.0;

        return S;
    }

};
#endif