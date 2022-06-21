bool som;
const int pinoDetect = 13;
const int led = 8;
const int vermelho = 6;
const int verde = 5;
const int azul = 3;
const int gas = 10;

void setup() {
  Serial.begin(9600);
  pinMode(pinoDetect, INPUT);
  pinMode(led, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(gas, INPUT);
}

void loop() {
  analogWrite(azul, 0);
  som = digitalRead(pinoDetect);

  if(digitalRead(gas) == LOW && !som) {
    analogWrite(vermelho, 228);
    analogWrite(azul, 224);
    analogWrite(verde, 0);
    delay(3000);
  } else if (!som) {
    analogWrite(verde, 255);
    analogWrite(vermelho, 0);
    delay(3000);
    analogWrite(verde, 0);
  } else if (digitalRead(gas) == LOW) {
    analogWrite(vermelho, 255);
    analogWrite(verde, 0);  
  } else {
    analogWrite(vermelho, 0);
    analogWrite(azul, 0);
  }

}

void piscar() {
  analogWrite(azul, 0);
  analogWrite(verde, 255);
  delay(1000);
  analogWrite(verde, 0);
  delay(200);
}
