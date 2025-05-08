#include "botoes.h"

void iniciar_botoes ()

{
    gpio_init(PINO_BOTAO_A);
    gpio_set_dir(PINO_BOTAO_A, GPIO_IN);
    gpio_pull_up(PINO_BOTAO_A);

    gpio_init(PINO_BOTAO_B);
    gpio_set_dir(PINO_BOTAO_B, GPIO_IN);
    gpio_pull_up(PINO_BOTAO_B);
}

bool a_pressionado()
{
    return !gpio_get(PINO_BOTAO_A);
}

bool b_pressionado()
{
    return !gpio_get(PINO_BOTAO_B);
}