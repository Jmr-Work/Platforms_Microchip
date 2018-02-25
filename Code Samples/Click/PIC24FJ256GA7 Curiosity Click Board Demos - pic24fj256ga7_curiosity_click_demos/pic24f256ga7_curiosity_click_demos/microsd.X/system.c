/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#include "system_config.h"
#include "system.h"
#include <xc.h>
#include <stdbool.h>
#include "sd_spi.h"

/** CONFIGURATION Bits **********************************************/
// FSEC
#pragma config BWRP = OFF    // Boot Segment Write-Protect bit->Boot Segment may be written
#pragma config BSS = DISABLED    // Boot Segment Code-Protect Level bits->No Protection (other than BWRP)
#pragma config BSEN = OFF    // Boot Segment Control bit->No Boot Segment
#pragma config GWRP = OFF    // General Segment Write-Protect bit->General Segment may be written
#pragma config GSS = DISABLED    // General Segment Code-Protect Level bits->No Protection (other than GWRP)
#pragma config CWRP = OFF    // Configuration Segment Write-Protect bit->Configuration Segment may be written
#pragma config CSS = DISABLED    // Configuration Segment Code-Protect Level bits->No Protection (other than CWRP)
#pragma config AIVTDIS = OFF    // Alternate Interrupt Vector Table bit->Disabled AIVT

// FOSCSEL
#pragma config FNOSC = FRCPLL    // Oscillator Source Selection->Fast RC Oscillator with divide-by-N with PLL module (FRCPLL) 
#pragma config PLLMODE = PLL96DIV2    // PLL Mode Selection->96 MHz PLL. Oscillator input is divided by 2 (8 MHz input)
#pragma config IESO = ON    // Two-speed Oscillator Start-up Enable bit->Start up device with FRC, then switch to user-selected oscillator source

// FOSC
#pragma config POSCMD = NONE    // Primary Oscillator Mode Select bits->Primary Oscillator disabled
#pragma config OSCIOFCN = OFF    // OSC2 Pin Function bit->OSC2 is clock output
#pragma config SOSCSEL = ON    // SOSC Power Selection Configuration bits->SOSC is used in crystal (SOSCI/SOSCO) mode
#pragma config PLLSS = PLL_FRC    // PLL Secondary Selection Configuration bit->PLL is fed by the on-chip Fast RC (FRC) oscillator
#pragma config IOL1WAY = ON    // Peripheral pin select configuration bit->Allow only one reconfiguration
#pragma config FCKSM = CSDCMD    // Clock Switching Mode bits->Both Clock switching and Fail-safe Clock Monitor are disabled

// FWDT
#pragma config WDTPS = PS32768    // Watchdog Timer Postscaler bits->1:32768
#pragma config FWPSA = PR128    // Watchdog Timer Prescaler bit->1:128
#pragma config FWDTEN = OFF    // Watchdog Timer Enable bits->WDT and SWDTEN disabled
#pragma config WINDIS = OFF    // Watchdog Timer Window Enable bit->Watchdog Timer in Non-Window mode
#pragma config WDTWIN = WIN25    // Watchdog Timer Window Select bits->WDT Window is 25% of WDT period
#pragma config WDTCMX = WDTCLK    // WDT MUX Source Select bits->WDT clock source is determined by the WDTCLK Configuration bits
#pragma config WDTCLK = LPRC    // WDT Clock Source Select bits->WDT uses LPRC

// FPOR
#pragma config BOREN = ON    // Brown Out Enable bit->Brown Out Enable Bit
#pragma config LPCFG = OFF    // Low power regulator control->No Retention Sleep
#pragma config DNVPEN = ENABLE    // Downside Voltage Protection Enable bit->Downside protection enabled using ZPBOR when BOR is inactive

// FICD
#pragma config ICS = PGD2    // ICD Communication Channel Select bits->Communicate on PGEC2 and PGED2
#pragma config JTAGEN = OFF    // JTAG Enable bit->JTAG is disabled

