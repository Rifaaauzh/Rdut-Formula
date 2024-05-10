// Function to calculate Rx = (R2 * (Vin / Vout)) - R1 - R2
float calculateRx(float Vin, float Vout, float R1, float R2) {
    return (R2 * (Vin / Vout)) - R1 - R2;
}

float voltageDivider(float Vin, float Rx, float R1, float R2) {
    return Vin * (R2 / (Rx + R1 + R2));
}

void setup() {
  
    Serial.begin(9600);
}

void loop() {
  
  float Vin = 12.0;   // Input voltage
  float R1 = 100;   // Resistance R1 in ohms
  float R2 = 200000;   // Resistance R2 in ohms
  float Vout = 3.27;

  float Rx = calculateRx(Vin, Vout, R1, R2);

  Serial.print("Calculated Rx: ");
  Serial.print(Rx);
  Serial.println(" ohms");

  float VolOut= voltageDivider(Vin, Rx, R1, R2);

  Serial.print("Calculated Vout: ");
  Serial.print(VolOut);
  Serial.println(" V");

  delay(10000);
}
