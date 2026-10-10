#include <Arduino.h>
#ifndef _BOTAO_H_
#define _BOTAO_H_

class Botao{
private:
    uint8_t pinoBotao;
    bool estadoAtualBotao = HIGH;
    bool estadoAnteriorBotao = HIGH;
    unsigned int contadorCliques = 0;

public:
    Botao(uint8_t pino);
    void iniciar();
    bool lerEstado();
    bool atualizar();
    bool pressionou();
    bool soltou();
    bool click();
    unsigned int getContador() const;
};

#endif