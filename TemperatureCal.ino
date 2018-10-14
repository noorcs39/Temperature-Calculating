//Computing the Temperature using equation



int ThermPin = 0; //Thermostal Pin
float Resister1 = 10000.0;
float Resister2;
float resLog;
int V;
float Temp;
float C;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
Serial.begin(9600);
}

void loop() {

  V = analogRead(ThermPin);
 Resister2 = Resister1 * (1023.0 / (float)V - 1.0);
  resLog = log(Resister2);
  Temp = 1.0 / (c1 + c2*resLog + (c3*(resLog*resLog*resLog)));
  Temp = Temp- 273.15;
  C= Temp;
  Temp = (Temp * 9.0)/ 5.0 + 32.0; 

  Serial.println("Temperature Result: "); 
    Serial.print(" F: "); 
  Serial.println(Temp);
Serial.print(" C: "); 
  Serial.println(C);
  
 
  
  
  delay(500);
}
