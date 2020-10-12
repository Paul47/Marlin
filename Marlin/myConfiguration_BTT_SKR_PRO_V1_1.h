

#pragma once

/**
* myConfiguration_BTT_SKR_PRO_V1.1.h  5/27/2020 ppd
*this header contains all the RE_ARM specific code for pin assignments
*All other //ppd modificationbs are common to both motherboards.
*The motherboard sdefinition in config.h @line 145 selects the myConfiguration_xxx.h file
*
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
 * Example by location: EXT_1_3_PIN	makes more sense than PF8 to locate the pin on Extension-1 pin 3.
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


//*********************custom pins for SKR PRO start ***************                                                                    
 /**
 * My stepper (Extruder) pin definitions
 * ex: E2_STEP_PIN, E2_DIR_PIN, or E2_ENABLE_PIN 
* cannot use ALL RE-ARM AUX2 pins for motor expander-pins some are NC
* try thiese pins on AUX1 and AUX2 
* If not enough pins,  disable the enable_pin here (-1) and ground the enable pn on the motor extender
 */
//------------code for extruder motors 4 - 6 ----------------
// 1st 3 extruder motors are set by default
#define NO_EXT_PIN 999              //NOTE: unused pins cannot be set to -1 as with some parameters.
// 3rd extruder Motor - n/a for SKR PRO
//#define myE2_STEP_PIN   RAMPS_D20_PIN    //define 3rd extr motor
//#define myE2_DIR_PIN    RAMPS_D21_PIN            
//#define myE2_ENABLE_PIN NO_EXT_PIN  //RAMPS_D59_PIN optional. If 4 motors, disable this and ground the enable pn on the motor extender
//4th extruder Motor
#define myE3_STEP_PIN   EXT_1_4_PIN
#define myE3_DIR_PIN    EXT_1_7_PIN
#define myE3_ENABLE_PIN EXT_1_8_PIN 

/**  
 For multiple extruders define the heater pins
 HEATER_0_PIN is internally defined for all boards, but assign here to override defaults
 HEATER_1_PIN is internally defined only for EEB & EEF but assign here to override defaults
 myHEATER pins can be defined as their own pins or can be assigned NO_HEATER_PIN to hardware wire 
 "piggyback" heaters in parallel to the same pin. (be sure to use a MOSFET driver board) 
 This may be the only option if there are not enough free pins
*/
#define NO_HEATER_PIN   999             //NOTE: unused pins cannot be set to -1 as with some parameters.
//#define myHEATER_0_PIN      // 1.  Enable & Aassign to override defaults. 2. leave commented out for default assigns
//#define myHEATER_1_PIN     // 1. Enabel & Aassign for EFB & EFF as a 2nd heater. 2. Enable & Aassign to override EEF and EEB 2nd heater. 3. leave commented out  for default EEF and EEB
//#define myHEATER_2_PIN NO_HEATER_PIN                  //n/a for SKR PRO              
#define myHEATER_3_PIN EXT_1_9_PIN
#define myHEATER_4_PIN EXT_1_10_PIN                      

//
// Hotend Temperature sensor pin assignments
//
/**
 NOTE: See mySENSOR_TYPE selction below in config.h
 to set hotend temp sensor types for each hotend
*/
                                                                                                

/**
Analog INPUT pins are designated as A# and run sequentially from 0 to 7 These pins
Can also be didigtal pins D##
*ASSIGNING ANALOG PINS EXCLUDES USE AS DIGITAL PINS 
**Note that the 2nd sensor can be labelled REDUNDANT in config.h
    to protect from heater runaway for multiple heating blocks.
This code changes assign analog pins only if needed by HOTENDS to make sure there is no conflict

*******Number of HOTENDS (nozzles) may be less than number of extruders  (motors)
      so the pins here only need assigned for physical hotends.*******

Each hotend/extrude must have a valid temp sensor and pin associated with it.
A Sensor pin cannot be -1, 0, or 99. It must be valid analog physical input pin.
To assign the minimum pins (and avoid using others like A4, A5, and A6) you can 
double up pin assigments like T0. 

ADC pins (anlog to digital) such as thermistors

define EXT_1_3_A21_PIN   A21    //Extension-1 pin 3. ADC and PWM
#define EXT_1_6_A22_PIN   A22     //Extension-1 pin 6. ADC and PWM
#define EXT_1_5_A23_PIN   A23    //Extension-1 pin 5, ADC but not PWM
#define EXT_1_13_A20_PIN  A20  //Extension-1 pin 13. ADC and PWM
#
TEMP_0_PIN, TEMP_1_PIN and TEMP_2_PIN are defined by default
*/
#define NO_TEMP_SENSOR TEMP_0_PIN  //cannot be -1, 0, or 99. must be physical pin
                                                
