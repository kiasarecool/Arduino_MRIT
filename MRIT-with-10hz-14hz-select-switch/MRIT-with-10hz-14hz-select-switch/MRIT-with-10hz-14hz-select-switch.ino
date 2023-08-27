#define IR_LED_PIN  D5  // Define the pin connected to the MOSFET
#define SWITCH_PIN  D6  // Define the pin connected to the switch
#define BUILTIN_LED_PIN D4
void setup() {
  pinMode(BUILTIN_LED_PIN, OUTPUT);  
  pinMode(IR_LED_PIN, OUTPUT); // Set the IR LED pin as output
  pinMode(SWITCH_PIN, INPUT_PULLUP); // Set the switch pin as input with pull-up resistor
}

void loop() {
  int switchState = digitalRead(SWITCH_PIN); // Read the state of the switch

  if (switchState == HIGH) { // If the switch is HIGH
    flashLED(35714); // Flash the LED at 14Hz (35,714 microseconds for both HIGH and LOW)
  } else { // If the switch is LOW
    flashLED(50000); // Flash the LED at 10Hz (50,000 microseconds for both HIGH and LOW)
  }
}

void flashLED(unsigned long duration) {
  digitalWrite(IR_LED_PIN, HIGH); // Turn on the IR LED (via the MOSFET)
  digitalWrite(BUILTIN_LED_PIN, HIGH);
  delayMicroseconds(duration); // Leave it on for the specified duration
  digitalWrite(IR_LED_PIN, LOW);  // Turn off the IR LED (via the MOSFET)
  digitalWrite(BUILTIN_LED_PIN, LOW);
  delayMicroseconds(duration); // Leave it off for the specified duration
}
