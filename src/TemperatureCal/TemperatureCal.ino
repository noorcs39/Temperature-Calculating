/*
 * Temperature Calculating - Arduino Thermistor Project
 * Author: Noor Uddin (noor.cs2@yahoo.com)
 * Uses the Steinhart-Hart equation to convert thermistor resistance to temperature.
 */

// Calculate temperature from a thermistor using the Steinhart-Hart equation.

const int THERMISTOR_PIN = A0;
const float SERIES_RESISTOR = 10000.0;

const float COEFFICIENT_A = 1.009249522e-03;
const float COEFFICIENT_B = 2.378405444e-04;
const float COEFFICIENT_C = 2.019202697e-07;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(THERMISTOR_PIN);

  if (analogValue == 0) {
    Serial.println("Invalid sensor reading.");
    delay(500);
    return;
  }

  float thermistorResistance = SERIES_RESISTOR * (1023.0 / analogValue - 1.0);
  float logResistance = log(thermistorResistance);

  float temperatureKelvin = 1.0 / (
    COEFFICIENT_A +
    (COEFFICIENT_B * logResistance) +
    (COEFFICIENT_C * logResistance * logResistance * logResistance)
  );

  float temperatureCelsius = temperatureKelvin - 273.15;
  float temperatureFahrenheit = (temperatureCelsius * 9.0) / 5.0 + 32.0;

  Serial.println("Temperature Result:");
  Serial.print("F: ");
  Serial.println(temperatureFahrenheit);
  Serial.print("C: ");
  Serial.println(temperatureCelsius);
  Serial.println();

  delay(500);
}