//#define myTEMP_SENSOR_BED_PIN     T1      //bed, 1 and 2 n/a for SKR PRO
//#define myTEMP_SENSOR_1_PIN   NO_TEMP_SENSOR	//numbers match EXTRUDERS starting w/ zero
//#define myTEMP_SENSOR_2_PIN   NO_TEMP_SENSOR                                               
#define myTEMP_SENSOR_3_PIN   EXT_1_5_A23_PIN   //**MUST BE ADC enabled pin

//FAN_PIN (Parts fan) is defined as FAN0.  default: PC8 
//Extruder cooling fans (actually HOTENDS not EXTRUDERS)
//See Diamond, Cyclops, and Chimera 
/**
 * Extruder auto fans automatically turn on when their extruders'
 * temperatures go above EXTRUDER_AUTO_FAN_TEMPERATURE.
 * Your board's pins file specifies the recommended pins. Override those here
 * or set to -1 to disable completely.
 * NOTE Multiple fans can be assigned to the same pin in which case
 * the fan will turn on when any selected extruder is above the threshold.
 * NOTE fan pins are enabled only for defined HOTENDS. Others will be ignored
 * See congig_adv.h
 */
#define NO_E_PIN    -1    //set to -1 to disable completely
//FAN0_PIN, FAN1_PIN and FAN2_PIN are set by default
#define myE0_AUTO_FAN_PIN   FAN1_PIN 
#define myE1_AUTO_FAN_PIN   EXT_1_13_PIN //PWM/SERVO Pin
#define myE2_AUTO_FAN_PIN   EXT_1_6_PIN //PWM/SERVO Pin
#define myE3_AUTO_FAN_PIN   EXT_1_3_PIN //PWM/SERVO Pin

/**
 * Controller Fan
 * To cool down the stepper drivers and MOSFETs.
 *
 * The fan will turn on automatically whenever any stepper is enabled
 * and turn off after a set period after all steppers are turned off.
 */
#define myCONTROLLER_FAN_PIN FAN2_PIN       //define as needed  //ppd

/**
 * Stepper Drivers
 *
 * These settings allow Marlin to tune stepper driver timing and enable advanced options for
 * stepper drivers that support them. You may also override timing options in Configuration_adv.h.
 *
 */

//ppd TMC2208/TMC2209 added  driver selection. select at top of configuration.h under motherboard
 #ifdef using_TMC2208_STANDALONE  //ppd
	#define X_DRIVER_TYPE  TMC2208_STANDALONE
	#define Y_DRIVER_TYPE  TMC2208_STANDALONE
	#define Z_DRIVER_TYPE  TMC2208_STANDALONE

 	#define E0_DRIVER_TYPE TMC2208_STANDALONE
	#define E1_DRIVER_TYPE TMC2208_STANDALONE
	#define E2_DRIVER_TYPE TMC2208_STANDALONE
	#define E3_DRIVER_TYPE TMC2208_STANDALONE
#endif

//ppd added if for driver selection. select at top under motherboard
 #ifdef using_TMC2208_UART  //ppd
	#define X_DRIVER_TYPE  TMC2208
	#define Y_DRIVER_TYPE  TMC2208
 	#define E0_DRIVER_TYPE TMC2208  
	#define E1_DRIVER_TYPE TMC2208
  	#define Z_DRIVER_TYPE  TMC2208
	#define E2_DRIVER_TYPE TMC2208
	#define E3_DRIVER_TYPE TMC2208
#endif
 
#ifdef using_TMC2209_UART	//ppd
	#define X_DRIVER_TYPE  TMC2209
	#define Y_DRIVER_TYPE  TMC2209
	#define Z_DRIVER_TYPE  TMC2209

 	#define E0_DRIVER_TYPE TMC2209
	#define E1_DRIVER_TYPE TMC2209
	#define E2_DRIVER_TYPE TMC2209
	#define E3_DRIVER_TYPE TMC2209
#endif
 
 #ifdef using_TMC2209  //ppd
	#define X_DRIVER_TYPE  TMC2209_STANDALONE
	#define Y_DRIVER_TYPE  TMC2209_STANDALONE
	#define Z_DRIVER_TYPE  TMC2209_STANDALONE

 	#define E0_DRIVER_TYPE TMC2209_STANDALONE
	#define E1_DRIVER_TYPE TMC2209_STANDALONE
	#define E2_DRIVER_TYPE TMC209_STANDALONE
	#define E3_DRIVER_TYPE TMC2209_STANDALONE
#endif
 
//**************************custom pins for SKR PRO end *******************************                                                                     
