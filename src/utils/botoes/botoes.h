#ifndef BOTOES_H
#define BOTOES_H

#include "pico/stdlib.h"

#define PINO_BOTAO_A 5
#define PINO_BOTAO_B 6

void iniciar_botoes();
bool a_pressionado ();
bool b_pressionado ();

#endif