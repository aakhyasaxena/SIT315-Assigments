// Define pin numbers
const int MOTION_SENSOR_PIN = 2; // Motion sensor connected to digital pin 2
const int LED_PIN = 13;         // LED connected to digital pin 13

// Variable to store the state of the LED
volatile bool ledState = false;

// Interrupt service routine (ISR) for handling motion detection
void motionDetected() {
  // Toggle the LED state
  ledState = !ledState;
  
  // Print message to serial monitor
  if (ledState) {
    Serial.println("Motion detected!");
  } else {
    Serial.println("No motion.");
  }
}

void setup() {
  // Initialize the motion sensor pin as an input
  pinMode(MOTION_SENSOR_PIN, INPUT);
  
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Start serial communication for debugging
  Serial.begin(9600);
  
  // Attach the interrupt to the motion sensor pin
  // The ISR will be triggered on a change (both HIGH and LOW)
  attachInterrupt(digitalPinToInterrupt(MOTION_SENSOR_PIN), motionDetected, CHANGE);
}

void loop() {
  // Set the LED state based on the variable controlled by the ISR
  digitalWrite(LED_PIN, ledState);
  
  // Add a small delay to prevent excessive serial output
  delay(100);
}
