#include <Arduino.h>
#include "func.cpp"
void setup()
{
    inicializar();
}

void loop()
{
    botaoA.atualizar();
    botaoB.atualizar();

    nivelLeds();
    atualizarLeds();
    atualizarLCD();
}
