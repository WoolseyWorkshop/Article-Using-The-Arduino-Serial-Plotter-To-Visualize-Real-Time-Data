// LSM6DS3_SerialPlotter - LSM6DS3_SerialPlotter.ino
//
// Description:
// Retrieves motion data from the on-board LSM6DS3 IMU and displays readings in
// the Serial Plotter.
//
// Created by John Woolsey on 05/01/2019.
// Copyright © 2019 Woolsey Workshop.  All rights reserved.


// Includes
#include <SparkFunLSM6DS3.h>
#include <SPI.h>


// Defines
#define PLOT_INTERVAL 100


// Global Variables
unsigned long previousTime = 0;


// Constructors
LSM6DS3 imu(SPI_MODE, SPIIMU_SS);  // set SPI mode and chip select for on-board IMU


void setup() {
   Serial.begin(9600);  // initialize serial bus (Serial Plotter)
   delay(1000);         // wait one second for IMU reset to complete
   imu.begin();         // initialize IMU
}


void loop() {
   unsigned long currentTime = millis();
   if (currentTime - previousTime >= PLOT_INTERVAL) {
      Serial.print(imu.readFloatAccelX());  Serial.print(" ");  // x-axis
      Serial.print(imu.readFloatAccelY());  Serial.print(" ");  // y-axis
      Serial.println(imu.readFloatAccelZ());                    // z-axis
      previousTime = currentTime;
   }
}
