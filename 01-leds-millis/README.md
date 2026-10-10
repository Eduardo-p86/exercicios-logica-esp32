# 01 - LEDs com Millis

Este projeto demonstra como piscar um LED utilizando a função `millis()` do Arduino/ESP32 em vez do tradicional `delay()`. Essa abordagem permite que o microcontrolador execute outras tarefas de forma não bloqueante.

## O que foi desenvolvido
- **Classe `Led`**: Foi criada uma classe para encapsular toda a lógica de controle do LED, facilitando o reuso e a organização do código.
- **Controle de Tempo**: O método `ativarPiscar(500)` configura o LED para alternar seu estado a cada 500 milissegundos usando o `millis()`.
- **Programação Orientada a Objetos (POO)**: Aplicação prática de conceitos de POO em C++ para sistemas embarcados.

## Hardware Utilizado
- 1x ESP32 (ou compatível)
- 1x LED Vermelho (conectado ao pino 13)
- Resistor adequado
