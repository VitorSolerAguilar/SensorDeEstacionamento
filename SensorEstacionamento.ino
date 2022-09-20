int ledVermelho= 3, ledAmarelo = 4, ledVerde = 5, pinoTrig = 10, pinoEcho = 9, buzzer = 6;
float distancia, duracao;
float velocidade = 0.0172316;

void setup()
{
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //Inicio instruçao obrigatória sensor
  digitalWrite(pinoTrig, 0);
  delayMicroseconds(5);
  
  digitalWrite(pinoTrig, 1);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, 0);
  
  duracao = pulseIn(pinoEcho, 1);
  distancia = duracao * velocidade;
  //Fim instrução obrigatória sensor
  
  if(distancia >= 25 && distancia <= 50){
     digitalWrite(ledVerde, 1);
     tone(buzzer, 1500);
     Serial.print("Proximo ao obstaculo: ");
     Serial.println(distancia);
  }
  else if(distancia > 10 && distancia < 25){
     digitalWrite(ledAmarelo, 1);
     tone(buzzer, 2000);
     Serial.print("Perto do obstaculo: ");
     Serial.println(distancia);
  }
  else if(distancia < 10){
     digitalWrite(ledVermelho, 1);
     tone(buzzer, 3000);
     Serial.print("Muito perto do obstaculo: ");
     Serial.println(distancia);
  }
  else{
     noTone(buzzer);
     digitalWrite(ledVerde, 0);
     digitalWrite(ledAmarelo, 0);
     digitalWrite(ledVermelho, 0);
  }
  
    delay(500);
}
