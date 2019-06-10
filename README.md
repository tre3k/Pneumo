# Penumo
## Intro
This soft is the Tango-CS server for custom PNPI device. For control valves pneumo system for moving part of TEX-2

## Properties:
1. SerialPort - just path to serial port (for example "/dev/ttyS0")
2. DeviceAddr - for this device "085" (string format)
3. NumOfValve - number of valve from 0 to 15.

## Attributes:
1. valve, type: bool, only write - for changing state of valve (on/off)
2. sensor, type: uint16_t, only read - read state of pressure sensors (all 16 sensors).

## Install:
1. git clone https://github.com/tre3k/Pneumo
2. cd Pneumo
3. mkdir build && cd build
4. cmake ../ 
5. make

