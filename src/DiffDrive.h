#ifndef SRC_DIFFDRIVE_H_
#define SRC_DIFFDRIVE_H_

#include <WPILib.h>
#include "ctre/Phoenix.h"

class DiffDrive {
	public:
		DiffDrive(int leftDrive, int rightDrive);
		void Init();
		void setDriveType(int type);
		int getDriveType();
		void Update(float left, float right);


	private:
		WPI_TalonSRX j_leftDrive;
		WPI_TalonSRX j_rightDrive;
		DifferentialDrive j_driveTrain;
		int driveType;

};

#endif /* SRC_DIFFDRIVE_H_ */
