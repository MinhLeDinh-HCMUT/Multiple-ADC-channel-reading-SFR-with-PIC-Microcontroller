# Multiple ADC channels reading with Special Function Register (SFR) of PIC microcontroller
## Microcontrollers that can be used
- PIC16F877
- PIC16F877A
- PIC16F887
## Project task
- Reading ADC values of 3 channels: Channel 0 every 1 second, Channel 1 every 2 seconds and Channel 2 every 3 seconds.
- Do not use built-in function, only SFRs are allowed.
- ADC input sources can be potentiometers, temperature sensors, etc. 
## Program used
- Proteus v8.12
- PIC CCS C v5.115 / MPLAB X IDE v5.45
## How to use
- Create a Proteus project and wire as shown in the image.
- Use the .hex file to input to the PIC microcontroller in Proteus for quick simulation.
- If modification is needed, create a PIC CCS C project or a MPLAB X IDE project (if MPLAB X IDE is used, please remove the register address declaration lines)
- Generate .hex file for Proteus from the above project. 
## Project simulation video
- https://drive.google.com/file/d/19L-4WxQqMVdc_yUZemNKGSPHbd9ma7Wh/view?usp=sharing
