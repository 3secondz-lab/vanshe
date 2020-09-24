#ifndef MISALIGN_H_
#define MISALIGN_H_

#include <cstddef>
#include "Eigen/Dense"
#include "kf.h"


class Misalign : public KF
{
    public:

    // Misalignment Angle
    static constexpr size_t ALPHA = 0;
    static constexpr size_t BETA = 1;
    static constexpr size_t GAMMA = 2;

    // Odometery Lever Arm
    static constexpr size_t LOX = 3;
    static constexpr size_t LOY = 4;
    static constexpr size_t LOZ = 5;

    void TranModel(void) {

    }

    void MeasModel(void) {

    }

};

#endif