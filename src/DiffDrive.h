#ifndef SRC_DIFFDRIVE_H_
#define SRC_DIFFDRIVE_H_

#include <WPILib.h>
#include "ctre/Phoenix.h"

class DiffDrive {
	public:
		DiffDrive(int leftDriveOne, int leftDriveTwo, int leftDriveThree, int rightDriveOne, int rightDriveTwo, int rightDriveThree);
		void Init();
		void setDriveType(int type);
		int getDriveType();
		void Update(float left, float right);


	private:
		WPI_TalonSRX a_leftDriveOne;
		WPI_TalonSRX a_leftDriveTwo;
		WPI_TalonSRX a_leftDriveThree;

		WPI_TalonSRX a_rightDriveOne;
		WPI_TalonSRX a_rightDriveTwo;
		WPI_TalonSRX a_rightDriveThree;

		DifferentialDrive a_Drivetrain;
		int driveType;

};

#endif /* SRC_DIFFDRIVE_H_ */
