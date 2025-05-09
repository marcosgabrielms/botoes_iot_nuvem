#ifndef CONEXAO_H
#define CONEXAO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pico/cyw43_arch.h"
#include "lwip/dns.h"
#include "lwip/ip_addr.h"
#include "lwip/tcp.h"

#include "src/utils/botoes/botoes.h"


#define PROXY_HOST "switchback.proxy.rlwy.net"
#define PROXY_PORT 23445

void enviar_dados_para_nuvem(const EstadoBotoes *dados_a_enviar);

#endif 