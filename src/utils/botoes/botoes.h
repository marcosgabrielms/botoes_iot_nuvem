#ifndef BOTOES_H
#define BOTOES_H

#include "pico/stdlib.h"
#include <stdbool.h>

#define PINO_BOTAO_A 5
#define PINO_BOTAO_B 6

typedef struct{
    bool botao_a;
    bool botao_b;
} EstadoBotoes;

extern EstadoBotoes *estado_botoes;

void iniciar_botoes();
bool botao_a_pressionado();
bool botao_b_pressionado();

#endif