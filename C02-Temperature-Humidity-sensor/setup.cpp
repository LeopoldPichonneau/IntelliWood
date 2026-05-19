#include <SensirionI2cScd4x.h>
#include <Arduino.h>
#include <Wire.h>


SensirionI2cScd4x scd4x;

void setup() {
    Serial.begin(115200);

    // SDA = GPIO39
    // SCL = GPIO40
    Wire.begin(39, 40);

    // Init sensor
    scd4x.begin(Wire, 0x62);

    uint16_t error;

    error = scd4x.startPeriodicMeasurement();

    if (error) {
        Serial.print("Error starting measurement: ");
        Serial.println(error);
    } else {
        Serial.println("SCD40 started");
    }
}

void loop() {

    uint16_t co2;
    float temperature;
    float humidity;

    bool isDataReady = false;

    uint16_t error = scd4x.getDataReadyStatus(isDataReady);

    if (!error && isDataReady) {

        error = scd4x.readMeasurement(
            co2,
            temperature,
            humidity
        );

        if (!error) {

            Serial.print("CO2: ");
            Serial.print(co2);
            Serial.println(" ppm");

            Serial.print("Temperature: ");
            Serial.print(temperature);
            Serial.println(" °C");

            Serial.print("Humidity: ");
            Serial.print(humidity);
            Serial.println(" %");

            Serial.println("--------------------");
        }
    }

    delay(5000);
}