/**
 * CUSTOMIZED VERSION for easier pin identification
 * 
 * Assigning most pins from configuration.h:
 * Pin assignments are split between configuration.h and the MCU's pin__.h files. 
 * I wanted to bve able to change many of the pin assignments fron configuration.h only.
 * So I changed the hard coded pin assigments in pins.h to relative pins called my____PIN.  
 * Then I moved the direct pin assignments to configuration.h.
 * Example for my new 4th extruder STEP pin: 
 * pins.h definition:          #define E3_STEP_PIN  myE3_STEP_PIN
 * Configuration.h definition: #define myE3_STEP_PIN   EXT_1_4_PIN
 * 
 * Understandable names:
 * Next I gave hard coded pin assignemnts in pins.h like PF7 (SKR_PRO) more understandable names.
 * Pins can be multiply defined, essentially having several names for the same pin.
 * Here many of the pins are defined to be identified more easily by location or function.
 * Example by location: EXT_1_3_PIN	makes more sense than PF8 to locate the pin on Extensio-1 pin 3.
 * Example by function: EMAX_X_PIN for PE15 to define extruder X maximum endstop.
 * Redefines for I2C, UART, BLT, etc. are included.
 * 
 * Analog pins are defined: 
 * Pins that can be digital out and ADC (analog in) are adressed differently for each. 
 * Example: A21 defines the analog input function forExtension-1 pin 3
 *          PF8 defines the digital out function
 * Example of my notation:
 *          EXT_1_3_A21_PIN defines Extension-1 pin 3 for analog input
 *          EXT_1_3_PIN defines digital out for Extension-1 pin 3
 * 
 * RAMPS Servo pins are identified and pins tested:
 * Example: SERVO0_PIN on BLT_2_PIN
 * 
 * 4th extruder is defined and pins tested:
 * This includes a 4th temp sensor, heater, cooling stack fan, and step/dir/enable pins.
 * Example: E3_STEP_PIN, FAN3_PIN, HEATER_3_PIN
 * NOTE: the code in pins.h that errors out ona 4th extruder is commented out.
 * 
 * UART control pins for TMC steppers - both internal assigned, and additional pins
 * Example: URT_1_PIN PC13 //X 
 */

/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#ifndef TARGET_STM32F4
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#endif
//ppd Disable >3 hotends/steppers moved to new v1_1 and v1_2 headers 
												 

// Use one of these or SDCard-based Emulation will be used
#if NO_EEPROM_SELECTED
  //#define SRAM_EEPROM_EMULATION                 // Use BackSRAM-based EEPROM emulation
  #define FLASH_EEPROM_EMULATION                  // Use Flash-based EEPROM emulation
#endif

#if ENABLED(FLASH_EEPROM_EMULATION)
  // Decrease delays and flash wear by spreading writes across the
  // 128 kB sector allocated for EEPROM emulation.
  #define FLASH_EEPROM_LEVELING
#endif

/**     //ppd
Better names for possible available pins to identify by location on the board. 
Some may be used by added features such as WIFI, BLTounch sensor, etc.
*/
//EXTENSION-1
#define EXT_1_3_PIN	    PF8     //PWM & ADC
#define EXT_1_4_PIN	    PC9
#define EXT_1_5_PIN	    PF10    //ADC
#define EXT_1_6_PIN	    PF9     //PWM & ADC
#define EXT_1_7_PIN	    PC5 
#define EXT_1_8_PIN	    PC4
#define EXT_1_9_PIN	    PG13
#define EXT_1_10_PIN	PG11
#define EXT_1_11_PIN	PD3
#define EXT_1_12_PIN	PG14
#define EXT_1_13_PIN	PF7     //PWM & ADC
#define EXT_1_14_PIN	PC1

//EXTENSION-2
#define EXT_2_3_PIN	PE4
#define EXT_2_4_PIN	PD0
#define EXT_2_5_PIN	PE2
#define EXT_2_6_PIN	PD2
#define EXT_2_7_PIN	PE0
#define EXT_2_8_PIN	PD5

