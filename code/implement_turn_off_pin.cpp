//#define AD8232_SDN_PIN <pin>

void setup() {
// Set SDN pin as an output
pinMode(AD8232_SDN_PIN, OUTPUT);
}
void loop() {
// Turn off the AD8232
digitalWrite(AD8232_SDN_PIN, LOW);
delay(1000); // Wait for 1 second

// Turn on the AD8232
digitalWrite(AD8232_SDN_PIN, HIGH);
delay(1000); // Wait for 1 second
}
