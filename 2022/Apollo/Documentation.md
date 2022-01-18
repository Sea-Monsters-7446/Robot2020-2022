# Basic commands
## reset
Resets the device

## echo [Input]
Prints the arguments back

**(Prints up to as many arguments as allowed)**

## sleep [Time:float]
Waits for that amount of time

# Pin control
## pin_mode [PinNumber:int] ["input " | "output "]
Configures the mode of the pin

**(NOTE: Pins’ mode should be set before using/reading them)**

## pin_read [PinNumber:int]
Reads the current status of the pin

## pin_set [PinNumber:int] ["high " | "low "]
Sets the current output of the pin

# AutoExec control
## autoexec_start
Runs the contents of the AutoExec

**(NOTE: If writing to the AutoExec, this will be needed as the _first_ command to run the AutoExec on startup)**

## autoexec_write
Allows you to write commands to the AutoExec

**(NOTE: Be sure to give yourself room to add "autoexec_write" to properly end the AutoExec, failing to do so will result in garbage data being ran)**

## autoexec_end
Marks the end of the AutoExec