//BLTouch
#define BLT_2_PIN   PA1 //PWM
#define BLT_4_PIN   PA2 //PWM

//UART(LOWER RIGHT)
#define  URTZ_1_PIN	PD9
#define  URTZ_2_PIN	PD8

//I2C
#define I2C_1_PIN   PB7
#define I2C_2_PIN   PB6

//UART (DRIVERS)

//These are assigned to Software serial for UART control of steppers
//x_SERIAL_TX_PIN and RX 
#define URT_1_PIN	PC13 //X    these are all internal pins to the SKR PRO
#define URT_3_PIN	PE3  //Y
#define URT_5_PIN	PE1	//Z
#define URT_7_PIN	PD4	//E0
#define URT_9_PIN	PD1	//E1
#define URT_11_PIN	PD6	//E2

//THESE WERE ASSIGNED in Marlin 1.9.1 but not used in Marling 2.0
//May be avaiable for additional steppers 
#define URT_4_PIN	PE2 //EXTENSION-2 EXT_2_5_PIN
#define URT_6_PIN	PE0 //EXTENSION-2 EXT_2_7_PIN
#define URT_10_PIN	PD0 //EXTENSION-2 EXT_2_4_PIN
#define URT_12_PIN	PD5 //EXTENSION-2 EXT_2_8_PIN


/**
WIFI - only 2 pins
*/
#define WIFI_1_PIN  PC6
#define WIFI_8_PIN  PC7

/**
ADC pins (anlog to digital) such as thermistors
*/
#define EXT_1_3_A21_PIN   A21    //Extension-1 pin 3
#define EXT_1_6_A22_PIN   A22     //Extension-1 pin 6
#define EXT_1_5_A23_PIN   A23    //Extension-1 pin 5
#define EXT_1_13_A20_PIN  A20  //Extension-1 pin 13
#define BLT_2_A1_PIN  A1  //BLTouch Pin 2
#define BLT_4_A2_PIN  A2  //BLTouch Pin 4
//
// Servos
//
/**
RAMPS "SERVO" pins can do PWM (pulsed width modulation).
This enables variable speed fans among other things.
These defines include all the possible PWM pins on the SKR PRO. 
Available pins will depend on what features you have enabled, like WIFI, BLTounch sensor, etc.
*/

#define SERVO0_PIN BLT_2_PIN     //BLTouch pin 2
#define SERVO1_PIN BLT_4_PIN     //BLTouch pin 4
#define SERVO2_PIN EXT_1_13_PIN    //Extension-1 pin 13
#define SERVO3_PIN EXT_1_3_PIN     //Extension-1 pin 3
#define SERVO4_PIN EXT_1_6_PIN     //Extension-1 pin 6
#define SERVO5_PIN WIFI_1_PIN      //WIFI
#define SERVO6_PIN WIFI_8_PIN      //WIFI
//
// Trinamic Stallguard pins
//
#define X_DIAG_PIN                          PB10  // X-
#define Y_DIAG_PIN                          PE12  // Y-
#define Z_DIAG_PIN                          PG8   // Z-
#define E0_DIAG_PIN                         PE15  // E0
#define E1_DIAG_PIN                         PE10  // E1
#define E2_DIAG_PIN                         PG5   // E2

//
// Limit Switches
//
#ifdef X_STALL_SENSITIVITY
  #define X_STOP_PIN                  X_DIAG_PIN
  #if X_HOME_DIR < 0
    #define X_MAX_PIN                       PE15  // E0
  #else
    #define X_MIN_PIN                       PE15  // E0
  #endif
#else
  #define X_MIN_PIN                         PB10  // X-
  #define X_MAX_PIN                         PE15  // E0
#endif

#ifdef Y_STALL_SENSITIVITY
  #define Y_STOP_PIN                  Y_DIAG_PIN
  #if Y_HOME_DIR < 0
    #define Y_MAX_PIN                       PE10  // E1
  #else
    #define Y_MIN_PIN                       PE10  // E1
  #endif
