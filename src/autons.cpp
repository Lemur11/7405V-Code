#include "autons.h"
#include "pros/motor_group.hpp"
#include "pros/rtos.hpp"

void left_auton(lemlib::Chassis& chassis, pros::v5::MotorGroup& intake) {
    chassis.setPose(0, 0, 0);
    intake.move_voltage(12000);
    chassis.moveToPose(0, 50, 0, 4000, {.maxSpeed=100});
    while (chassis.isInMotion()) {
        printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        pros::delay(200);
    }
    
}