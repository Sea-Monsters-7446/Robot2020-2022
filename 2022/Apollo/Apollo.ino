#define SET_Baud 9600
#define SET_MaxArgs 5
#define SET_MaxEEPROM 512
#define SET_PrintAutoExec false

String EmptyInput[SET_MaxArgs];

void setup() {
  Serial.begin(SET_Baud);

  while (!Serial) {
    ;
  }

  Serial.println("Apollo connected to Capcom!");
  Serial.println("Building cache...");
  DB_Cache();
  Serial.println("Done.");
  if (AE_check()) {
    Serial.println("Automatically running AutoExec...");
    AE_start(EmptyInput);
  }
  Serial.println("Ready for commands.");
}

void loop() {
  String UserInput;
  UserInput = Serial.readString();
  
  if (UserInput != "") {
    P_Parse(UserInput);
  }
}

