#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "Botao.h"
#include "Led.h"

Led LedVerde(2);
Led LedAmarelo(4);
Botao botaoA(32);
Botao botaoB(33);
LiquidCrystal_I2C lcd(0x27, 20, 4);

unsigned long tempoInicial = 0;
unsigned long tempoAcumulado = 0;
unsigned long ultimaExibicao = 0;
bool cronometroAtivo = false;

void Cronometro()
{
    unsigned long agora = millis();

    if (botaoA.pressionou())
    {
        if (!cronometroAtivo)
        {
            tempoInicial = agora;
            cronometroAtivo = true;
        }
        else
        {
            tempoAcumulado += agora - tempoInicial;
            cronometroAtivo = false;
        }
    }

    if (botaoB.pressionou() && !cronometroAtivo)
    {
        tempoAcumulado = 0;
        tempoInicial = 0;
    }

    unsigned long tempoDecorrido = tempoAcumulado;

    if (cronometroAtivo)
    {
        tempoDecorrido += agora - tempoInicial;
    }

    unsigned long minutos = tempoDecorrido / 60000;
    unsigned long segundos = (tempoDecorrido % 60000) / 1000;
    unsigned long decimos = (tempoDecorrido % 1000) / 100;

    if (agora - ultimaExibicao >= 100)
    {
        char buffer[12];
        snprintf(buffer, sizeof(buffer), "%02lu:%02lu.%lu", minutos, segundos, decimos);

        lcd.setCursor(7, 1);
        lcd.print("            ");
        lcd.setCursor(7, 1);
        lcd.print(buffer);

        ultimaExibicao = agora;
    }

    if (cronometroAtivo)
    {
        LedVerde.ligar();
        LedAmarelo.desligar();
    }
    else
    {
        LedVerde.desligar();
        LedAmarelo.ligar();
    }
}

void InicializarBotoes()
{
    botaoA.iniciar();
    botaoB.iniciar();
}

void atualizarBotoes()
{
    botaoA.atualizar();
    botaoB.atualizar();
}