#include "commands/ArmDrive.h"

#include <utility>

#include "Robot.h"

ArmdDrive::ArmDrive(
        std::function<double()> speed,
        Arm& arm):
            m_arm