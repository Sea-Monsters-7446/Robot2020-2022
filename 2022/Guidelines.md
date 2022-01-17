# Critical info:
## Control the robot with a roboRIO
ROBOTS must be controlled via 1 programmable NI roboRIO
or roboRIO 2.0 (P/N **am3000** or **am3000a**, both versions referred to throughout this manual as
“roboRIO”), with image version **2022_v3.0** or later

## Communicate with the ROBOT with the specified radio
OpenMesh wireless bridge (P/N:
**OM5P-AN** or **OM5P-AC**), that has been configured with the appropriate encryption key
for your team number at each event, is the only permitted device for communicating to and
from the ROBOT during the MATCH

## Use specific Ethernet port for roboRIO
roboRIO Ethernet port must be connected to the wireless bridge port labeled
“**18-24 vPOE**” either directly, via a network switch, via an RPM, or via a CAT5 Ethernet
pigtail

## Only use allowed ports and bandwidth to communicate with the ROBOT
Communication between the ROBOT and the OPERATOR CONSOLE may not exceed 4 Mbits/second
and is restricted to network ports listed in Table 9-5.

## Configure devices for your team number
## Don't bypass the arena network
## No other wireless devices allowed to communicate with the ROBOT
## Wireless bridge must be visible
## ROBOTS must have a signal light 
## Pneumatic (important!) 98-102
Only use _explicitly_ permitted pneumatic parts

No custom pneumatics and meet minimum pressure ratings

Don’t modify pneumatics

Only use specific pneumatic devices

Compressed air from ROBOT compressor _only_

Air storage pressure limit _no greater than **120 psi (~827kPa)**_

No stored air pressure intended for the ROBOT may be located off-board the ROBOT 

### Working air pressure limit
Working air pressure (air pressure used to actuate devices) on the
ROBOT must be _no greater than **60 psi (~413 kPa)**_ and must be provided through a single primary
adjustable, relieving, pressure regulator 

## Limited devices at high pressure

# Important Info
## Wires
Use specified colored wires

_Red, yellow, white, brown, or black-with-stripe_ on the **positive** (e.g. +24VDC, +12VDC,
+5VDC, etc.) connections

_Black_ or _blue_ for the common or negative side (-) of the connections

**(Wire exceptions below)**

Wires that are originally attached to legal devices and any extensions to these wires using
the same color as the manufacturer

Ethernet cable used in POE cables   

## Battery (1):
Lead acid

12V max

Min 17 Ah
Max 18.2 Ah

### Shape
Rectangle 

### Dimensions
7.1 in. x 3 in. x 6.6 in., +/- .1 in. for each dimension (~ 180 mm x
76mm x 168 mm, +/- 2.5 mm for each dimension)

### Weight
11lbs to 14.5 (~5 kg to 6.5 kg)

### Terminals
Nut and bolt style

## Fans
No greater than 120mm (nominal) size and rated electrical input power no greater than 10 watts
(W) continuous duty at 12 volts (VDC)

## Motors
Electrical solenoid actuators, no greater than 1 in. (nominal) stroke and rated electrical input power no
greater than 10 watts (W) continuous duty at 12 volts (VDC) 

Hard drive motors part of a legal COTS computing device

Factory installed vibration and autofocus motors resident in COTS computing devices (e.g. rumble
motor in a smartphone).

PWM COTS servos with a retail cost < $75. 
Motors integral to a COTS sensor (e.g. LIDAR, scanning sonar, etc.), provided the device is not modified
except to facilitate mounting

1 compressor compliant with R806 and used to compress air for the ROBOT’S pneumatic system


## Motors (modification exceptions)
The mounting brackets and/or output shaft/interface may be modified to facilitate the physical
connection of the motor to the ROBOT and actuated part.

The electrical leads may be trimmed to length as necessary and connectors or splices to additional
wiring may be added.

The locking pins on the window motors (P/N **262100-3030** and **262100-3040**) may be removed. 
The connector housings on KOP automotive motors listed in Table 9-1 may be modified to
facilitate lead connections.

ROBOT Construction Rules V2 85 of 136

Servos may be modified as specified by the manufacturer (e.g. re-programming or
modification for continuous rotation).

The wiring harness of the Nidec Dynamo BLDC Motor may be modified as documented by
FIRST in Nidec Dynamo BLDC Motor with Controller.

Minimal labeling may be applied to indicate device purpose, connectivity, functional
performance, etc.

Any number of #10-32 plug screws may be removed from the Falcon 500.

Insulation may be applied to electrical terminals.

## Ports
Don’t connect motor outputs to roboRIO

Control PWM controllers from the roboRIO

Only approved MXP devices can control actuators (more info attached)

Control CAN motor controllers from the roboRIO.

Control PCM/PH(S) and Servo Hubs from roboRIO

Connect the PDP/PDH to the roboRIO CAN bus

Don’t alter the CAN bus

USB to CAN adapter permitted
