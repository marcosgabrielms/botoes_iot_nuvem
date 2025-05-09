#include "botoes.h"
#include <stdlib.h>

EstadoBotoes *estado_botoes = NULL;

void iniciar_botoes() {
       

    estado_botoes = (EstadoBotoes*)malloc(sizeof(EstadoBotoes));
    estado_botoes->botao_a = false;
    estado_botoes->botao_b = false;

    gpio_init(PINO_BOTAO_A);
    gpio_set_dir(PINO_BOTAO_A, GPIO_IN);
    gpio_pull_up(PINO_BOTAO_A);

    gpio_init(PINO_BOTAO_B);
    gpio_set_dir(PINO_BOTAO_B, GPIO_IN);
    gpio_pull_up(PINO_BOTAO_B);
}

bool botao_a_pressionado()
{
    return !gpio_get(PINO_BOTAO_A);
}

bool botao_b_pressionado()
{
    return !gpio_get(PINO_BOTAO_B);
}