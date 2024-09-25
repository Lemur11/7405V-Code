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
    intake.move_velocity(200);
    pros::delay(1750);

    intake.move_velocity(-500);
    chassis.moveToPose(-6.1, 30.6, 0, 4000);
    pros::delay(2000);
    intake.move_velocity(0);
    chassis.turnToHeading(305, 800);
    printf("Done");
    chassis.moveToPoint(12, 18, 2000, {.forwards = false, .maxSpeed=50, .minSpeed = 5});
    pros::delay(3000);
    mogo.extend();
    intake.move_velocity(-600);


    // chassis.turnToHeading(1, 4000);
    // chassis.moveToPoint(8.13, 40.5, 4000);
    
    // // 6 42 5
    // while (chassis.isInMotion()) {
    //     printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
    //     pros::delay(200);
    // }

    //3, 47, -13
    // chassis.turnToHeading(-35, 500);
    // chassis.moveToPoint(4, 45, 4000);

    // chassis.moveToPoint(5.6, 30.7, 4000, {.forwards = false});
    // chassis.turnToHeading(-10, 400);
    // chassis.moveToPoint(2, 45, 4000);



    


    
    // while (!mogo.is_extended()) {
    //     printf("%f, %f, %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
    //     if ((-3 < chassis.getPose().x) & (chassis.getPos e().x < 3) & (chassis.getPose().y < 40) & (chassis.getPose().y > 34)) {
    //         mogo.extend();        
    //     }
    // }


}
void carry_auton(lemlib::Chassis& chassis, pros::v5::MotorGroup& intake, pros::adi::Pneumatics& mogo, pros::adi::Pneumatics& hammer) {
    chassis.setPose(0, 0, 0);
    pros::delay(4000);   
    chassis.moveToPoint(0, -11, 4000, {.forwards = false, .maxSpeed = 30});
    // intake.move_velocity(100);
    while (chassis.isInMotion()) {
        pros::delay(200);
    }
    intake.move_velocity(200);
    pros::delay(1750);
    intake.move_velocity(0);
    chassis.moveToPose(-6.1, 30.6, 0, 4000);
    pros::delay(1400);
    intake.move_velocity(-500);
    pros::delay(800);
    intake.move_velocity(0);
    chassis.turnToHeading(305, 800);
    printf("Done");
    chassis.moveToPoint(12, 18, 2000, {.forwards = false, .maxSpeed=75, .minSpeed = 5});
    pros::delay(3000);
    mogo.extend();
    pros::delay(500);
    intake.move_velocity(-600);
    pros::delay(2000);
    chassis.turnToHeading(-240, 4000);
    mogo.retract();
    intake.move_velocity(0);
    chassis.moveToPoint(23, 14, 1000);

    

    
}

void right_auton(lemlib::Chassis& chassis, pros::v5::MotorGroup& intake, pros::adi::Pneumatics& mogo, pros::adi::Pneumatics& hammer) {
    chassis.setPose(0, 0, 0);
    pros::delay(4000);
    chassis.moveToPoint(0, -11, 4000, {.forwards = false, .maxSpeed = 30});
    // intake.move_velocity(100);
    while (chassis.isInMotion()) {
        pros::delay(200);
    }
    intake.move_velocity(300);
    pros::delay(1500);

    // -4.7, 21.559, 96.0
    // 3.24, 32.029, 38.54

    intake.move_velocity(500);
    chassis.turnToHeading(38, 400);
    chassis.moveToPoint(16.5, 18.4,4000 , {.maxSpeed = 70}) ;
        while (chassis.isInMotion()) {
        pros::delay(200);
    }
    pros::delay(300);
    intake.move_velocity(0);

    chassis.turnToHeading(90, 400);
    // -7, 19
    chassis.moveToPoint(-10, 19, 1000, {.forwards = false, .maxSpeed = 50});
    pros::delay(2500);
    intake.move_velocity(-500);

    mogo.extend();
    pros::delay(500);

    chassis.turnToHeading(50, 400);
    chassis.moveToPoint(3.24, 32, 1000, {.maxSpeed = 75});
    pros::delay(1500);
    intake.move_velocity(-500);
    pros::delay(2000);
    mogo.retract();
    pros::delay(500);
    intake.move_velocity(0);
    chassis.moveToPoint(4, 39, 4000);

}