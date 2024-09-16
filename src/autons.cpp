#include <cstdio>
#include "autons.h"
#include "lemlib/asset.hpp"
#include "pros/motor_group.hpp"
#include "pros/rtos.hpp"

ASSET(mogo1_txt);

void left_auton(lemlib::Chassis& chassis, pros::v5::MotorGroup& intake, pros::adi::Pneumatics& mogo, pros::adi::Pneumatics& hammer) {
    // FILE *pfile;
    // pfile = fopen("file.txt", "a");
    chassis.setPose(0, 0, 180);
    // chassis.follow(mogo1_txt, 15, 4000, false);
    chassis.moveToPoint(0, 40, 4000, {.forwards = false, .maxSpeed = 70});
    // while (chassis.isInMotion()) {
    //     // fprintf(pfile, "%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
    //     printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
    //     pros::delay(200);
    // }
    while (!mogo.is_extended()) {
        printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        if ((-3 < chassis.getPose().x) & (chassis.getPose().x < 3) & (chassis.getPose().y < 40) & (chassis.getPose().y > 34)) {
            mogo.extend();        
        }
    }
    intake.move_velocity(-12000);
    chassis.moveToPoint(0, 22, 4000);
    chassis.moveToPoint(0, 33, 4000, {.forwards = false});
    mogo.retract();
    chassis.moveToPoint(0, 20, 4000);
    // intake.move_voltage(12000);
    // chassis.moveToPose(24, 9, 90,  4000, {.forwards = true, .minSpeed=50});

}