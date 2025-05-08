#ifndef conexao
#define conexao

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/cyw43_arch.h"
#include "lwip/dns.h"
#include "lwip/ip_addr.h"
#include "lwip/tcp.h"
#include "src/utils/botoes/botoes.h"

#define PROXY_HOST
#define PROXY_PORT

void enviar_dados_para_servidor();

#endif