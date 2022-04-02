# Sample code for accelerometer

This is the sample code for using the accelerometer. Here is a [link to our webpage](https://jentronic.dk/content/17-accelerometer-kode-eksempel), with danish translation of the example.<br />

# Wiring
Tool for generating labels for letters - using LibreOffice Writer and customer data from Prestashop.<br />

![Wiring](/Images/Accelerometer-Schematic-Colored.png)

# Description

This example shows how you can use the Accelerometer / Gyroscope module to control a sphere on an OLED display.<br />

The communication with the MPU6050 chip on the accelerometer module, takes place using the serial IIC (I2C) protocol. Therefore, we use the [Wire](https://www.arduino.cc/en/reference/wire) library, and we specify which IIC address the MPU6050 chip has (0x68). When the program is executed, we start by sending the value 0 to register 0x6B. This is done in order to wake the MPU6050 chip from sleep mode, and ask it to start taking measurements.<br />

We now repeat reading the registers 0x3B - 0x3E, in order to read out the current accelerometer measurements, for the axes X and Y. We store 20 of these measurements, and calcute the average of these 20 measurements - for moving sphere on the screen - if the MPU6050 chip is tilted away from horizontal position.

Simply copy the sample into a new Arduino project, and you're ready to go. Note that you must install the [U8g2](https://www.arduinolibraries.info/libraries/u8g2) library before you can build the program - and that a NodeMCU ESP8266 is used in the example.

The MPU6050 chip is extremely advanced, and in the example show here, we have only just touched the surface of the possibilities. If you want to read more about what you can read from the chip, you can see the [register documentation here](https://www.invensense.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf).