#else
  #define Y_MIN_PIN                         PE12  // Y-
  #define Y_MAX_PIN                         PE10  // E1
#endif

#ifdef Z_STALL_SENSITIVITY
  #define Z_STOP_PIN                  Z_DIAG_PIN
  #if Z_HOME_DIR < 0
    #define Z_MAX_PIN                       PG5   // E2
  #else
    #define Z_MIN_PIN                       PG5   // E2
  #endif
#else
  #define Z_MIN_PIN                         PG8   // Z-
  #define Z_MAX_PIN                         PG5   // E2
#endif

//
// Z Probe must be this pin
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                   PA2
#endif

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PE15
#endif
#ifndef FIL_RUNOUT2_PIN
  #define FIL_RUNOUT2_PIN                   PE10
#endif
#ifndef FIL_RUNOUT3_PIN
  #define FIL_RUNOUT3_PIN                   PG5
#endif

//
// Steppers
//
#define X_STEP_PIN                          PE9
#define X_DIR_PIN                           PF1
#define X_ENABLE_PIN                        PF2
#ifndef X_CS_PIN
  #define X_CS_PIN                          PA15
#endif

#define Y_STEP_PIN                          PE11
#define Y_DIR_PIN                           PE8
#define Y_ENABLE_PIN                        PD7
 #ifndef Y_CS_PIN
  #define Y_CS_PIN                          PB8
#endif

#define Z_STEP_PIN                          PE13
#define Z_DIR_PIN                           PC2
#define Z_ENABLE_PIN                        PC0
#ifndef Z_CS_PIN
  #define Z_CS_PIN                          PB9
#endif

#define E0_STEP_PIN                         PE14
#define E0_DIR_PIN                          PA0
#define E0_ENABLE_PIN                       PC3
#ifndef E0_CS_PIN
  #define E0_CS_PIN                         PB3
#endif

#define E1_STEP_PIN                         PD15
#define E1_DIR_PIN                          PE7
#define E1_ENABLE_PIN                       PA3
#ifndef E1_CS_PIN
  #define E1_CS_PIN                         PG15
#endif

#define E2_STEP_PIN                         PD13
#define E2_DIR_PIN                          PG9
#define E2_ENABLE_PIN                       PF0
#ifndef E2_CS_PIN
  #define E2_CS_PIN                         PG12
#endif

/*This is for a 4th stepper motor
extension boards for multiple steppers typically have only 1 enable pin for
all the steppers. OR the enable pin can be grounded to permant on.
Using the enable pin is optional. 
CS pin is not used on stepper motor extension boards. 
CS (Chip Select) is used for SPI stepper chip selection.
So external stepper chips lke TMC2130 cannot use the SPI feature.
*/

#define E3_STEP_PIN     myE3_STEP_PIN
#define E3_DIR_PIN      myE3_DIR_PIN
#define E3_ENABLE_PIN   myE3_ENABLE_PIN   //EXTENSION-1, USae one enable for extension board's multiple steppers

#define E4_STEP_PIN     myE4_STEP_PIN
#define E4_DIR_PIN      myE4_DIR_PIN
#define E4_ENABLE_PIN   myE4_ENABLE_PIN

#define E5_STEP_PIN     myE5_STEP_PIN
#define E5_DIR_PIN      myE5_DIR_PIN
#define E5_ENABLE_PIN   myE5_ENABLE_PIN

//
// Temperature Sensors
//
#define TEMP_0_PIN         PF4  // T1 <-> E0
#define TEMP_1_PIN         PF5  // T2 <-> E1
#define TEMP_2_PIN         PF6  // T3 <-> E2
#if EXTRUDERS  > 3
  #define TEMP_3_PIN         myTEMP_SENSOR_3_PIN
#endif
#if EXTRUDERS  > 4
  #define TEMP_4_PIN         myTEMP_SENSOR_4_PIN
#endif
#define TEMP_BED_PIN       PF3  // T0 <-> Bed

