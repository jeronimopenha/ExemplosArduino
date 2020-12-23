#define SOM 2
#define C 132
#define D 149
#define E 165
#define FA 176
#define G 198
#define A 220
#define B 248

byte nota;
byte counter = 0;
byte flag = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
  //define o pino 9 como saída
  pinMode(SOM, OUTPUT);
  Serial.println("Programa Piano Rústico :)");
  Serial.println();
}

void loop() {

  if (flag) {
    if (counter > 15) {
      Serial.println();
      counter = 0;
    }
    counter++;
    flag = 0;
  }
  if (Serial.available() > 0) {
    nota = Serial.read();
    switch (nota) {
      case 'c':
        tone(SOM, C);
        Serial.write("Do, ");
        flag = 1;
        break;
      case 'd':
        tone(SOM, D);
        Serial.write("Re, ");
        flag = 1;
        break;
      case 'e':
        tone(SOM, E);
        Serial.write("Mi, ");
        flag = 1;
        break;
      case 'f':
        tone(SOM, FA);
        Serial.write("Fa, ");
        flag = 1;
        break;
      case 'g':
        tone(SOM, G);
        Serial.write("Sol, ");
        flag = 1;
        break;
      case 'a':
        tone(SOM, A);
        Serial.write("La, ");
        flag = 1;
        break;
      case 'b':
        tone(SOM, B);
        Serial.write("Si, ");
        flag = 1;
        break;
      case 'o':
        noTone(SOM);
        Serial.println();
        Serial.write("Desligado");
        Serial.println();
        flag = 0;
        counter = 0;
        break;
    }
  }
}
