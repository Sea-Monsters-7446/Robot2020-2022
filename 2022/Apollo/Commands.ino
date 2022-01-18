/*
// Leaving this template here for the future
void CMD_template(String Input[SET_MaxArgs]) {
  ;
}
*/

void CMD_echo(String Input[SET_MaxArgs]) {
  for (int i = 0; i < SET_MaxArgs; i ++) {
    Serial.print(Input[i]);
    if (i != SET_MaxArgs - 1) { // Not needed, just removes the extra space
      Serial.print(" ");
    }
  }
  
  Serial.println();
}

void CMD_sleep(String Input[SET_MaxArgs]) {
  int Time = 1000 * Input[0].toFloat();
  delay(Time);
}

void CMD_egg(String Input[SET_MaxArgs]) {
  Serial.println("Ooh Popeyes biscuit");
  delay(1000 * 2.5);
  Serial.println("AAAHHHH (with reverb)");
}

