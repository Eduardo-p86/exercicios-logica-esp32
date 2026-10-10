#include <Arduino.h>
#include "led.h"


Led LedVermelho(13);

void setup(){

LedVermelho.iniciar();
LedVermelho.ativarPiscar(500);

}

void loop(){

LedVermelho.atualizar();


}