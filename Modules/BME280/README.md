# BME280

<p align="center">
  <img width="35%" height="35%" src="img/bme280_module.jpg">
</p>


## Description
THe BME280 module uses [BME280 sensor](https://www.bosch-sensortec.com/products/environmental-sensors/humidity-sensors-bme280/). The BME280 sensor is a **humidity**, **temperature** and **pressure** sensor especially developed for mobile applications and wearables where size and low power consumption are key design parameters. The unit combines high linearity and high accuracy sensors and is perfectly feasible for low current consumption, long-term stability and high EMC robustness. The BME280 sensor offers an extremely fast response time and therefore supports performance requirements for emerging applications such as context awareness, and high accuracy over a wide temperature range.


## Details
* Pressure operation range: 300...1100 hPa
* Temperature operation range: -40…85°C
* Absolute accuracy: ±1 hPa
* Average typical current consumption (1 Hz data rate): 3.4 μA @ 1 Hz
* Average current consumption (1 Hz data refresh rate): 1.2 ... 3.6 V
* Average current consumption in sleep mode: 1.71 ... 3.6 V



## Scheme

<p align="center">
  <img width="45%" height="45%" src="img/bme280_scheme.png">
</p>


## Code

```arduino

#include <Wire.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

void setup() {
    Serial.begin(9600);
    
    if (!bme.begin()) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        while (1) delay(10);
    }
}


void loop() { 
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
    
    delay(1000);
}
```

Library:

* [Adafruit_BME280](./src/lib)