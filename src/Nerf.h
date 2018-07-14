#ifndef SRC_NERF_H_
#define SRC_NERF_H_

#include <IterativeRobot.h>
#include <WPILib.h>
#include "ctre/Phoenix.h"

class Nerf {
	public:
		Nerf(int liftMotor);
		void ChangeAngle(int speed);
		void Fire();
		void StopFire();


	private:
		WPI_TalonSRX j_angleMotor;
		DigitalOutput j_Fires;

};

#endif /* SRC_NERF_H_ */
