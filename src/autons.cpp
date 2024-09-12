#include <cstdio>
#include "autons.h"
#include "pros/motor_group.hpp"
#include "pros/rtos.hpp"

void left_auton(lemlib::Chassis& chassis, pros::v5::MotorGroup& intake, pros::adi::Pneumatics& pa, pros::adi::Pneumatics& pb) {
    // FILE *pfile;
    // pfile = fopen("file.txt", "a");
    chassis.setPose(0, 0, 180);
    // intake.move_voltage(12000);
    chassis.moveToPoint(0, 36,  4000, {.forwards = false, .maxSpeed=50});
    pa.extend();
    pb.extend();
    while (chassis.isInMotion()) {
        // fprintf(pfile, "%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        pros::delay(200);
    }
    
}