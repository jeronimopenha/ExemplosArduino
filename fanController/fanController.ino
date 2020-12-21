#define FAN 3

byte vel;

void setup() {
  pinMode(FAN, OUTPUT);
  //inicia a interface serial
  Serial.begin(9600);
  delay(1000);
  Serial.println("Digite um valor entre 0 e 100%: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    vel = Serial.parseInt();
    Serial.read();
    if(vel > 100){
      Serial.println("Erro! O valor deve ser menor ou igual a 100%");
      Serial.println("Digite um valor entre 0 e 100%: ");  
      return;
    }else if(vel < 0){
      Serial.println("Erro! O valor deve ser maior ou igual a 0%");
      Serial.println("Digite um valor entre 0 e 100%: ");
      return;
    }
    vel = vel/100.0*255;
    analogWrite(FAN, vel);
    Serial.print("Ventilador com velocidade em: ");
    Serial.print(vel/255.0*100);
    Serial.println("%.");
    Serial.println("Digite um valor entre 0 e 100%: ");
  }
}
