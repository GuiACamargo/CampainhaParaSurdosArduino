const int trigPin = 12;
const int echoPin = 13;
const int buzzer = 8;

const int distanciaMao = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (distancia() <= distanciaMao) {
    tone(buzzer, 50);
  } else {
    noTone(buzzer);
  }
}

long distancia() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duracao = pulseIn(echoPin, HIGH);
  
  return 1 + ((duracao/2) / 28.9);
  
}
