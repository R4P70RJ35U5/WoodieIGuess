#include <Woodie.h>
#include <WPILib.h>
#include <Defs.h>
#include <DiffDrive.h>
#include <Nerf.h>
#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

	Woodie::Woodie(void):
		j_Joystick1(JOYSTICK1_PORT),
		j_Joystick2(JOYSTICK2_PORT),
		j_Controller(CONTROLLER_PORT),
		j_diffDrive(TALON_LEFT, TALON_RIGHT),
		j_nerf1(TALON_NERF),
		j_leftEncoder(8,9,true),
		j_rightEncoder(6,7,false)
		{
			SmartDashboard::init();
		}

	void  Woodie::RobotInit() { }

	void  Woodie::RobotPeriodic() { }

	void  Woodie::DisabledInit() { }

	void  Woodie::DisabledPeriodic() {

		SmartDashboard::PutBoolean("Enabled", false);
	}

	void  Woodie::AutonomousInit() { }

	void  Woodie::AutonomousPeriodic() { }

	void  Woodie::TeleopInit() {

		SmartDashboard::PutString("Drive Type:", "Tank Joysticks");
		j_diffDrive.setDriveType(0);

	}

	void  Woodie::TeleopPeriodic() {

		SmartDashboard::PutBoolean("Enabled", true);
		// These button and axis numbers are theo af cause like I don't have the joysticks or controller with me

		if(j_Joystick2.GetRawButton(1)) { // Tank Drive with stick1 and stick2
			j_diffDrive.setDriveType(0);
		};

		if(j_Joystick2.GetRawButton(2)) { // Tank Drive with the controller
			j_diffDrive.setDriveType(1);
		};

		if(j_Joystick2.GetRawButton(3)) { // Arcade Drive with the stick2
			j_diffDrive.setDriveType(2);
		};

		if(j_Joystick2.GetRawButton(4)) { // Arcade Drive with the controller
			j_diffDrive.setDriveType(3);
		};



		if(j_diffDrive.getDriveType() == 0) {
			SmartDashboard::PutString("Drive Type:", "Tank Joysticks");
			j_diffDrive.Update(j_Joystick1.GetRawAxis(1), j_Joystick2.GetRawAxis(1));
		};

		if(j_diffDrive.getDriveType() == 1) {
			SmartDashboard::PutString("Drive Type:", "Tank Controller");
			j_diffDrive.Update(j_Controller.GetRawAxis(2), j_Controller.GetRawAxis(1));
		};

		if(j_diffDrive.getDriveType() == 2) {
			SmartDashboard::PutString("Drive Type:", "Arcade Joystick2");
			j_diffDrive.Update(j_Joystick2.GetRawAxis(1), j_Joystick2.GetRawAxis(0));
		};

		if(j_diffDrive.getDriveType() == 3) {
			SmartDashboard::PutString("Drive Type:", "Arcade Controller");
			j_diffDrive.Update(j_Controller.GetRawAxis(1),j_Controller.GetRawAxis(0));
		};

		if(j_Controller.GetRawButton(2)){
			j_nerf1.Fire();

		}



	}

	void  Woodie::TestInit() { }

	void  Woodie::TestPeriodic() { }

	Woodie::~Woodie() { }

	START_ROBOT_CLASS(Woodie);
