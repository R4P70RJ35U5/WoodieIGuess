#include <WPILib.h>
#include <DiffDrive.h>
#include <Defs.h>
#include "ctre/Phoenix.h"


	DiffDrive::DiffDrive(int leftDriveOne, int leftDriveTwo, int leftDriveThree, int rightDriveOne, int rightDriveTwo, int rightDriveThree):
	a_leftDriveOne(leftDriveOne),
	  a_leftDriveTwo(leftDriveTwo),
	  a_leftDriveThree(leftDriveThree),

	  a_rightDriveOne(rightDriveOne),
	  a_rightDriveTwo(rightDriveTwo),
	  a_rightDriveThree(rightDriveThree),

	  a_Drivetrain(a_leftDriveTwo, a_rightDriveTwo)
		{
			driveType = 0;
		}
	void DiffDrive::Init(){
		a_leftDriveOne.SetInverted(true);
		a_leftDriveTwo.SetInverted(true);
		a_leftDriveThree.SetInverted(true);

		a_rightDriveOne.SetInverted(true);
		a_rightDriveTwo.SetInverted(true);
		a_rightDriveThree.SetInverted(true);


	} // For when we get sensors

	int DiffDrive::getDriveType(){
		return driveType;
	}

	void DiffDrive::setDriveType(int type) {
		driveType = type;
	}

	void DiffDrive::Update(float speed1, float speed2){
		switch(driveType){

			case 0: // Tank Drive with stick1 and stick2
				a_Drivetrain.TankDrive(speed1, speed2, false);
				break;

			case 1: // Tank Drive with the controller
				a_Drivetrain.TankDrive(speed1, speed2, false);
				break;

			case 2: // Arcade Drive with the stick2
				a_Drivetrain.ArcadeDrive(speed1, speed2, false);
				break;

			case 3: // Arcade Drive with the controller
				a_Drivetrain.ArcadeDrive(speed1, speed2, false);
				break;
			default:
				a_Drivetrain.TankDrive(0, 0, false); // For when something inevitably goes wrong
		}

	}
