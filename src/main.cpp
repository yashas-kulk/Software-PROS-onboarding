#include "main.h"


void initialize() {
    pros::lcd::initialize();
    pros::lcd::set_text(1, "Hello PROS User!");
}

void disabled() {}


void competition_initialize() {}


void autonomous() {}
//1,2
//15,17
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_mtr({1, 8});
pros::MotorGroup right_mtr({15, 17});

void display_task() {
    pros::Task task([]{ // this is a lambda -> https://en.cppreference.com/w/cpp/language/lambda
        while(true) {
            // display motor position
            pros::lcd::print(1, "Left Motor Pos: %lf" , left_mtr.get_position(), 3);
            pros::lcd::print(3, "Right Motor Pos: %lf", right_mtr.get_position(), 5);
            // display motor velocity
            pros::lcd::print(5, "Left Motor Velo: %lf", left_mtr.get_actual_velocity(), 7);
            pros::lcd::print(7, "Right Motor Velo: %lf", right_mtr.get_actual_velocity(), 9);
            pros::delay(100); // delay for context switching

            //hello?? im so confusedefwf2w

        }
    });
}

void opcontrol() {
    // spawn display task
    display_task();
    // opcontrol while loop
    while(true) {
        // motor control code
            left_mtr.move(-controller.get_analog(ANALOG_LEFT_Y));
            right_mtr.move(controller.get_analog(ANALOG_RIGHT_Y));
        //tryna get the motors to move in opposite directions
    
        pros::delay(10);// delay for context switching
    }
}