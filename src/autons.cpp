#include <cstdio>
#include "autons.h"
#include "lemlib/asset.hpp"
#include "pros/motor_group.hpp"
#include "pros/rtos.hpp"

ASSET(mogo1_txt);


void left_auton(lemlib::Chassis& chassis, pros::v5::MotorGroup& intake, pros::adi::Pneumatics& mogo, pros::adi::Pneumatics& hammer) {
    chassis.setPose(0, 0, 0);
    
    chassis.moveToPoint(0, -11, 4000, {.forwards = false, .maxSpeed = 30});
    // intake.move_velocity(100);
    while (chassis.isInMotion()) {
        pros::delay(200);
    }
    intake.move_velocity(500);
    pros::delay(1750);

    intake.move_velocity(-500);
    chassis.moveToPose(-6, 36, 0, 4000);
    pros::delay(1000);
    intake.move_velocity(0);
    chassis.turnToHeading(305, 800);
    printf("Done");
    chassis.moveToPoint(10, 20, 2000, {.forwards = false, .maxSpeed=70, .minSpeed = 5, .earlyExitRange = 10});
    pros::delay(620);
    mogo.extend();
    intake.move_velocity(-600);


    chassis.turnToHeading(1, 4000);
    chassis.moveToPoint(8.13, 40.5, 4000);
    
    // 6 42 5
    while (chassis.isInMotion()) {
        printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        pros::delay(200);
    }

    //3, 47, -13
    chassis.turnToHeading(-35, 500);
    chassis.moveToPoint(4, 45, 4000);

    


    
    // while (!mogo.is_extended()) {
    //     printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
    //     if ((-3 < chassis.getPose().x) & (chassis.getPose().x < 3) & (chassis.getPose().y < 40) & (chassis.getPose().y > 34)) {
    //         mogo.extend();        
    //     }
    // }


}
void carry_auton(lemlib::Chassis& chassis, pros::v5::MotorGroup& intake, pros::adi::Pneumatics& mogo, pros::adi::Pneumatics& hammer) {
    chassis.setPose(0, 0, 180);
    chassis.moveToPoint(0, 30, 2000, {.forwards = false, .maxSpeed = 50});
    chassis.turnToHeading(150, 400);
    chassis.moveToPoint(-9.5, 41.5, 4000, {.forwards = false, .maxSpeed = 50});
    pros::delay(800);
    mogo.extend();
    
}

void right_auton(lemlib::Chassis& chassis, pros::v5::MotorGroup& intake, pros::adi::Pneumatics& mogo, pros::adi::Pneumatics& hammer) {
    chassis.setPose(0, 0, 0);
    
    chassis.moveToPoint(0, -11, 4000, {.forwards = false, .maxSpeed = 30});
    // intake.move_velocity(100);
    while (chassis.isInMotion()) {
        pros::delay(200);
    }
    intake.move_velocity(300);
    pros::delay(1500);

    intake.move_velocity(-500);
    chassis.turnToHeading(38, 400);
    chassis.moveToPoint(16.5, 18.4,4000 ) ;
        while (chassis.isInMotion()) {
        pros::delay(200);
    }
    pros::delay(300);
    intake.move_velocity(0);

    chassis.turnToHeading(90, 400);
    chassis.moveToPoint(-7.18, 21.99, 1000, {.forwards = false, .maxSpeed = 75});
    pros::delay(500);
    intake.move_velocity(-500);
    pros::delay(200);
    mogo.extend();

    chassis.turnToHeading(50, 400);
    chassis.moveToPoint(3.6, 33, 1000, {.maxSpeed = 75});
    pros::delay(1500);
    // intake.move_velocity(0);

    //A: 50
    // 3.6 33
}