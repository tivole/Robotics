# MQ7

<p align="center">
  <img width="35%" height="35%" src="img/mq7_module.jpg">
</p>


## Description
MQ-7 is a **Carbon Monoxide** (CO) sensor, suitable for sensing Carbon Monoxide concentrations(PPM) in the air. The MQ-7 sensor can measure CO concentrations ranging from 20 to 2000ppm.


## Details
* Using temperature: -20°C to +50°C
* Relative humidity: ≤95%RH
* Oxygen concentration: 21% (stand condition)


## Scheme
<p align="center">
  <img width="60%" height="60%" src="img/mq7_scheme.png">
</p>


## Code
```arduino
const int AOUTpin=0;
const int DOUTpin=2;

int limit;
int value;

void setup() {
  Serial.begin(115200);
  pinMode(DOUTpin, INPUT);
}

void loop() {
  value = analogRead(AOUTpin);
  limit = digitalRead(DOUTpin);
  Serial.print("CO value: ");
  Serial.println(value);
  Serial.print("Limit: ");
  Serial.print(limit);
  delay(100);
  if (limit == HIGH){
    Serial.println("CO level is HIGH")
  }
  else{
    Serial.println("CO level is LOW")
  }
}
```