// FDEVOPT1
#pragma config ALTCMPI = DISABLE    // Alternate Comparator Input Enable bit->C1INC, C2INC, and C3INC are on their standard pin locations
#pragma config TMPRPIN = OFF    // Tamper Pin Enable bit->TMPRN pin function is disabled
#pragma config SOSCHP = ON    // SOSC High Power Enable bit (valid only when SOSCSEL = 1->Enable SOSC high power mode (default)
#pragma config ALTI2C1 = ALTI2CEN    // Alternate I2C pin Location->SDA1 and SCL1 on RB9 and RB8


void SYSTEM_Initialize (void)
{
    // CF no clock failure; NOSC FRCPLL; SOSCEN disabled; POSCEN disabled; CLKLOCK unlocked; OSWEN Switch is Complete; IOLOCK not-active; 
    __builtin_write_OSCCONL((uint8_t) (0x0100 & 0x00FF));
    // CPDIV 1:1; PLLEN enabled; DOZE 1:8; RCDIV FRC; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x3020;
    // STOR disabled; STORPOL Interrupt when STOR is 1; STSIDL disabled; STLPOL Interrupt when STLOCK is 1; STLOCK disabled; STSRC SOSC; STEN disabled; TUN Center frequency; 
    OSCTUN = 0x0000;
    // ROEN disabled; ROSEL FOSC; ROSIDL disabled; ROSWEN disabled; ROOUT disabled; ROSLP disabled; 
    REFOCONL = 0x0000;
    // RODIV 0; 
    REFOCONH = 0x0000;
    // ROTRIM 0; 
    REFOTRIML = 0x0000;
    // DCOTUN 0; 
    DCOTUN = 0x0000;
    // DCOFSEL 8; DCOEN disabled; 
    DCOCON = 0x0700;
    // DIV 0; 
    OSCDIV = 0x0000;
    // TRIM 0; 
    OSCFDIV = 0x0000;
    // WDTO disabled; TRAPR disabled; SLEEP disabled; BOR disabled; DPSLP disabled; CM disabled; SWR disabled; SWDTEN disabled; EXTR disabled; POR disabled; SBOREN disabled; IDLE disabled; IOPUWR disabled; VREGS disabled; 
    RCON = 0x0000;
}


void MIKROBUS_A_SdSpiConfigurePins (void)
{
    _RP15R = 0x0008;    //SCK1OUT -> RB15
    _RP14R = 0x0007;    //SDO -> RP14
    _SDI1R = 13;        //SDI <- RP13
    
    //Settings for microSD click board using mikroBUS Interface A
    //CS = RC9 
    //CD = RB10
    LATCbits.LATC9 = 0;
    TRISCbits.TRISC9 = 0;
    TRISCbits.TRISC1 = 1;
    
    ANSCbits.ANSC1 = 0;
    ANSBbits.ANSB13 = 0;
    ANSBbits.ANSB14 = 0;
    ANSBbits.ANSB15 = 0;
}

inline void MIKROBUS_A_SdSpiSetCs(uint8_t a)
{
    LATCbits.LATC9 = a;     //mikroBUS click on interface A
}

inline bool MIKROBUS_A_SdSpiGetCd(void)
{
    return (!PORTCbits.RC1) ? true : false;

}

inline bool MIKROBUS_A_SdSpiGetWp(void)
{
    return false;
}

// The sdCardMediaParameters structure defines user-implemented functions needed by the SD-SPI fileio driver.
// The driver will call these when necessary.  For the SD-SPI driver, the user must provide
// parameters/functions to define which SPI module to use, Set/Clear the chip select pin,
// get the status of the card detect and write protect pins, and configure the CS, CD, and WP
// pins as inputs/outputs (as appropriate).
// For this demo, these functions are implemented in system.c, since the functionality will change
// depending on which demo board/microcontroller you're using.
// This structure must be maintained as long as the user wishes to access the specified drive.
FILEIO_SD_DRIVE_CONFIG mikroBusA =
{
    1,                                  // Use SPI module 1
    MIKROBUS_A_SdSpiSetCs,                    // User-specified function to set/clear the Chip Select pin.
    MIKROBUS_A_SdSpiGetCd,                    // User-specified function to get the status of the Card Detect pin.
    MIKROBUS_A_SdSpiGetWp,                    // User-specified function to get the status of the Write Protect pin.
    MIKROBUS_A_SdSpiConfigurePins             // User-specified function to configure the pins' TRIS bits.
};
