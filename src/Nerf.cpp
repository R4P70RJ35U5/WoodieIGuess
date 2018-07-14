#include <IterativeRobot.h>
#include <WPILib.h>
#include <Nerf.h>
#include <Defs.h>
#include "ctre/Phoenix.h"

	Nerf::Nerf(int liftMotor):
		j_angleMotor(liftMotor),
		j_Fires(RELAY_1)
		{

		}
	void Nerf::ChangeAngle(int speed){
		j_angleMotor.Set(speed);
		}

	void Nerf::Fire(){
		j_Fires.Set(true);
		}
	void Nerf::StopFire(){
		j_Fires.Set(false);
	}

