#include <cstdio>
#include "autons.h"
#include "lemlib/asset.hpp"
#include "pros/motor_group.hpp"
#include "pros/rtos.hpp"

ASSET(mogo1_txt);


void left_auton(lemlib::Chassis& chassis, pros::v5::MotorGroup& intake, pros::adi::Pneumatics& mogo, pros::adi::Pneumatics& hammer) {
    // FILE *pfile;
    // pfile = fopen("file.txt", "a");
    chassis.setPose(0, 0, 0);
    // chassis.follow(mogo1_txt, 15, 4000, false);
    chassis.moveToPoint(0, -10, 4000, {.forwards = false, .maxSpeed = 50});
    // chassis.moveToPose(0, -10, -45, 4000, {.forwards = false, .maxSpeed = 30});
    while (chassis.isInMotion()) {
    //     // fprintf(pfile, "%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        // printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        pros::delay(200);
    }
    intake.move_velocity(200);
    pros::delay(2000);
    intake.move_velocity(-500);
    chassis.moveToPose(-3, 31, 0, 4000);
    pros::delay(2000);
    intake.move_velocity(0);
    chassis.turnToHeading(305, 800);
    printf("Done");
    chassis.moveToPoint(5.39, 27.11, 2000, {.forwards = false, .maxSpeed=70, .minSpeed = 5, .earlyExitRange = 10});
    pros::delay(520);
    mogo.extend();
    intake.move_velocity(-600);
    chassis.turnToHeading(1, 4000);
    chassis.moveToPoint(8.13, 40.5, 4000);
    while (chassis.isInMotion()) {
    //     // fprintf(pfile, "%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        pros::delay(200);
    }
    chassis.turnToHeading(-35, 500);
    chassis.moveToPose(1.64, 51.2, 40.7, 4000);
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
    chassis.moveToPoint(0, -11, 4000, {.forwards = false, .maxSpeed = 50});
    intake.move_velocity(1);
    while (chassis.isInMotion()) {
        pros::delay(200);
    }
    intake.move_velocity(200);
    pros::delay(1500);
    intake.move_velocity(-500);
    chassis.turnToHeading(32, 400);
    chassis.moveToPoint(16.5, 18.4,4000 ) ;
        while (chassis.isInMotion()) {
        pros::delay(200);
    }
    pros::delay(300);
    intake.move_velocity(0);
    chassis.turnToHeading(90, 400);
    chassis.moveToPoint(-3.9, 22.9, 1000, {.forwards = false});
    pros::delay(700);
    mogo.extend();
}