//
// Heaters / Fans
//
#define HEATER_0_PIN       PB1  // Heater0
#define HEATER_1_PIN       PD14 // Heater1
#define HEATER_2_PIN       PB0  // Heater2
#define HEATER_3_PIN    myHEATER_3_PIN  //MUST use external MOSFET board to drive these heaters
#define HEATER_4_PIN    myHEATER_4_PIN
#define HEATER_5_PIN    myHEATER_5_PIN

#define HEATER_BED_PIN     PD12 // Hotbed
#define FAN_PIN            PC8  // Fan0
#define FAN1_PIN           PE5  // Fan1
#define FAN2_PIN           PE6  // Fan2
#define FAN3_PIN        myE3_AUTO_FAN_PIN   
#define FAN4_PIN        myE4_AUTO_FAN_PIN   
#define FAN5_PIN        myE5_AUTO_FAN_PIN   
#define FAN6_PIN        myE6_AUTO_FAN_PIN	

#ifndef E0_AUTO_FAN_PIN
  #define E0_AUTO_FAN_PIN               FAN1_PIN
#endif
//
// Software SPI pins for TMC2130 stepper drivers
//
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI                     PC12
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO                     PC11
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK                      PC10
  #endif
#endif

#if HAS_TMC_UART
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //
  #define X_SERIAL_TX_PIN                   PC13
  #define X_SERIAL_RX_PIN                   PC13

  #define Y_SERIAL_TX_PIN                   PE3
  #define Y_SERIAL_RX_PIN                   PE3

  #define Z_SERIAL_TX_PIN                   PE1
  #define Z_SERIAL_RX_PIN                   PE1

  #define E0_SERIAL_TX_PIN                  PD4
  #define E0_SERIAL_RX_PIN                  PD4

  #define E1_SERIAL_TX_PIN                  PD1
  #define E1_SERIAL_RX_PIN                  PD1

  #define E2_SERIAL_TX_PIN                  PD6
  #define E2_SERIAL_RX_PIN                  PD6

  #define E3_SERIAL_TX_PIN                  EXT_2_5_PIN //URT_4_PIN = PE2 //ppd_UART
  #define E3_SERIAL_RX_PIN                  EXT_2_5_PIN

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE                    19200
#endif


//
// Misc. Functions
//

#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION                  LCD
#endif

//
// Onboard SD card
// Must use soft SPI because Marlin's default hardware SPI is tied to LCD's EXP2
//
#if SD_CONNECTION_IS(LCD)
  #define SD_DETECT_PIN                     PF12
  #define SDSS                              PB12
#elif SD_CONNECTION_IS(ONBOARD)
  // The SKR Pro's ONBOARD SD interface is on SPI1.
  // Due to a pull resistor on the clock line, it needs to use SPI Data Mode 3 to
  // function with Hardware SPI. This is not currently configurable in the HAL,
  // so force Software SPI to work around this issue.
  #define SOFTWARE_SPI
  #define SDSS                              PA4
  #define SCK_PIN                           PA5
  #define MISO_PIN                          PA6
  #define MOSI_PIN                          PB5
  #define SD_DETECT_PIN                     PB11
#elif SD_CONNECTION_IS(CUSTOM_CABLE)
  #define "CUSTOM_CABLE is not a supported SDCARD_CONNECTION for this board"
#endif

/**
 *               _____                                             _____
 *           NC | · · | GND                                    5V | · · | GND
 *        RESET | · · | PF12(SD_DETECT)             (LCD_D7)  PG7 | · · | PG6  (LCD_D6)
 *   (MOSI)PB15 | · · | PF11(BTN_EN2)               (LCD_D5)  PG3 | · · | PG2  (LCD_D4)
 *  (SD_SS)PB12 | · · | PG10(BTN_EN1)               (LCD_RS) PD10 | · · | PD11 (LCD_EN)
 *    (SCK)PB13 | · · | PB14(MISO)                 (BTN_ENC)  PA8 | · · | PG4  (BEEPER)
 *               ￣￣                                               ￣￣
 *               EXP2                                              EXP1
 */

