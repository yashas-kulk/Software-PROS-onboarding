#include "main.h"


void initialize() {
    pros::lcd::initialize();
    pros::lcd::set_text(1, "Hello PROS User!");
}

void disabled() {}


void competition_initialize() {}


void autonomous() {}


pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_mtr({});
pros::MotorGroup right_mtr({});

void display_task() {
    pros::Task task([]{ // this is a lambda -> https://en.cppreference.com/w/cpp/language/lambda
        while(true) {
            // display motor position

            // display motor velocity
            pros::delay(100);// delay for context switching
        }
    });
}

void opcontrol() {
    // spawn display task

    // opcontrol while loop
    while(true) {
        // motor control code


        pros::delay(10);// delay for context switching
    }
}