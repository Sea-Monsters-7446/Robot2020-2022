#include <EEPROM.h>

String AE_Str_Start = "autoexec_start";
String AE_Str_End = "autoexec_end";

bool AE_check() {
  bool Match = true;

  for (int i = 0; i < AE_Str_Start.length(); i ++) {
    if (AE_Str_Start[i] != EEPROM.read(i)) { // 
      Match = false;
    }
  }

  return Match;
}

void AE_start(String Input[SET_MaxArgs]) {
  String PassCMD;

  for (int i = 0; i < SET_MaxEEPROM; i ++) {
    char Current = EEPROM.read(i);
    if (Current != ';') {
      PassCMD.concat(Current);
    } else {
      if (SET_PrintAutoExec) {
        Serial.println(PassCMD);
      }

      if (PassCMD != AE_Str_Start) {
        P_Parse(PassCMD);
      }

      if (PassCMD == AE_Str_End) {
        break;
      }

      PassCMD = "";
    }
  }
}

void AE_end(String Input[SET_MaxArgs]) {
  Serial.println("Finished AutoExec.");
}

void AE_write(String Input[SET_MaxArgs]) {
  Serial.println("Now writing to AutoExec, type your commands.");
  Serial.print("(Type '");
  Serial.print(AE_Str_End);
  Serial.println("' when done.)");

  String UserInput;
  int EEPROM_Count = 0;

  while (EEPROM_Count < SET_MaxEEPROM) {
    UserInput = Serial.readString();
    if (UserInput != "") {
      UserInput.concat(";");

      for (int i = 0; i < UserInput.length() && EEPROM_Count < SET_MaxEEPROM; i ++) {
        EEPROM.update(EEPROM_Count, UserInput[i]); // EEPROM_Count should have the current position
        EEPROM_Count ++; // We do character at a time
      }

      Serial.print(UserInput);
      Serial.print(" (Remaining bytes for AutoExec: ");
      Serial.print(SET_MaxEEPROM - EEPROM_Count);
      Serial.println(")");

      if (UserInput == AE_Str_End + ";") {
        break;
      }
    }
  }

  Serial.println("Wrote to AutoExec.");
}

