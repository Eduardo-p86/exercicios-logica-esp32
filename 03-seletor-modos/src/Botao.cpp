#include "Botao.h"

Botao::Botao(uint8_t pino) : pinoBotao(pino), estadoAtualBotao(HIGH), estadoAnteriorBotao(HIGH), contadorCliques(0)
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

bool Botao::click()
{
    atualizar();

    if (pressionou())
    {
        contadorCliques++;
        return true;
    }

    return false;
}

unsigned int Botao::getContador() const
{
    return contadorCliques;
}

void Botao::iniciar()
{
    pinMode(pinoBotao, INPUT_PULLUP);
    estadoAtualBotao = digitalRead(pinoBotao);
    estadoAnteriorBotao = estadoAtualBotao;
}