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