void P_Parse(String Input) {
  String Name;
  String Args[SET_MaxArgs];
  
  int ArgCount = 0;
  
  for (int i = 0; i < Input.length(); i ++) {
    if (Input[i] == ' ') {
      ArgCount ++;
    } else if (Input[i] == ';') {
      ArgCount = SET_MaxArgs + 1;
    } else {
      if (ArgCount == 0) {
        Name.concat(Input[i]);
      } else if (ArgCount <= SET_MaxArgs) { // Do this becase we append up to len - 1, so it's within index
        Args[ArgCount - 1].concat(Input[i]);
      }
    }
  }

  for (int i = 0; i < sizeof Command_Names; i ++) {
    if (Name == Command_Names[i]) {
      (*Command_Funcs[i]) (Args);
      return; // Done with this command
    }
  }

  Serial.println("Command not found.");
}
