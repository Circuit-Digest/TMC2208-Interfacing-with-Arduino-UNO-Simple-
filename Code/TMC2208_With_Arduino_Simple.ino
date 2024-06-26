// This code controls a stepper motor using the TMC2208 stepper driver.
// Features:
// - Defines pins for enabling the driver, stepping, and setting direction.
// - Configures pin modes and initial states in the setup function.
// - In the loop function, alternates the stepping direction after a specified number of steps.
// - Utilizes delay to control the speed of the stepper motor.

// Pin Definitions
#define EN_PIN 8    // LOW: Driver enabled, HIGH: Driver disabled
#define STEP_PIN 9  // Step on the rising edge
#define DIR_PIN 10  // Set stepping direction

int noOfSteps = 250;           // Number of steps to move in each direction
int microSecondsDelay = 1000;  // Delay in microseconds between each step

void setup() {
  // Configure pin modes
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // Initialize pin states
  digitalWrite(DIR_PIN, LOW);  // Set initial direction
  digitalWrite(EN_PIN, LOW);   // Enable the driver
}

void loop() {
  // Move the motor in one direction
  digitalWrite(DIR_PIN, LOW);  // Set direction to LOW
  for (int i = 0; i < noOfSteps * 2; i++) {
    digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));  // Toggle the step pin
    delayMicroseconds(microSecondsDelay);            // Wait for the specified delay
  }

  // Move the motor in the opposite direction
  digitalWrite(DIR_PIN, HIGH);  // Set direction to HIGH
  for (int i = 0; i < noOfSteps * 2; i++) {
    digitalWrite(STEP_PIN, !digitalRead(STEP_PIN));  // Toggle the step pin
    delayMicroseconds(microSecondsDelay);            // Wait for the specified delay
  }
}
