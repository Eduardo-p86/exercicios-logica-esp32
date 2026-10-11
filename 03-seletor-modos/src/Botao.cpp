#include "Botao.h"

unsigned int Botao::contadorCliques = 0;

Botao::Botao(uint8_t pino) : pinoBotao(pino), estadoAtualBotao(HIGH), estadoAnteriorBotao(HIGH)
{
}

bool Botao::lerEstado()
{
    bool estadoAtual = digitalRead(pinoBotao);

    if (estadoAtual != estadoAnteriorBotao)
    {
        delay(50); // debounce
        estadoAtual = digitalRead(pinoBotao);
    }

    estadoAnteriorBotao = estadoAtual;
    estadoAtualBotao = estadoAtual;
    return estadoAtual;
}

bool Botao::atualizar()
{
    estadoAnteriorBotao = estadoAtualBotao;
    estadoAtualBotao = digitalRead(pinoBotao);
    return estadoAtualBotao;
}

bool Botao::pressionou()
{
    return estadoAtualBotao == LOW && estadoAnteriorBotao == HIGH;
}

bool Botao::soltou()
{
    return estadoAtualBotao == HIGH && estadoAnteriorBotao == LOW;
}

bool Botao::clickMais()
{
    atualizar();

    if (pressionou())
    {
        contadorCliques++;
        return true;
    }

    return false;
}

bool Botao::clickMenos()
{
    atualizar();

    if (pressionou())
    {
        if (contadorCliques > 0)
        {
            contadorCliques--;
        }
        return true;
    }

    return false;
}

unsigned int Botao::getContador()
{
    return contadorCliques;
}

void Botao::resetContador()
{
    contadorCliques = 0;
}

void Botao::iniciar()
{
    pinMode(pinoBotao, INPUT_PULLUP);
    estadoAtualBotao = digitalRead(pinoBotao);
    estadoAnteriorBotao = estadoAtualBotao;
}