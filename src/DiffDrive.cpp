#include <WPILib.h>
#include <DiffDrive.h>
#include <Defs.h>
#include "ctre/Phoenix.h"


	DiffDrive::DiffDrive(int leftDrive, int rightDrive):
		j_leftDrive(leftDrive),
		j_rightDrive(rightDrive),
		j_driveTrain(j_leftDrive, j_rightDrive)
		{
			driveType = 0;
		}
	void DiffDrive::Init(){ } // For when we get sensors

	int DiffDrive::getDriveType(){
		return driveType;
	}

	void DiffDrive::setDriveType(int type) {
		driveType = type;
	}

	void DiffDrive::Update(float speed1, float speed2){
		switch(driveType){

			case 0: // Tank Drive with stick1 and stick2
				j_driveTrain.TankDrive(speed1, speed2, false);
				break;

			case 1: // Tank Drive with the controller
				j_driveTrain.TankDrive(speed1, speed2, false);
				break;

			case 2: // Arcade Drive with the stick2
				j_driveTrain.ArcadeDrive(speed1, speed2, false);
				break;

			case 3: // Arcade Drive with the controller
				j_driveTrain.ArcadeDrive(speed1, speed2, false);
				break;
			default:
				j_driveTrain.TankDrive(0, 0, false); // For when something inevitably goes wrong
		}

	}
