#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "Botao.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);
Botao botaoA(2);
Botao botaoB(3);

constexpr uint8_t PINO_VERMELHO = 13;
constexpr uint8_t PINO_AMARELO = 12;
constexpr uint8_t PINO_VERDE = 14;

uint8_t modoAtual = 0;
bool ledsAcesos = false;
unsigned long ultimaTroca = 0;

void mostrarModo()
{
    static const char *nomesModos[] = {
        "Todos apagados",
        "Todos acesos",
        "Todos piscam 500ms",
        "Vermelho pisca 150ms"};

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Modo ");
    lcd.print(modoAtual);
    lcd.setCursor(0, 1);
    lcd.print(nomesModos[modoAtual]);
}

void atualizarLeds(unsigned long agora)
{
    switch (modoAtual)
    {
    case 0:
        digitalWrite(PINO_VERMELHO, LOW);
        digitalWrite(PINO_AMARELO, LOW);
        digitalWrite(PINO_VERDE, LOW);
        break;
    case 1:
        digitalWrite(PINO_VERMELHO, HIGH);
        digitalWrite(PINO_AMARELO, HIGH);
        digitalWrite(PINO_VERDE, HIGH);
        break;
    case 2:
        if (agora - ultimaTroca >= 500)
        {
            ledsAcesos = !ledsAcesos;
            ultimaTroca = agora;
        }
        digitalWrite(PINO_VERMELHO, ledsAcesos ? HIGH : LOW);
        digitalWrite(PINO_AMARELO, ledsAcesos ? HIGH : LOW);
        digitalWrite(PINO_VERDE, ledsAcesos ? HIGH : LOW);
        break;
    case 3:
        if (agora - ultimaTroca >= 150)
        {
            ledsAcesos = !ledsAcesos;
            ultimaTroca = agora;
        }
        digitalWrite(PINO_VERMELHO, ledsAcesos ? HIGH : LOW);
        digitalWrite(PINO_AMARELO, LOW);
        digitalWrite(PINO_VERDE, LOW);
        break;
    }
}

void setup()
{
    pinMode(PINO_VERMELHO, OUTPUT);
    pinMode(PINO_AMARELO, OUTPUT);
    pinMode(PINO_VERDE, OUTPUT);

    botaoA.iniciar();
    botaoB.iniciar();

    lcd.init();
    lcd.backlight();
    mostrarModo();
}

void loop()
{
    bool mudouModo = false;

    if (botaoA.clickMais())
    {
        modoAtual = (modoAtual + 1) % 4;
        mudouModo = true;
    }

    if (botaoB.clickMenos())
    {
        modoAtual = 0;
        mudouModo = true;
    }

    if (mudouModo)
    {
        ledsAcesos = false;
        ultimaTroca = millis();
        mostrarModo();
    }

    atualizarLeds(millis());
}