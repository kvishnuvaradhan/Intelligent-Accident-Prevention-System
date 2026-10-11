/*
  Intelligent Accident Prevention - educational obstacle-warning prototype
  Assumed hardware: Arduino Uno, HC-SR04, buzzer, built-in LED.
  This does not control vehicle brakes and is not a certified safety system.
*/
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int BUZZER_PIN = 6;
const int LED_PIN = 13;
const float WARNING_DISTANCE_CM = 30.0;

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
  if (duration == 0) return -1.0;
  return (duration * 0.0343f) / 2.0f;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  Serial.begin(9600);
  Serial.println("Obstacle-warning prototype ready");
}

void loop() {
  float distance = readDistanceCm();
  if (distance < 0) {
    Serial.println("No echo received; check sensor wiring/target.");
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  } else {
    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");
    if (distance <= WARNING_DISTANCE_CM) {
      digitalWrite(LED_PIN, HIGH);
      tone(BUZZER_PIN, 2000);
      Serial.println("WARNING: obstacle nearby!");
    } else {
      digitalWrite(LED_PIN, LOW);
      noTone(BUZZER_PIN);
    }
  }
  delay(150);
}
