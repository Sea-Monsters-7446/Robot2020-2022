String Command_Names[10];

void (*Command_Funcs[10]) (String Input[SET_MaxArgs]);
// Create a function pointer array
// void - output type
// (*Command_Funcs[10]) - create array with size 10
// (String a0...) - input types

void DB_Cache() {
  // Basic stuff to let me know we good
  Command_Funcs[0] = 0; // Address 0 will reset
  Command_Names[0] = "reset";
  Command_Funcs[1] = CMD_echo;
  Command_Names[1] = "echo";
  Command_Funcs[2] = CMD_sleep;
  Command_Names[2] = "sleep";
  //
  // Pin stuff
  Command_Funcs[3] = PM_mode;
  Command_Names[3] = "pin_mode";
  Command_Funcs[4] = PM_read;
  Command_Names[4] = "pin_read";
  Command_Funcs[5] = PM_set;
  Command_Names[5] = "pin_set";
  //
  // Reading autoexec
  Command_Funcs[6] = AE_start;
  Command_Names[6] = "autoexec_start"; // I have to do this since it gets compiled alphabetically
  Command_Funcs[7] = AE_end;
  Command_Names[7] = "autoexec_end";
  Command_Funcs[8] = AE_write;
  Command_Names[8] = "autoexec_write";
  //

  Command_Funcs[9] = CMD_egg;
  Command_Names[9] = "popeyes_biscuit";
}
