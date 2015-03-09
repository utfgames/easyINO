/***************UTFGames - UTFPR - Campus Cornélio Procópio*******************
	This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
	
	Developed by Lucas da Cunha Bueno
*****************************************************************/

/*---DEFINIÇÃO DE CONSTANTES---*/
#ifndef _easyINO
#define _easyINO
#define ENTRADA 0
#define SAIDA 1
#define LIGADO 1
#define DESLIGADO 0

/*---INCLUSÃO DE BIBLIOTECAS---*/
#include <Arduino.h>
#include <String.h>

/*---easyINO-DEF_BEGIN---*/
void modoPino(uint8_t pino, uint8_t modo);
void escreveDigital(uint8_t pino, uint8_t estado);
uint8_t leDigital(uint8_t pino);
void iniciaSerial(unsigned int baud);
void espera(short ms);
void esperaMicrosegundos(unsigned int);
void enviaSerial(String msg);
String leSerial();
int leAnalogico(uint8_t pino);
void escreveAnalogico(uint8_t pino, int valor);
unsigned long milisegundos();
unsigned long microsegundos();
double seno(float angulo);
double cosseno(float angulo);
double tangente(float angulo);
int absoluto(int numero);
double raizQuadrada(double numero); 
double potencia(double base, double expoente); 
long mapeamento(long valor, long deMenor, long deMaior, long paraMenor, long paraMaior);
long maior(long numero1, long numero2);
long menor(long numero1, long numero2);
long restricao(long numero, long minimo, long maximo);
long aleatorio(long maximo);
long aleatorio(long minimo, long maximo);
void iniciaAleatorio(long inicio);
void tocarSom(uint8_t pino, unsigned int frequencia);
void tocarSom(uint8_t pino, unsigned int frequencia, unsigned long duracao);
void desligaSom(uint8_t pino);
bool serialDisponivel();
void acendeLed(uint8_t pino);
void apagaLed(uint8_t pino);
void interrupcao();
void desinterrupcao();

/*---TRADUÇÕES---*/
/*--Esta função define o modo do pino escolhido como entrada ou saída--*/
void modoPino(uint8_t pino, uint8_t modo){
	if(modo)
		pinMode(pino,1);
	else
		pinMode(pino,0);
}
/*--Esta função faz uma escrita digital na porta digital--*/
void escreveDigital(uint8_t pino, uint8_t estado){
	if(estado)
		digitalWrite(pino,1);
	else
		digitalWrite(pino,0);
}
/*--Esta função faz uma leitura digital da porta escolhida--*/
uint8_t leDigital(uint8_t pino){
	return digitalRead(pino);
}
/*--Esta função inicia a comunicação serial--*/
void iniciaSerial(int baud){
	Serial.begin(baud);
}
/*--Esta função envia um texto através da comunicação serial--*/
void enviaSerial(String msg){
	Serial.println(msg);
}
/*--Esta função le um texto através da comunicação serial--*/
String leSerial(){
	return String(Serial.read());
}
/*--Esta função faz o sistema esperar por um tempo--*/
void espera(int ms){
	delay(ms);
}
/*--Esta função faz uma leitura analógico da porta escolhida--*/
int leAnalogico(uint8_t pino){
	return analogRead(pino);
}
/*--Esta função faz uma escrita analógica na porta escolhida--*/
void escreveAnalogico(uint8_t pino, int valor){
	analogWrite(pino, valor);
}
/*--Esta função retorna a contagem de tempo de execução em milisegundos--*/
unsigned long milisegundos(){
	return millis();
}
/*--Esta função retorna a contagem de tempo de execução em microsegundos--*/
unsigned long microsegundos(){
	return micros();
}
/*--Esta função faz o sistema esperar por um tempo medido em microsegundos--*/
void esperaMicrosegundos(unsigned int microsegundos){
	delayMicroseconds(microsegundos);
}
/*--Esta função retorna o valor do seno do angulo--*/
double seno(float angulo){
	return sin(angulo);
}
/*--Esta função retorna o valor do cosseno do angulo--*/
double cosseno(float angulo){
	return sin(angulo);
}
/*--Esta função retorna o valor do tangente do angulo--*/
double tangente(float angulo){
	return sin(angulo);
}
/*--Esta função retorna o valor absoluto--*/
int absoluto(int numero){
	return abs(numero);
}
/*Esta função retorna o valor da raiz quadrada do numero*/
double raizQuadrada(double numero){
	return sqrt(numero);
}
/*Esta função retorna a potencia de um numero pelo outro*/
double potencia(double base, double expoente){
	return pow(base, expoente);
}
/*Esta função retorna o mapeamento do numero*/
long mapeamento(long valor, long deMenor, long deMaior, long paraMenor, long paraMaior){
	return map(valor, deMenor, deMaior, paraMenor, paraMaior);
}
/*Esta função retorna o maior dos dois numeros*/
long maior(long numero1, long numero2){
	return max(numero1, numero2);
}
/*Esta função retorna o menor dos dois numeros*/
long menor(long numero1, long numero2){
	return min(numero1, numero2);
}
/*Esta função restringe um numero entre um máximo e mínimo*/
long restricao(long numero, long minimo, long maximo){
	return constrain(numero, minimo, maximo);
}
/*Esta função gera um valor aleatório menor que o valor do parametro*/
long aleatorio(long maximo){
	return random(maximo);
}
/*Esta função gera um valor aleatório entre dois valores*/
long aleatorio(long minimo, long maximo){
	return random(minimo, maximo);
}
/*Esta função inicializa a função aleatoria com um valor*/
void iniciaAleatorio(long inicio){
  randomSeed(inicio);
}
/*Esta função toca um som*/
void tocarSom(uint8_t pino, unsigned int frequencia){
	tone(pino, frequencia);
}
/*Esta função toca um som durante um tempo*/
void tocarSom(uint8_t pino, unsigned int frequencia, unsigned long duracao){
	tone(pino, frequencia, duracao);
}
/*Esta função desliga o som*/
void desligaSom(uint8_t pino){
	noTone(pino);
}
/*Esta função verifica se há dados disponiveis na comunicação serial*/
bool serialDisponivel(){
	return Serial.available() > 0;
}
/*Esta função acende um led em uma determinada porta digital*/
void acendeLed(uint8_t pino){
  digitalWrite(pino,1);
}
/*Esta função apaga um led em uma determinada porta digital*/
void apagaLed(uint8_t pino){
  digitalWrite(pino,0);
}
/*Interrompe um conjunto de instruções*/
void interrupcao(){
  interrupts();
}
/*Desinterrompe um conjunto de instruções*/
void desinterrupcao(){
  noInterrupts();
}
/*--easyINO-DEF_END--*/
#endif
