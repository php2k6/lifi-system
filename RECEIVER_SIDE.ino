#define PHOTO_DIODE_PIN D5
#define BITDELAY 3

int previous_state = 1;
int current_state = 1;

void setup() {
  Serial.begin(115200);
}

void loop() {
  current_state = get_bit(); 
  if (!current_state && previous_state) {
    Serial.print(get_byte());
  }
  previous_state = current_state;
}

int get_bit() {
  int val = digitalRead(PHOTO_DIODE_PIN);
  return 1-val;
}

char get_byte() {
  char byte = 0;
  delay(BITDELAY * 1.5);
  for (int i = 0; i < 8; i++) {
    byte = byte | (get_bit() << i);
    delay(BITDELAY);
  }
  return byte;
}
