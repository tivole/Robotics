/*
    Pocket Geiger Module Sketch

    (c) Tivole
*/

unsigned int Read_Radiation(int POCKET_GEIGER_PIN) {

}

#define LOG_PERIOD 15000
#define MAX_PERIOD 60000

unsigned long counts;
unsigned int cpm;
unsigned int multiplier;
unsigned long previousMillis;

void tube_impulse(){
    counts++;
}

void setup(){
    counts = 0;
    cpm = 0;
    multiplier = MAX_PERIOD / LOG_PERIOD;
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(2), tube_impulse, RISING);
}

void loop() {
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > LOG_PERIOD){
        previousMillis = currentMillis;
        cpm = counts * multiplier;
        Serial.print(cpm);
        Serial.write(' ');
        counts = 0;
    }
}