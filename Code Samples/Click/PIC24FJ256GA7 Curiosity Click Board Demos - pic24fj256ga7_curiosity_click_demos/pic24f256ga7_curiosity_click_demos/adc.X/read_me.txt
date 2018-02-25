================================================================
ADC Click Demo
================================================================

Overview
----------------------------------------------------------------
This demo shows how to use the ADC click board.  MPLAB(R) Code 
Configurator(MCC) is used to configure the processor, pins, and 
peripherals.


Hardware Configuration
----------------------------------------------------------------
1) Plug the ADC Click into the appropriate mikroBUS(tm).
2) Refer to the hardware.txt file attached to the project for 
   more information about any board/processor specific 
   limitations or configuration required.

This demo uses the following mikroBUS pins:
* CS
* SCK
* MISO
* MOSI

For more information about the bus mapping for this specific
processor, please refer to the hardware.txt file packaged with 
this example.


Running the Demo
----------------------------------------------------------------
This demo automatically samples all four channels and prints
their value on the LCD display of the Explorer 16/32 board.  The
printed number is the in the range of [0, 4095].

For example:

+----------------+
|0:  100  1: 2400|
|2: 1642  3:    1|
+----------------+

Connect an analog source to the CN0, CN1, CN2, and/or CN3 inputs
of the ADC click board as well as the GND connection and the
conversion results of that port are automatically updated on the
screen.  

The analog sources should be between 0v-3.3v.

EXPLORER 16/32 Only: You can use the potentiometer on the 
Explorer 16/32 as an analog source if you like by connecting 
one of the ADC click board analog channels to the P20_POT 
net on the Explorer 16/32.

References/Links
----------------------------------------------------------------
[1] http://www.mikroe.com/click/adc/
[2] http://www.microchip.com/mplab/mplab-code-configurator

Legal
----------------------------------------------------------------
mikroBUS(tm) a trademark of MikroElectronika.
MPLAB(R) is a registered trademark of Microchip Technology Inc.
