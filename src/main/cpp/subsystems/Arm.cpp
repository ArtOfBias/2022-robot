#include "subsystems/Arm.h"

#include <frc/smartdashboard/SmartDashboard.h>

Intake::Arm(){
    m_motor.RestoreFactoryDefaults();
    SetName("Arm");
}

void Arm::Rotate(double speed){
    m_motor.Set(speed * invert);
}

void Arm::Stop(){
    m_motor.Set(0);
}
