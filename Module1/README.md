// Define pin numbers
const int MOTION_SENSOR_PIN = 2; // Motion sensor connected to digital pin 2
const int LED_PIN = 13;         // LED connected to digital pin 13

// Variables to store the state of the motion sensor
int motionState = 0;

void setup() {
  // Initialize the motion sensor pin as an input
  pinMode(MOTION_SENSOR_PIN, INPUT);
  
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the state of the motion sensor
  motionState = digitalRead(MOTION_SENSOR_PIN);
  
  // If motion is detected, turn on the LED
  if (motionState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Motion detected!");
  } 
  // If no motion is detected, turn off the LED
  else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("No motion.");
  }
  
  // Add a small delay to prevent excessive serial output
  delay(100);
}
