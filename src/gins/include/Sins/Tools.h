#ifndef INSTOOLS_H_
#define INSTOOLS_H_

#include "Eigen/Dense"
#include "Eigen/Geometry"
#include <math.h>

Eigen::Matrix3d eulerToCtm(Eigen::Vector3d euler)
{
    Eigen::Matrix3d cx, cy, cz;
    cx << 1,0,0,
          0,cos(euler(0)),sin(euler(0)),
          0,-sin(euler(0)),cos(euler(0));

    cy << cos(euler(1)),0,-sin(euler(1)),
          0,1,0,
          sin(euler(1)),0,cos(euler(1));

    cz << cos(euler(2)),sin(euler(2)),0,
          -sin(euler(2)),cos(euler(2)),0,
          0,0,1;
    
    return cx*cy*cz;;
}

Eigen::Vector3d ctmToEuler(Eigen::Matrix3d ctm)
{
    Eigen::Vector3d euler;
    euler(0) = atan2(ctm(1,2), ctm(2,2));
    euler(1) = -asin(ctm(0,2));
    euler(2) = atan2(ctm(0,1), ctm(0,0));

    return euler;
}

Eigen::Matrix3d quaToCtm(Eigen::Quaterniond qua)
{
    double a = qua.w();
    double b = qua.vec()(0);
    double c = qua.vec()(1);
    double d = qua.vec()(2);

    Eigen::Matrix3d ctm;
    ctm(0,0) = a*a + b*b - c*c - d*d;
    ctm(0,1) = 2*(b*c - a*d);
    ctm(0,2) = 2*(a*c + b*d);
    ctm(1,0) = 2*(a*d + b*c);
    ctm(1,1) = a*a - b*b + c*c - d*d;
    ctm(1,2) = 2*(c*d - a*b);
    ctm(2,0) = 2*(b*d - a*c);
    ctm(2,1) = 2*(c*d + a*b);
    ctm(2,2) = a*a - b*b - c*c + d*d;

    return ctm;
}

Eigen::Quaterniond ctmToQua(Eigen::Matrix3d ctm)
{
    Eigen::Quaterniond qua;

    qua.w() = 0.5 * sqrt(1+ctm(0,0)+ctm(1,1)+ctm(2,2));
    qua.vec()(0) = (ctm(2,1)-ctm(1,2))/(4*qua.w());
    qua.vec()(1) = (ctm(0,2)-ctm(2,0))/(4*qua.w());
    qua.vec()(2) = (ctm(1,0)-ctm(0,1))/(4*qua.w());

    return qua;
}

Eigen::Quaterniond eulerToQua(Eigen::Vector3d eul)
{
    Eigen::Vector3d euler = eul.reverse();
    Eigen::Vector3d c, s;
    c = (euler/2).array().cos();
    s = (euler/2).array().sin();

    Eigen::Quaterniond qua;
    qua.w() = c(0)*c(1)*c(2) + s(0)*s(1)*s(2);
    qua.vec()(0) = c(0)*c(1)*s(2) - s(0)*s(1)*c(2);
    qua.vec()(1) = c(0)*s(1)*c(2) + s(0)*c(1)*s(2);
    qua.vec()(2) = s(0)*c(1)*c(2) - c(0)*s(1)*s(2);

    return qua;
}

Eigen::Vector3d quaToEuler(Eigen::Quaterniond qua)
{
    return ctmToEuler(quaToCtm(qua).transpose());
}
#endif 