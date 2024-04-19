#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors

//Set up left drive group
motor rearLeft = motor(PORT2, ratio18_1, false);
motor frontLeft = motor(PORT11, ratio18_1, false);
motor_group leftDrive = motor_group(rearLeft, frontLeft);

//set up right drive group
motor rearRight = motor(PORT9, ratio18_1, true);
motor frontRight = motor(PORT20, ratio18_1, true);
motor_group rightDrive = motor_group(rearRight, frontRight);

//Intertial setup
inertial funnyGyro = inertial(PORT19);

//Constructor for drivetrain
smartdrive drivetrain = smartdrive(leftDrive, rightDrive, funnyGyro, 319.19, 320, 40, mm, 1);

//Assign controller 
controller master = controller(primary);

//Set up Arm
motor leftArm = motor(PORT1, ratio18_1, false);
motor rightArm = motor(PORT10, ratio18_1, true);
motor_group arm = motor_group(leftArm, rightArm);

//Assign Claw motor
motor claw = motor(PORT12, ratio18_1, false);

//Additional sensor setup
distance theRuler = distance(PORT17);
optical theEye = optical(PORT16);

// VEXcode generated functions
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  funnyGyro.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (funnyGyro.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}