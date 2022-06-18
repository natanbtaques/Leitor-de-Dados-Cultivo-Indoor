

//Bibliotecas
#include <dht.h>
#include "dht.h"
#include <SPI.h>
#include <SD.h>


// Selecao de pinos analógicos e digitais
const int pinoDHT11 = A2;   //PINO ANALÓGICO UTILIZADO PELO DHT11
const int pinoSensor1 = A0; //PINO UTILIZADO PELO SENSOR 01
const int pinoSensor2 = A1; //PINO UTILIZADO PELO SENSOR 02
const int pinoSensor3 = A3; //PINO UTILIZADO PELO SENSOR 03
const int pinoSensor4 = A4; //PINO UTILIZADO PELO SENSOR 04
const int pinoSensor5 = A5; //PINO UTILIZADO PELO SENSOR 05

int n = 0;
int day = 1;


int chipSelect = 4; // chipe do arduino para SD 
int valorLido1; //VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO 01
int valorLido2; //VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO 02
int valorLido3; //VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO 03
int valorLido4; //VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO 04
int valorLido5; //VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO 05
int analogSoloSeco = 1023; //VALOR MEDIDO COM O SOLO SECO 
int analogSoloMolhado = 0; //VALOR MEDIDO COM O SOLO MOLHADO 
int percSoloSeco = 0; //MENOR PERCENTUAL DO SOLO SECO (0% - NÃO ALTERAR)
int percSoloMolhado = 100; //MAIOR PERCENTUAL DO SOLO MOLHADO 



File myFile; // denomino o sistema File com o nome de MyFile
dht DHT; //VARIÁVEL DO TIPO DHT

void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  pinMode(chipSelect, OUTPUT);

  if (SD.begin()) { // Inicializa o SD Card
  Serial.println("SD Card pronto para uso."); // Imprime na tela
  }
 
  else {
  Serial.println("Falha na inicialização do SD Card.");
  return;
  }

  Serial.println("Lendo Variaveis de Analise..."); //IMPRIME O TEXTO NO MONITOR SERIAL
  delay(2000); //INTERVALO DE 2 SEGUNDOS

 myFile = SD.open("Midc1.txt", FILE_WRITE); // Cria / Abre arquivo .txt
      if (myFile) {

 Serial.print("Hora: "); 
 Serial.print(",");
 Serial.print("Dia: ");
 Serial.print(","); 
 Serial.print("Umidade do solo 1 "); 
 Serial.print(",");
 Serial.print("Umidade do solo 2 "); 
 Serial.print(",");
 Serial.print("Umidade do solo 3 "); 
 Serial.print(",");
 Serial.print("Umidade do solo 4 "); 
 Serial.print(",");
 Serial.print("Umidade do solo 5 "); 
 Serial.print(",");
 Serial.print(" Umidade do Ambiente "); 
 Serial.print(",");
 Serial.print(" Temperatura: "); 

 myFile.print("Hora: "); 
 myFile.print(",");
 myFile.print("Dia: ");
 myFile.print(","); 
 myFile.print("Umidade do solo 1 "); 
 myFile.print(",");
 myFile.print("Umidade do solo 2 "); 
 myFile.print(",");
 myFile.print("Umidade do solo 3 "); 
 myFile.print(",");
 myFile.print("Umidade do solo 4 "); 
 myFile.print(",");
 myFile.print("Umidade do solo 5 "); 
 myFile.print(",");
 myFile.print(" Umidade do Ambiente "); 
 myFile.print(",");
 myFile.print(" Temperatura: "); 

      }
myFile.close(); 
  
}




