/*							INSTRUCTIONS!!!110NE
 *							Bullet points:
 *	Gamepad 1 (Number buttons)
 *		-Left joystick moves forward and backward and strafes.
 *		-Right joystick rotates.
 *		
 *	Gamepad 2 (Lettered buttons)
 *		-Left joystick controls eyes.
 *		-A locks eyes
 *		-B shoots smoke.
 *		-Y makes smoke.
 *		-RB and RT move head and jaw up and down respectively.
 *		-LB and LT move jaw up and down respectively.
 *		-D-Pad makes sounds (unimplemented).
 *	
 *							In- Depth:
 *	There are two gamepads (control thingies). One has black buttons (push thingies) with numbers. 
 *	This is the driving gamepad.
 *	The left joystick up and down controls forward and backward respectively. The right and left
 *	button control right and left respectively. On the right joystick, left and right control
 *	rotating left and right respectively.
 *	
 *	On the other gamepad (with lettered buttons), it's more complex. Press A (green button) to lock eyes
 *	in their current position. Hold B for a short time(red button) to shoot smoke. 
 *	Hold Y (yellow) to make smoke. Moving the left joystick right changes eye position. RB moves the head and jaw up; 
 *	however, RT moves the head and jaw down. Holding the LB moves the jaw up; holding the LT moves the jaw down. 
 *	The D-pad controls sounds; unfortunately, this has not been implemented as of yet. 
 */
#include "WPILib.h"
#include "Gamepad.h"
#include "Relay.h"

class DragonBotDriveTrain : public IterativeRobot
{
	//PWM's
	static const int FRONT_LEFT_PWM = 1;
	static const int FRONT_RIGHT_PWM = 2;
	static const int BACK_LEFT_PWM = 3;
	static const int BACK_RIGHT_PWM = 4;
	static const int SMOKE_CANNON_PWM = 5;
	static const int JAW_MOTOR_PWM = 6;
	static const int HEAD_MOTOR_PWM = 7;
	static const int LEFT_EYE_X_PWM = 8;
	static const int RIGHT_EYE_X_PWM = 9;
	
	//static const int LEFT_EYE_Y_PWM = 7;
	//static const int RIGHT_EYE_Y_PWM = 9;
	
	static const int SMOKE_MACHINE_RELAY = 1;
	
	static const int TOPHEAD_LIMIT_PIN = 4;
	static const int BOTTOMJAW_LIMIT_PIN = 2;
	static const int CRASH_LIMIT_PIN = 3;
	
	
	//Buttons for control 
	static const int FIRE_SMOKE_BUTTON = 2;
	static const float SMOKE_CANNON_SPEED = 0.4f;
	static const int MAKE_SMOKE_BUTTON = 4;
	static const int HEAD_UP_BUTTON = 6; //right bumper
	static const int JAW_UP_BUTTON = 5; //left bumper
	static const int EYE_LOCK_BUTTON = 1; 
	static const float LEFT_EYE_OFFSET = 0.0f; //TODO: figure this out
	float default_eye_position;
	float right_eye_val;
	float left_eye_val;
	static const float SPEED_LIMIT = 0.6f;
	
	//static const float JAWHEAD_MOTOR_SPEED = 0.2f;
	
