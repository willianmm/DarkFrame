// DarkFrame Studios - prototipo academico TMP36 / Arduino Uno
// Revisar e explicar antes da entrega; validar no Tinkercad.
const byte sensorTemp = A0;
const byte ledVerde = 8;
const byte ledAmarelo = 9;
const byte ledVermelho = 10;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  int leitura = analogRead(sensorTemp);
  float volts = leitura * (5.0 / 1023.0);
  float temperatura = (volts - 0.5) * 100.0; // TMP36: 500mV em 0C, 10mV/C
  digitalWrite(ledVerde, temperatura < 28.0 ? HIGH : LOW);
  digitalWrite(ledAmarelo, temperatura >= 28.0 && temperatura < 32.0 ? HIGH : LOW);
  digitalWrite(ledVermelho, temperatura >= 32.0 ? HIGH : LOW);
  Serial.print("Temperatura (C): ");
  Serial.println(temperatura, 1);
  delay(1000);
}