void loop() {

  // leitura direcionada ao cartão MicroSD
    myFile = SD.open("Midc1.txt", FILE_WRITE); // Cria / Abre arquivo .txt
      if (myFile) {


        
    myFile.println(" ");
    myFile.print(n);
    myFile.print(",       ");
    myFile.print(day);
    myFile.print(",            ");
  

    //SENSOR DE SOLO 01
    //myFile.print("Umidade do solo 1: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    myFile.print(valorLido1); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
    myFile.print("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
    myFile.print(",                 ");
    
    //SENSOR DE SOLO 02
   // myFile.print("Umidade do solo 2: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    myFile.print(valorLido2); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
    myFile.print("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
    myFile.print(",                 ");

    //SENSOR DE SOLO 03
   // myFile.print("Umidade do solo 3: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    myFile.print(valorLido3); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
    myFile.print("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
    myFile.print(",                 ");
    
    //SENSOR DE SOLO 04
   // myFile.print("Umidade do solo 4: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    myFile.print(valorLido4); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
    myFile.print("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
    myFile.print(",                 ");

    //SENSOR DE SOLO 05
   // myFile.print("Umidade do solo 5: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    myFile.print(valorLido5); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
    myFile.print("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
    myFile.print(",                 ");
   
    
    //SENSOR DHT11
    //myFile.print("Umidade: "); //IMPRIME O TEXTO NA SERIAL
    myFile.print(DHT.humidity); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
    myFile.print("%"); //ESCREVE O TEXTO EM SEGUIDA
    myFile.print(",       ");
   // myFile.print(" / Temperatura: "); //IMPRIME O TEXTO NA SERIAL
    myFile.print(DHT.temperature, 0); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
    myFile.print("*C"); //IMPRIME O TEXTO NA SERIAL
    myFile.print("                    ");
    
    
    myFile.close(); 




    delay (2000);
    
  }



  Serial.println(" ");
  Serial.print(n);
  Serial.print("       ");
  Serial.print(day);
  Serial.print("            ");
  
 
  // Coloca em Porcentagem os valores de 0 a 1023 lidos pelo sensor de umidade 01 do sólo e imprime no serial
  valorLido1 = constrain(analogRead(pinoSensor1), analogSoloMolhado, analogSoloSeco); //MANTÉM valorLido DENTRO DO INTERVALO (ENTRE analogSoloMolhado E analogSoloSeco)
  valorLido1 = map(valorLido1, analogSoloMolhado, analogSoloSeco, percSoloMolhado, percSoloSeco); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
  Serial.print(valorLido1); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
  Serial.print("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
  Serial.print("                 ");


  // Coloca em Porcentagem os valores de 0 a 1023 lidos pelo sensor de umidade 02 do sólo e imprime no serial
  valorLido2 = constrain(analogRead(pinoSensor2), analogSoloMolhado, analogSoloSeco); //MANTÉM valorLido DENTRO DO INTERVALO (ENTRE analogSoloMolhado E analogSoloSeco)
  valorLido2 = map(valorLido2, analogSoloMolhado, analogSoloSeco, percSoloMolhado, percSoloSeco); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
  //Serial.print("Umidade do solo 2: "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(valorLido2); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
  Serial.print("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
  Serial.print("                ");


// Coloca em Porcentagem os valores de 0 a 1023 lidos pelo sensor de umidade 03 do sólo e imprime no serial
 valorLido3 = constrain(analogRead(pinoSensor3), analogSoloMolhado, analogSoloSeco); //MANTÉM valorLido DENTRO DO INTERVALO (ENTRE analogSoloMolhado E analogSoloSeco)
 valorLido3 = map(valorLido3, analogSoloMolhado, analogSoloSeco, percSoloMolhado, percSoloSeco); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
// Serial.print("Umidade do solo 3: "); //IMPRIME O TEXTO NO MONITOR SERIAL
 Serial.print(valorLido3); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
 Serial.print("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
 Serial.print("                 ");

  
 // Coloca em Porcentagem os valores de 0 a 1023 lidos pelo sensor de umidade 04 do sólo e imprime no serial
 valorLido4 = constrain(analogRead(pinoSensor4), analogSoloMolhado, analogSoloSeco); //MANTÉM valorLido DENTRO DO INTERVALO (ENTRE analogSoloMolhado E analogSoloSeco)
 valorLido4 = map(valorLido4, analogSoloMolhado, analogSoloSeco, percSoloMolhado, percSoloSeco); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
// Serial.print("Umidade do solo 4: "); //IMPRIME O TEXTO NO MONITOR SERIAL
 Serial.print(valorLido4); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
 Serial.print("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
 Serial.print("                  ");

 // Coloca em Porcentagem os valores de 0 a 1023 lidos pelo sensor de umidade 04 do sólo e imprime no serial
 valorLido5 = constrain(analogRead(pinoSensor5), analogSoloMolhado, analogSoloSeco); //MANTÉM valorLido DENTRO DO INTERVALO (ENTRE analogSoloMolhado E analogSoloSeco)
 valorLido5 = map(valorLido5, analogSoloMolhado, analogSoloSeco, percSoloMolhado, percSoloSeco); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
// Serial.print("Umidade do solo 5: "); //IMPRIME O TEXTO NO MONITOR SERIAL
 Serial.print(valorLido5); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
 Serial.print("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
 Serial.print("                 ");


  // Parte responsavel pelo DHT11
  DHT.read11(pinoDHT11); //LÊ AS INFORMAÇÕES DO SENSOR
 // Serial.print("Umidade do Ambiente: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(DHT.humidity); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
  Serial.print("%"); //ESCREVE O TEXTO EM SEGUIDA
  Serial.print("        ");
 // Serial.print(" Temperatura: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(DHT.temperature, 0); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
  Serial.print("*C"); //IMPRIME O TEXTO NA SERIAL
  Serial.print("                    ");
  delay(2000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR

  Serial.println("");




    n=n+1;   
    if (n>=24){
    day=day+1;
    n=0;
    }
    


 
   
  delay (3600000);
}




void inicia_SD(){
   // se retirar a parte serial desta funcao conseguimos mais 3% de economia de memoria
    while (!Serial) {
    ; // Aguarde pela conexao.
    }
    Serial.print("SD CARD…");
    pinMode(4, OUTPUT); // define o pino 9 como saída, ChipSelected.
     
    if (!SD.begin(4)){
    Serial.println("Falhou");
    return;
    }
    Serial.println("Conectado.");
}
