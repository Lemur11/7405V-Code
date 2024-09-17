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
    chassis.moveToPose(-5.79, 36, 0, 4000);
    while (chassis.isInMotion()) {
        pros::delay(20);
    }
    intake.move_velocity(0);
    chassis.turnToHeading(305, 800);
    printf("Done");
    chassis.moveToPoint(6.59, 28.78, 2000, {.forwards = false});
    while (chassis.isInMotion()) {
        pros::delay(20);
        }
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
    // while (!mogo.is_extended()) {
    //     printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
    //     if ((-3 < chassis.getPose().x) & (chassis.getPose().x < 3) & (chassis.getPose().y < 40) & (chassis.getPose().y > 34)) {
    //         mogo.extend();        
    //     }
    // }


}