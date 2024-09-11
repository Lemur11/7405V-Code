#include "main.h"
#include "lemlib/api.hpp"
#include "autonSelector.h"
#include "autons.h"
#include <cstddef>
#include <cstdio>



pros::Controller master(pros::E_CONTROLLER_MASTER);
/*
left_mg(-, +, -) - 20, 12, 11
right_mg(+, -, +) - 10, 19, 18
*/
pros::MotorGroup left_mg({-20, 12, -11}, pros::MotorGearset::blue);
pros::MotorGroup right_mg({10, -19, 18}, pros::MotorGearset::blue);
// intake (-1, 2)
pros::MotorGroup intake({-1, 2}, pros::MotorGearset::blue);
lemlib::Drivetrain drivetrain(&left_mg,
                              &right_mg,
                              10, // track width
                              lemlib::Omniwheel::NEW_4, // using new 4" omnis
                              360, // drivetrain rpm
                              2 // horizontal drift
);
// piston a, b
pros::adi::Pneumatics piston_a('a', false);  
pros::adi::Pneumatics piston_b('b', false);
// imu 4
pros::Imu imu(9);
// TODO determine where rotation sensor is reversed or not
// pros::Rotation rotation_sensor(1);
// lemlib::TrackingWheel horizontal_tracking_wheel(&rotation_sensor, lemlib::Omniwheel::NEW_275, -5.75);


lemlib::OdomSensors sensors(nullptr, 
                            nullptr, 
                            nullptr, 
                            nullptr, 
                            &imu 
);

lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID 
                        angular_controller, // angular PID 
                        sensors, // odometry sensors
                        &throttleCurve,
                        &steerCurve

);


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	autonSelector.initialize();
    chassis.calibrate();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    left_mg.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_mg.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	int curAuton = autonSelector.getState();
    printf("%d", curAuton);
	if (curAuton == autonSelector.LEFT) {
        left_auton(chassis, intake);
	} else if (curAuton == autonSelector.RIGHT) {
		//
	} else if (curAuton == autonSelector.CARRY) {
		//
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    left_mg.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    right_mg.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    int intake_on = 0;
    int TIMER_L = 20;
    int b1_timer = TIMER_L;
    int b3_timer = TIMER_L;
    int vel = 12000;
	while (true) {
        // print to screen
        // lv_obj_t * label1 = lv_label_create(lv_scr_act());
        // lv_label_set_text_fmt(label1, "X: %f, Y: %f, Angle: %f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        // lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);
        // button logic
        b1_timer += 1;
        b3_timer += 1;
        if (master.get_digital(DIGITAL_R1) & (b1_timer > TIMER_L)) {
            if (intake_on == 0) {
                intake.move_voltage(vel);
                intake_on = 1;   
            } else if (intake_on == 1) {
                intake.move_voltage(0);
                intake_on = 0;
            }
            b1_timer = 0;
        } if (master.get_digital(DIGITAL_L1)) {
            piston_a.extend();
            piston_b.extend();
        } if (master.get_digital(DIGITAL_L2)) {
            piston_a.retract();
            piston_b.retract();
        } if (master.get_digital(DIGITAL_R2) & (b3_timer > TIMER_L)) {
            vel *= -1;
            intake.move_voltage(vel);
            b3_timer = 0;
        } 
        // drive logic
		int dir = master.get_analog(ANALOG_LEFT_Y);    
		int turn = master.get_analog(ANALOG_RIGHT_X);
        chassis.arcade(dir, turn);
		pros::delay(20);                               // Run for 20 ms then update
	}
}