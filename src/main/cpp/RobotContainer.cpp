// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/TankDrive.h"
#include "commands/SpinPropeller.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  m_drivetrain.SetDefaultCommand(TankDrive(
    [this] {return (m_stick2.GetY() * (-m_stick2.GetThrottle() + 2) / 3) * (int)!(bool)round((-m_stick1.GetThrottle() + 1) / 2)/*tank*/
            + (m_stick2.GetY() + m_stick2.GetZ()) * ((-m_stick2.GetThrottle() + 2) / 3) * (int)round((-m_stick1.GetThrottle() + 1) / 2)
            ; }, 
    [this] {return ((m_stick1.GetY() * ((int)!m_stick2.GetRawButton(1)) + m_stick2.GetY() * ((int)m_stick2.GetRawButton(1))) * (-m_stick2.GetThrottle() + 2) / 3) * (int)!(bool)round((-m_stick1.GetThrottle() + 1) / 2)/*tank*/
            + (m_stick2.GetY() - m_stick2.GetZ()) * ((-m_stick2.GetThrottle() + 2) / 3) * (int)round((-m_stick1.GetThrottle() + 1) / 2)
            ; }, 
    m_drivetrain));

  // Configure the button bindings
  ConfigureButtonBindings();

}

void RobotContainer::ConfigureButtonBindings() {
    frc2::JoystickButton(&m_stick2,2).WhenPressed(
        SpinPropeller(m_propeller)
    );
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
