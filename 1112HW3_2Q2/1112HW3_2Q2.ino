/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/DigitalReadSerial/
*/

const int ledPin = 3;
const int buttonPin = 2;

int mode = 0;
bool lastButtonState = HIGH;
unsigned long previousMillis = 0;
int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(ledPin, LOW);
}


void loop() {
  bool currentButtonState = digitalRead(buttonPin);

  if(lastButtonState == HIGH && currentButtonState == LOW){
    mode++;
    if(mode > 3) mode = 0;
    delay(200);
  }

  lastButtonState = currentButtonState;
  unsigned long currentMillis = millis();

  if(mode == 0){
    digitalWrite(ledPin, LOW);
  } 
  else if (mode == 1){
    if(currentMillis - previousMillis >= 1000){
      previousMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
  }
  else if (mode == 2){
    if(currentMillis - previousMillis >= 500){
      previousMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
  }
  else if (mode == 3){
    if(currentMillis - previousMillis >= 100){
      previousMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
  }
}