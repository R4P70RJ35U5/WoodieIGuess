#ifndef SRC_WOODIE_H_
#define SRC_WOODIE_H_

#include <IterativeRobot.h>
#include <WPILib.h>
#include <DiffDrive.h>
#include <Nerf.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"


class Woodie : public IterativeRobot {
	public:
		Woodie(void);

		void RobotInit(void);
		void RobotPeriodic(void);

		void AutonomousInit(void);
		void AutonomousPeriodic(void);

		void DisabledInit(void);
		void DisabledPeriodic(void);

		void TeleopInit(void);
		void TeleopPeriodic(void);

		void TestInit(void);
		void TestPeriodic(void);

		~Woodie(void);

	private:
		Joystick j_Joystick1; // Slot 1
		Joystick j_Joystick2; // Slot 2
		Joystick j_Controller; // Slot 3

		DiffDrive j_diffDrive;

		Nerf j_nerf1;

		Encoder j_leftEncoder;
		Encoder j_rightEncoder;
};
#endif /* SRC_WOODIE_H_ */
