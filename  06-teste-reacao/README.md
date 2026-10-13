# 06 - Teste de Tempo de Reação

Jogo simples de tempo de reação usando ESP32, um LED verde, dois botões e um display LCD I2C. O jogador espera o LED verde acender e pressiona o botão o mais rápido possível para medir seu tempo de reação em milissegundos.

## O que foi desenvolvido
- **Máquina de Estados**: O jogo opera com 5 estados distintos:
  - **AGUARDANDO**: Tela inicial, esperando o jogador apertar o Botão A para começar.
  - **ESPERANDO_SINAL**: Delay aleatório entre 2 e 5 segundos (`random(2000, 5000)`) antes do LED acender — o jogador deve aguardar.
  - **SINAL_VERDE**: O LED verde acende e o cronômetro começa a contar via `millis()`.
  - **RESULTADO**: O jogador pressionou o Botão B a tempo — o LCD exibe o tempo de reação em ms.
  - **QUEIMADA**: O jogador pressionou o Botão B cedo demais (antes do LED acender).
- **Temporização não bloqueante**: Uso de `millis()` para o delay aleatório e para medir o tempo de reação, sem travar o programa com `delay()`.
- **Aleatoriedade**: `randomSeed(micros())` no `setup()` garante uma semente diferente a cada execução.
- **Classes reutilizadas**: `Led` e `Botao` dos exercícios anteriores.

## Hardware Utilizado
- 1x ESP32 (ou compatível)
- 1x LED Verde (Pino 2)
- 2x Botões:
  - Botão A (Pino 32) — Inicia o jogo
  - Botão B (Pino 33) — Reação do jogador
- 1x Display LCD 20x4 com adaptador I2C (endereço 0x27)
