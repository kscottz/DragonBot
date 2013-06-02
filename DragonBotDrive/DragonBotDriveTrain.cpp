#include "WPILib.h"
#include "Gamepad.h"

class DragonBotDriveTrain : public IterativeRobot
{
	static const int FRONT_LEFT_PWM = 1;
	static const int FRONT_RIGHT_PWM = 2;
	static const int BACK_LEFT_PWM = 3;
	static const int BACK_RIGHT_PWM = 4;
	
	RobotDrive * drive;
	Gamepad * gamepad;
	
public:
	DragonBotDriveTrain(void)	{
		drive = new RobotDrive(
			new Victor(FRONT_LEFT_PWM),
			new Victor(BACK_LEFT_PWM),
			new Victor(FRONT_RIGHT_PWM),
			new Victor(BACK_RIGHT_PWM)
		);
		gamepad = new Gamepad(1);
	}
	
	
	/********************************** Init Routines *************************************/

	void RobotInit(void) {

	}
	
	void DisabledInit(void) {

	}

	void AutonomousInit(void) {

	}

	void TeleopInit(void) {
		
	}

	/********************************** Periodic Routines *************************************/
	
	void DisabledPeriodic(void)  {
		drive->MecanumDrive_Cartesian(0.0f,0.0f,0.0f);
	}

	void AutonomousPeriodic(void) {
		
	}

	
	void TeleopPeriodic(void) {
		float x = gamepad->GetLeftX();
		float y = gamepad->GetLeftY();
		float rot = gamepad->GetRightX();
		
		drive->MecanumDrive_Cartesian(x,y,rot);
	}


			
};

START_ROBOT_CLASS(DragonBotDriveTrain);