	RobotDrive * drive;
	Gamepad * gamepad;
	Gamepad * gamepad2;
	DriverStationLCD * lcd;
	Victor * smoke_cannon;	
	DigitalOutput * smoke_machine;
	Servo * left_eye_x;
	//Servo * left_eye_y;
	Servo * right_eye_x;
	//Servo * right_eye_y;
	Victor * jaw_motor;
	Victor * head_motor;
	DigitalInput * tophead_limit;
	DigitalInput * bottomjaw_limit;
	DigitalInput * crash_limit;
	//bool makingSmoke;
	Timer * making_smoke_timer;
	Timer * firing_smoke_timer;
	static const int MAX_EXCESS_SMOKE_TIME = 2;
	
	
	bool can_move_head_up()
	{
		return tophead_limit->Get();
	}
	bool can_move_head_down(){
		return bottomjaw_limit->Get();
	}
	bool can_move_jaw_up(){
		return crash_limit->Get();
	}
	bool can_move_jaw_down(){
		return bottomjaw_limit->Get();
	}
	
public:
	DragonBotDriveTrain(void)	{
		drive = new RobotDrive(
			new Victor(FRONT_LEFT_PWM),
			new Victor(BACK_LEFT_PWM),
			new Victor(FRONT_RIGHT_PWM),
			new Victor(BACK_RIGHT_PWM)
		);
		drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		drive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		
		//makingSmoke = false;
		
		smoke_cannon = new Victor(SMOKE_CANNON_PWM);
		left_eye_x = new Servo(LEFT_EYE_X_PWM);
		//left_eye_y = new Servo(LEFT_EYE_Y_PWM);
		right_eye_x = new Servo(RIGHT_EYE_X_PWM);
		//right_eye_y = new Servo(RIGHT_EYE_Y_PWM);
		gamepad = new Gamepad(1);
		gamepad2 = new Gamepad(2);
		smoke_machine = new DigitalOutput(SMOKE_MACHINE_RELAY);
		lcd = DriverStationLCD::GetInstance();
		jaw_motor = new Victor(JAW_MOTOR_PWM);
		head_motor = new Victor(HEAD_MOTOR_PWM);
		tophead_limit = new DigitalInput(TOPHEAD_LIMIT_PIN);
		bottomjaw_limit = new DigitalInput(BOTTOMJAW_LIMIT_PIN);
		crash_limit = new DigitalInput(CRASH_LIMIT_PIN);
		
		default_eye_position = 15.0f; //TODO: figure this out
		
		making_smoke_timer = new Timer();
		firing_smoke_timer = new Timer();
		
		
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
		
		//small gamepad values are ignored
		if (x < 0.1f && x > -0.1f)
			{
				x = 0;
			}
		if (y < 0.1f && y > -0.1f)
			{
				y = 0;
			}
		
		if (rot < 0.1f && rot > -0.1f)
			{
				rot = 0;
			}
		
		drive->MecanumDrive_Cartesian(SPEED_LIMIT * x, SPEED_LIMIT * y, SPEED_LIMIT * rot);
		
		//shoot smoke if button is pressed
		if (gamepad2->GetNumberedButton(FIRE_SMOKE_BUTTON)){
			//SHOOT SMOKE!
			//makingSmoke = !makingSmoke;
			smoke_cannon->Set(SMOKE_CANNON_SPEED);
			lcd->PrintfLine(DriverStationLCD::kUser_Line5, "Shooting");
				
			firing_smoke_timer->Start(); //measure how long we've fired smoke, so we know if it's ok to make more
			
		}
		else
		{
			smoke_cannon->Set(0.0f);
			lcd->PrintfLine(DriverStationLCD::kUser_Line5, "Not shooting");
			firing_smoke_timer->Stop(); //stop the timer, since we're not firing smoke.
										//don't reset, cuz we need to how much smoke we've fired.

		}
		//Eye Code
		
//		float eye_pos = gamepad2->GetLeftX();
//		
//		right_eye_x->Set((eye_pos * 60) + default_eye_position);
//		left_eye_x->Set((eye_pos * 60) + default_eye_position - LEFT_EYE_OFFSET);
//		
//		//button lock code
//		if(gamepad2->GetNumberedButtonPressed(EYE_LOCK_BUTTON)){
//			default_eye_position = eye_pos;
//		}
//		
		
		
		//left eye control
		//If A isn't pressed the value should stay the same as before
		if (!gamepad2->GetNumberedButton(1)){
			float left_joystick_x = gamepad2->GetLeftX();
			float left_eye_x_axis = (1 - left_joystick_x)*60;
			left_eye_val = left_eye_x_axis + 50;
			
			float right_joystick_x = gamepad2->GetRawAxis(4);//right x axis
			float right_eye_x_axis = (1-right_joystick_x)*60;
			right_eye_val = right_eye_x_axis+20;
		}
		left_eye_x->SetAngle(left_eye_val);		
		right_eye_x->SetAngle(right_eye_val);
		
		//float right_joystick_y = gamepad2->GetRawAxis(4);
		//float right_eye_y_axis = (right_joystick_y+1)*60;
		//right_eye_y->SetAngle(right_eye_y_axis);

		/*
		bool rbutton = gamepad2->GetNumberedButton(HEAD_UP_BUTTON);
		bool lbutton = gamepad2->Ge tNumberedButton(HEAD_DOWN_BUTTON);
		if (rbutton){
			lcd->PrintfLine(DriverStationLCD::kUser_Line6, "rb pressed");
			jaw_motor->Set(0.2f);
		}else if(lbutton){
			lcd->PrintfLine(DriverStationLCD::kUser_Line6, "lb pressed");
			jaw_motor->Set(-0.15f);
		}else{
			lcd->PrintfLine(DriverStationLCD::kUser_Line6, "no buttons");
			jaw_motor->Set(0.0f);
		}
		*/

		//REAL head & jaw code
		//move head down
		if(gamepad2->GetRightX()<=-0.5f && can_move_head_down() && can_move_jaw_down()){
			head_motor->Set(-0.3f);
			jaw_motor->Set(0.3f);
		}
		//move head up
		else if(gamepad2->GetNumberedButton(HEAD_UP_BUTTON) && can_move_head_up()){
			head_motor->Set(0.3f);
			jaw_motor->Set(-0.3f);
		}
		//move jaw down
		else if(gamepad2->GetRightX()>=0.5f && can_move_jaw_down()){
			jaw_motor->Set(0.3f);
		}
		//move jaw up
		else if(gamepad2->GetNumberedButton(JAW_UP_BUTTON) && can_move_jaw_up()){
			jaw_motor->Set(-0.3f);
		}
		//sets to zero if no buttons pressed
		else {
			jaw_motor->Set(0.0f);
			head_motor->Set(0.0f);
		}
		
		
		lcd->PrintfLine(DriverStationLCD::kUser_Line6, "b:%d t:%d c:%d", bottomjaw_limit->Get(), tophead_limit->Get(), crash_limit->Get());
		
		

		//Smoke code
		if (gamepad2->GetNumberedButton(MAKE_SMOKE_BUTTON)){
			//MAKE SMOKE!!!!!!!!!!!
			//only if we don't have too much excess smoke
			if (making_smoke_timer->Get() - firing_smoke_timer->Get() < MAX_EXCESS_SMOKE_TIME){
				lcd->PrintfLine(DriverStationLCD::kUser_Line4, "smoke");
				smoke_machine->Set(true);
			} else {
				lcd->PrintfLine(DriverStationLCD::kUser_Line4, "too much smoke");
				smoke_machine->Set(false);
			}
			making_smoke_timer->Start(); //measure how long we've been making smoke, so we don't overflow the machine
										//doesn't do anything if we've already started the timer
		}
		else
		{
			lcd->PrintfLine(DriverStationLCD::kUser_Line4, "not smoke");
			smoke_machine->Set(false);
			making_smoke_timer->Stop(); 	//stop the timer, since we're not making smoke
											//don't reset it, cuz we need to know how much smoke we've made
		}
		
		//if both timers are the same, we can set them both to zero to ensure we don't overflow them or something
		if (making_smoke_timer->Get() == firing_smoke_timer->Get()){
			making_smoke_timer->Reset();
			firing_smoke_timer->Reset();
		}
		
		lcd->PrintfLine(DriverStationLCD::kUser_Line1, "x:%f", x);
		lcd->PrintfLine(DriverStationLCD::kUser_Line2, "y:%f", y);
		lcd->PrintfLine(DriverStationLCD::kUser_Line3, "r:%f", rot);
		
		
		lcd->UpdateLCD();

		
		
	}
			
};

START_ROBOT_CLASS(DragonBotDriveTrain);
