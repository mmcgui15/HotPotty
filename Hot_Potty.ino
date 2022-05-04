double temp = 0;
const int SensorPin = A0;                     //Currently using TMP36 sensor

void heat_on() {
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
}

void heat_off() {
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
}
void setup() {
  pinMode(3, OUTPUT);   //heating active- Connect to COM pin of relay and NO pin to load
  pinMode(4, OUTPUT);   //LED for active heating
}

void loop(){
  int SensorReading = analogRead(SensorPin);
  Serial.print("Sensor reading: ");           //**
  Serial.println(SensorReading);              //**
  double voltage = (SensorReading/1024)*5;    // sensor produces 0-5V represented by input value of 0-1023. 
  temp = (voltage - .5) * 100;                // 10mV/degree Celsius change
    if (temp < 30) {                          //activate below 30, shut off at 32 to prevent constant switching
        heat_on();
    }
    else if (temp > 32) {
        heat_off();
      }
  Serial.print("Temp (C): = ");               //**
  Serial.println(temp);                       //**
  delay(1000);
}

//** only for debugging.
