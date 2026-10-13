#include <Arduino.h>
#include "func.cpp"

void setup()
{
    Serial.begin(115200);

    LedVerde.iniciar();
    botaoA.iniciar();
    botaoB.iniciar();

    lcd.init();
    lcd.backlight();

    randomSeed(micros());

    LedVerde.desligar();

    lcd.setCursor(0, 0);
    lcd.print("A para iniciar");
}

void loop()
{
    iniciarJogo();
}
