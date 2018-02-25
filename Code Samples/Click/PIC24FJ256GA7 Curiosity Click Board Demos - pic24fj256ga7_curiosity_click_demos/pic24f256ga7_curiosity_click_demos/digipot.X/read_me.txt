================================================================
DigiPot Click Demo
================================================================

Overview
----------------------------------------------------------------
This demo shows how to use the DigiPot click board.  MPLAB(R) 
Code Configurator(MCC) is used to configure the processor, pins, 
and peripherals.


Hardware Configuration
----------------------------------------------------------------
1) Plug the DigiPot Click into the appropriate mikroBUS(tm).
2) Refer to the hardware.txt file attached to the project for 
   more information about any processor specific limitations or
   configuration required.

This demo uses the following mikroBUS pins:
* CS
* SCK
* MOSI

For more information about the bus mapping for this specific
processor, please refer to the hardware.txt file packaged with 
this example.


Running the Demo
----------------------------------------------------------------
This demo adjusts the digipot output based on the user
interactions with the push buttons.  There are buttons to:
* Increment the wiper
* Decrement the wiper
* Reset the wiper to the center

Some of these features may be missing based on the number of
buttons available on the target board/processor.

The code is written so that when the button is pressed, the
action above is performed once but will not trigger again until
the button is released and pressed again.  

To see the change in the digipot output, connect a multimeter
to the wiper and one of the ends of the digipot.  Set the
meter to measure in the 20k range.  Once connected, press the
buttons to change the potentiometer value and note the change
in the resistance and the meter.

NOTE: the code in this example does not debounce the button 
presses so you may occasionally see multiple actions per press.
Adding deboucing functionality in software would add complexity
to the demo and detract from the intended purpose, to show
the interaction with the DigiPot click board.

Explorer 16/32 only:
Due to connections on some processor modules, not all three
button functions may be available.  Check the hardware.txt file 
for hardware configuration and limitations for the specific
processor module you are using.  Also check button_mapping.h
to see which buttons are mapped to each of the demo features.
If BUTTON_NONE is defined for any of the features, then that
feature is not available on the processor module selected for
this demo, likely due to a hardware conflict.


References/Links
----------------------------------------------------------------
[1] http://www.mikroe.com/click/digipot/
[2] http://www.microchip.com/mplab/mplab-code-configurator

Legal
----------------------------------------------------------------
mikroBUS(tm) a trademark of MikroElectronika.
MPLAB(R) is a registered trademark of Microchip Technology Inc.