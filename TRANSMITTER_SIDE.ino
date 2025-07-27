#define LED_PIN 3
#define BITDELAY 3

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_PIN, HIGH);
}

void loop() {


  String inputString = Serial.readStringUntil('\n');

  if (inputString.length() > 0) {
    Serial.print("Transmitted Text: ");
    Serial.println(inputString);

    transmitString(inputString);
  }
}

void transmitString(const String &str) {
  for (int i = 0; i < str.length(); i++) {
    char currentChar = str.charAt(i);
    transmit_byte(currentChar); 
  }

}

void transmit_byte(char byte) {
  digitalWrite(LED_PIN, LOW);
  delay(BITDELAY);

  for (int i = 0; i < 8; i++) {
    digitalWrite(LED_PIN, (byte & (1 << i)) != 0  );
    delay(BITDELAY);
  }

  digitalWrite(LED_PIN, HIGH);
  delay(BITDELAY);
}

