#include <Arduino.h>
#include "func.cpp"
void setup()
{
    Serial.begin(9600);

    lcd.init();
    lcd.backlight();

    LedVerde.iniciar();
    LedAmarelo.iniciar();

    InicializarBotoes();

    lcd.setCursor(0, 1);
    lcd.print("Cronometro:");
}

void loop()
{
    atualizarBotoes();
    Cronometro();
}