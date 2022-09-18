
//Variáveis e sets do servomotor

#include <Servo.h>
Servo servomotor; 
int servoPin = 2;

//Variáveis e sets do motor de passo

byte HOR[4] = {0x09,0x03,0x06,0x0C};    // Matriz de fases do motor. Cada valor corresponde a uma fase do modo full step em sentido horário
int atraso_fase = 3;                    // atraso em ms entre cada mudança de fase
int intervalo = 1000;                  // Intervalo de tempo entre os movimentos do motor em ms

//Variáveis e sets do TCS230

#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 7
//Armazenamento da frequência lida pelos fotodiodos
int freqRed = 0;   
int freqGreen = 0; 
int freqBlue = 0; 
//Armazenamento de cores
int red = 0;  
int green = 0; 
int blue = 0; 

//Função de movimento do motor de passo

void Motor_HOR()                  
{ 
 
 for(int i = 0; i < 27; i++) 
 { 
  for(int j = 0; j < 4; j++)  
  {
    PORTB = HOR[j];             
    delay (atraso_fase);
   }
 }
}

//Função de operação do sensor de cor

void SensorCor()
{
/////////////////////////////RED///////////////////////////////////
  
  //Configurando os fotodiodos com filtro vermelho para serem lidos
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  //Leitura da frequência gerada
  freqRed = pulseIn(sensorOut, LOW);
  
  //Mapeia o valor da frequência obtida entre 0 e 255
  //Os valores complementares devem ser adicionados com base nos testes de calibragem
  red = map(freqRed, 102, 133, 255,0);
  
  //Mostra o resultado da cor vermelha no monitor serial
  Serial.print("R = ");
  Serial.print(red);
  delay(100);

/////////////////////////////GREEN///////////////////////////////////
  
  //Configurando os fotodiodos com filtro verde para serem lidos
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  //Leitura da frequência gerada
  freqGreen = pulseIn(sensorOut, LOW);
  
  //Mapeia o valor da frequência obtida entre 0 e 255
  //Os valores complementares devem ser adicionados com base nos testes de calibragem
  green = map(freqGreen, 141, 177, 255, 0);
  
  //Mostra o resultado da cor vermelha no monitor serial 
  Serial.print(" G = ");
  Serial.print(green);
  delay(100);

////////////////////////////BLUE///////////////////////////////////
 
  //Configurando os fotodiodos com filtro azul para serem lidos
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  //Leitura da frequência gerada
  freqBlue = pulseIn(sensorOut, LOW);
  
  //Mapeia o valor da frequência obtida entre 0 e 255
  //Os valores complementares devem ser adicionados com base nos testes de calibragem
  blue = map(freqBlue, 115, 155, 255, 0);
  
  //Mostra o resultado da cor vermelha no monitor serial 
  Serial.print(" B = ");
  Serial.print(blue);
  delay(100);


//Verificador das cores lidas pelo sensor
  if(red > green && red > blue){
      servomotor.write(2); //Ângulo de rotação do eixo do servomotor
      Serial.println(" - Vermelho");
  }
  if(green > red && green > blue){
    servomotor.write(90); //Ângulo de rotação do eixo do servomotor
    Serial.println(" - Verde");
  }
  if(blue > red && blue > green){
    servomotor.write(179); //Ângulo de rotação do eixo do servomotor
    Serial.println(" - Azul");
  }
 }


void setup() {
  
  Serial.begin(9600);

  //Configuração do servomotor
  servomotor.attach(servoPin); // Associa o pino 2 ao servomotor
  servomotor.write(2); // Posição inicial do servomotor


  //Configuração do motor de passo
  DDRB = 0x0F;           // Configura Portas D08,D09,D10 e D11 como saída 
  PORTB = 0x00;          // Reset dos bits da Porta B (D08 a D15) 

  //Configuração do TCS230 
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT); //Configura a variável como um input na placa e na função SensorCor 
  
  //Configurando a frequency scaling para 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
}


void loop() 
{
  Motor_HOR();
  SensorCor();
  delay (1000);
}

   
