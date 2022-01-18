int PM_ValidPin(String Pin) {
  if (Pin.charAt(0) == 'A') { // I could do Pin.startsWith("A"), but this saves memory
    Serial.println("Only digital pins supported.");
  }

  int AsInt = Pin.toInt();

  if (AsInt <= 0) {
    Serial.println("Invalid pin.");
    return -1;
  }

  return AsInt;
}

void PM_mode(String Input[SET_MaxArgs]) {
  int Pin = PM_ValidPin(Input[0]);

  if (Pin == -1) {
    return;
  }

  if (Input[1] == "in" || Input[1] == "input") {
    pinMode(Pin, INPUT);
    Serial.println("Pin mode set to input.");
  } else if (Input[1] == "out" || Input[1] == "output") {
    pinMode(Pin, OUTPUT);
    Serial.println("Pin mode set to output.");
  } else {
    Serial.println("Invalid mode.");
  }
}

void PM_read(String Input[SET_MaxArgs]) {
  int Pin = PM_ValidPin(Input[0]);

  if (Pin == -1) {
    return;
  }

  if (digitalRead(Pin)) {
    Serial.println("Pin is high.");
  } else {
    Serial.println("Pin is low.");
  }
}


void PM_set(String Input[SET_MaxArgs]) {
  int Pin = PM_ValidPin(Input[0]);

  if (Pin == -1) {
    return;
  }

  if (Input[1] == "high") {
    digitalWrite(Pin, HIGH);
    Serial.println("Pin set to high.");
  } else if (Input[1] == "low") {
    digitalWrite(Pin, LOW);
    Serial.println("Pin set to low.");
  } else {
    Serial.println("Invalid operation.");
  }
}

