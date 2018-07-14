#ifndef SRC_NERF_H_
#define SRC_NERF_H_

#include <IterativeRobot.h>
#include <WPILib.h>
#include "ctre/Phoenix.h"

class Nerf {
	public:
		Nerf(int liftMotor);
		void ChangeAngle(bool up, bool down); // 13 up, 15 down (theo)
		void Fire();


	private:
		WPI_TalonSRX j_nerfGun;

};

#endif /* SRC_NERF_H_ */