//
// LCDs and Controllers
//
#if HAS_SPI_LCD
  #define BEEPER_PIN                        PG4
  #define BTN_ENC                           PA8

  #if ENABLED(CR10_STOCKDISPLAY)
    #define LCD_PINS_RS                     PG6

    #define BTN_EN1                         PD11
    #define BTN_EN2                         PG2

    #define LCD_PINS_ENABLE                 PG7
    #define LCD_PINS_D4                     PG3

    // CR10_STOCKDISPLAY default timing is too fast
    #undef BOARD_ST7920_DELAY_1
    #undef BOARD_ST7920_DELAY_2
    #undef BOARD_ST7920_DELAY_3

  #elif ENABLED(MKS_MINI_12864)
    #define DOGLCD_A0                       PG6
    #define DOGLCD_CS                       PG3
    #define BTN_EN1                         PG10
    #define BTN_EN2                         PF11
  #else

    #define LCD_PINS_RS                     PD10

    #define BTN_EN1                         PG10
    #define BTN_EN2                         PF11

    #define LCD_PINS_ENABLE                 PD11
    #define LCD_PINS_D4                     PG2

    #if ENABLED(FYSETC_MINI_12864)
      #define DOGLCD_CS                     PD11
      #define DOGLCD_A0                     PD10
      //#define LCD_BACKLIGHT_PIN           -1
      #define LCD_RESET_PIN                 PG2   // Must be high or open for LCD to operate normally.
      #if EITHER(FYSETC_MINI_12864_1_2, FYSETC_MINI_12864_2_0)
        #ifndef RGB_LED_R_PIN
          #define RGB_LED_R_PIN             PG3
        #endif
        #ifndef RGB_LED_G_PIN
          #define RGB_LED_G_PIN             PG6
        #endif
        #ifndef RGB_LED_B_PIN
          #define RGB_LED_B_PIN             PG7
        #endif
      #elif ENABLED(FYSETC_MINI_12864_2_1)
        #define NEOPIXEL_PIN                PG3
      #endif
    #endif // !FYSETC_MINI_12864

    #if ENABLED(ULTIPANEL)
      #define LCD_PINS_D5                   PG3
      #define LCD_PINS_D6                   PG6
      #define LCD_PINS_D7                   PG7
    #endif

  #endif

  // Alter timing for graphical display
  #if HAS_GRAPHICAL_LCD
    #ifndef BOARD_ST7920_DELAY_1
      #define BOARD_ST7920_DELAY_1  DELAY_NS(96)
    #endif
    #ifndef BOARD_ST7920_DELAY_2
      #define BOARD_ST7920_DELAY_2  DELAY_NS(48)
    #endif
    #ifndef BOARD_ST7920_DELAY_3
      #define BOARD_ST7920_DELAY_3 DELAY_NS(600)
    #endif
  #endif

#endif // HAS_SPI_LCD

//
// WIFI
//

/**
 *          _____
 *      TX | 1 2 | GND      Enable PG1   // Must be high for module to run
 *  Enable | 3 4 | GPIO2    Reset  PG0   // active low, probably OK to leave floating
 *   Reset | 5 6 | GPIO0    GPIO2  PF15  // must be high (ESP3D software configures this with a pullup so OK to leave as floating)
 *     3.3V| 7 8 | RX       GPIO0  PF14  // Leave as unused (ESP3D software configures this with a pullup so OK to leave as floating)
 *           ￣￣
 *            W1
 */
#define ESP_WIFI_MODULE_COM                    6  // Must also set either SERIAL_PORT or SERIAL_PORT_2 to this
#define ESP_WIFI_MODULE_BAUDRATE        BAUDRATE  // Must use same BAUDRATE as SERIAL_PORT & SERIAL_PORT_2
#define ESP_WIFI_MODULE_RESET_PIN           PG0
#define ESP_WIFI_MODULE_ENABLE_PIN          PG1
#define ESP_WIFI_MODULE_GPIO0_PIN           PF14
#define ESP_WIFI_MODULE_GPIO2_PIN           PF15
