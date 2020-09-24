#ifndef KF_H
#define KF_H

#include <iostream>
#include "Eigen/Dense"
#include "unsupported/Eigen/MatrixFunctions"


class KF {
    public:
    // Constructor
    KF(){};
    // Destructor
    virtual ~KF(){};

    /*
     * Parameters
     */ 
    bool is_initialized_;

    // State Vector x-
    Eigen::VectorXd x_;

    // State Vector x+
    Eigen::VectorXd xpred_;

    // Transition Matrix F
    Eigen::MatrixXd F_;

    // Measurement Matrix H
    Eigen::MatrixXd H_;

    // Covariance Matrix P:KF
    Eigen::MatrixXd P_;

    // Model Uncertainty Q
    Eigen::MatrixXd Q_;

    // Measurement Noise R
    Eigen::MatrixXd R_;

    // Model Noise G
    Eigen::MatrixXd G_;

    // Measurement Vector
    Eigen::VectorXd z_;

    // Measurement Prediction
    Eigen::VectorXd zpred_;

    // ROS timings
    long long nsec_;
    long long sec_;

    // timing for kf
    double time_;

    // Dimension of State Vector
    int n_x_;
    // Dimension of Mesurement Vector
    int n_z_;

    // System Parameters

    // System Model Place Holder
    virtual void MeasModel() = 0;
    virtual void SysModel(double delta_t) = 0;

    void Prediction(double delta_t){
        Eigen::MatrixXd A = (delta_t*F_).exp();
        Eigen::MatrixXd Qd = delta_t * G_*Q_*G_.transpose();
        xpred_ = A * x_;
        P_ = (A*P_*A.transpose()) + Qd;
        P_ = (P_ + P_.transpose()) / 2.0;
    }
    
    void Update(){
        Eigen::MatrixXd S = R_ + H_*P_*H_.transpose();
        Eigen::VectorXd err = z_ - H_*xpred_;
        Eigen::MatrixXd K = P_*H_.transpose()*S.inverse();

        x_ = xpred_ + K*err;
        P_ = P_ - K*S*K.transpose();
        P_ = (P_+P_.transpose())/2.0;
    }
    
};

#endif