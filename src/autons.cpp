#include <cstdio>
#include "autons.h"
#include "lemlib/asset.hpp"
#include "pros/motor_group.hpp"
#include "pros/rtos.hpp"

ASSET(mogo_rush_txt);

void left_auton(lemlib::Chassis& chassis, pros::v5::MotorGroup& intake, pros::adi::Pneumatics& mogo, pros::adi::Pneumatics& hammer) {
    // FILE *pfile;
    // pfile = fopen("file.txt", "a");
    chassis.setPose(-59, -60, 270);
    chassis.follow(mogo_rush_txt, 15, 4000, false);
    while (chassis.isInMotion()) {
        // fprintf(pfile, "%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        pros::delay(200);
    }
    // while (!pa.is_extended()) {
        // printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        // if ((-3 < chassis.getPose().x) & (chassis.getPose().x < 3) & (chassis.getPose().y < 33) & (chassis.getPose().y > 27)) {
    mogo.extend();
    //     }
    // }
    // intake.move_voltage(12000);
    // chassis.moveToPose(24, 9, 90,  4000, {.forwards = true, .minSpeed=50});

}