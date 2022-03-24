#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"

class Arm : public frc2::SubsystemBase {
    public:
        Arm();
        void Rotate(double speed);
        void Stop();

    private:
        // TODO make sure wiring is correct.
        // rev::CANSparkMax m_motor{6, rev::CANSparkMax::MotorType::kBrushless};

        double invert = 1;
}