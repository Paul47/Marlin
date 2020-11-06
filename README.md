## Marlin 3D Printer Firmware for RAMPSXB expansion boards

This branch of the Marlin 2.0.x github project supports up to 4 extruders and stepper drivers in any combination:
extruders     Steppers     example
1             1 to 4       "3 in 1 out", Diamond head, Cyclops
2             2            "2 in 2 out", Chimera
3             3            HE3D hotend triple Nozzle
4             4            E3D Kraken, Chimera 2x

# Supported Controllers

Only two printer controllers are currently supportred (and tested):
    -RE-ARM with RAMPS 1.4 - 1.6
	-SKR-PRO V1.1 and v1.2

# Supported Stepper Drivers

Tested drivers: DRV8825, TMC2208, TMC2209 (including UART mode). Other compatible drivers should work.

## Adding Additional Extruders

# RAMPSXB_4RE-ARM

RE-ARM only supporrts 2 extruders and 1 heater. I have designed expansion board that plugs into the RAMPS board to add up to 2 additional stepper drivers and multiple heaters (including temperature sensors, and multiple fans)
This controller expansion board can be found at:(https://github.com/Paul47/RAMPSXB_4RE-ARM) .

# RAMPSXB_4SKR-PRO

SKR-PRO supporrts 3 extruders. I have designed expansion board that plugs into the motherboard board Extension-1 to add 1 additional stepper driver and multiple heaters (including temperature sensors, and multiple fans)
This controller expansion board can be found at: (https://github.com/Paul47/RAMPSXB_4SKR-PRO) .

## Marlin 2.0

Marlin 2.0 takes the popular RepRap firmware to the next level by adding support for much faster 32-bit and ARM-based boards while improving support for 8-bit AVR boards. Read about Marlin's decision to use a "Hardware Abstraction Layer" below.
Information and code for the main branch of Marlin 2.0 is located at: (https://github.com/MarlinFirmware/Marlin) .
Additional documentation can be found at the [Marlin Home Page](https://marlinfw.org/).
Please test this firmware and let us know if it misbehaves in any way. Volunteers are standing by!

## Building Marlin 2.0

To build Marlin 2.0 you'll need [Arduino IDE 1.8.8 or newer](https://www.arduino.cc/en/main/software) or [PlatformIO](http://docs.platformio.org/en/latest/ide.html#platformio-ide). Detailed build and install instructions are posted at:

  - [Installing Marlin (Arduino)](http://marlinfw.org/docs/basics/install_arduino.html)
  - [Installing Marlin (VSCode)](http://marlinfw.org/docs/basics/install_platformio_vscode.html).


## License

Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
