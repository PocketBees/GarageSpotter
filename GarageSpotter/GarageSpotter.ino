//Design by Cody Knutson
//Last change: 1/15/2015

// HARDWARE:
// Make the following connections between the EZ1, LEDs and the Arduino
// +5V - +5V
// GND - GND
// AN - Analog In 0
// "Slow" LED - Pin slowLedPin
// "Stop" LED - Pin stopLedPin

const int slowLedPin =  3; //Slow down LED
const int stopLedPin =  4; //Stop LED


void setup()
{
  Serial.begin(9600); 
  //Initialize LED pins for output
  pinMode(slowLedPin, OUTPUT);
  pinMode(stopLedPin, OUTPUT);
  //Test LED functionality
  digitalWrite(slowLedPin, HIGH);
  digitalWrite(stopLedPin, HIGH);
  delay(1000);
  digitalWrite(slowLedPin, LOW);
  digitalWrite(stopLedPin, LOW);
}

void loop()
{
  
  int sensor, inches, x;
  
  // read the analog output of the EZ1 from analog input 0
  sensor = analogRead(1);
  
  // convert the sensor reading to inches
  inches = sensor / 2;
  
  // print out the decimal result
  Serial.print(inches);
  
  {
    Serial.print(".");
  }
  Serial.println("|");


if (inches >80){
    Serial.println("   Clear");
    digitalWrite(stopLedPin, LOW);
    digitalWrite(slowLedPin, LOW);
}
  if (inches < 80 && inches > 50){
    digitalWrite(slowLedPin, HIGH);
    digitalWrite(stopLedPin, LOW);
    Serial.println("   Slow");
  }
  if (inches < 50){
    Serial.println("   Stop");
    digitalWrite(slowLedPin, LOW);
    digitalWrite(stopLedPin, HIGH);
  }
  

    
  // pause before taking the next reading
  delay(100);                     
}
