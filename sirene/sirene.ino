#define SOM 2

float seno;
int frequencia;
byte vel = 0;

void setup() {
  //define o pino 9 como saída
  pinMode(SOM, OUTPUT);
}

void loop() {
  if (vel < 10) {
    for (int x = 0; x < 180; x++) {
      //converte graus para radiando e depois obtém o valor do seno
      seno = (sin(x * 3.1416 / 180));
      //gera uma frequência a partir do valor do seno
      frequencia = 2000 + (int(seno * 1000));
      tone(SOM, frequencia);
      delay(4);
    }
    vel++;
  }else if (vel < 30) {
    for (int x = 0; x < 180; x++) {
      //converte graus para radiando e depois obtém o valor do seno
      seno = (sin(x * 3.1416 / 180));
      //gera uma frequência a partir do valor do seno
      frequencia = 2000 + (int(seno * 1000));
      tone(SOM, frequencia);
      delay(1);
    }
    vel++;
  }else{
    vel = 0;
  }

}
