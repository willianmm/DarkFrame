# DF-RED-002 — Plano IPv4, VLANs e política de acesso
**Revisão:** 1.0 | **Estado:** projeto, não configurado nem testado. Base: [DF-RED-001](PROJETO-DE-REDES.md).

## Endereçamento e capacidade
| VLAN | Nome | Rede/CIDR | Máscara | Gateway | Hosts válidos | DHCP / estático | Broadcast |
|---:|---|---|---|---|---|---|---|
| 10 | Administração | 10.50.10.0/27 | 255.255.255.224 | 10.50.10.1 | .1–.30 | DHCP .10–.25 | 10.50.10.31 |
| 20 | Operacional | 10.50.20.0/26 | 255.255.255.192 | 10.50.20.1 | .1–.62 | DHCP .10–.55 | 10.50.20.63 |
| 30 | Criativo | 10.50.30.0/27 | 255.255.255.224 | 10.50.30.1 | .1–.30 | DHCP .10–.25 | 10.50.30.31 |
| 40 | TI | 10.50.40.0/27 | 255.255.255.224 | 10.50.40.1 | .1–.30 | DHCP .10–.24 | 10.50.40.31 |
| 50 | Servidores | 10.50.50.0/27 | 255.255.255.224 | 10.50.50.1 | .1–.30 | estáticos .2–.25 | 10.50.50.31 |
| 60 | IoT reservado | 10.50.60.0/27 | 255.255.255.224 | 10.50.60.1 | .1–.30 | reservas .10–.25 | 10.50.60.31 |
| 70 | Visitantes | 10.50.70.0/26 | 255.255.255.192 | 10.50.70.1 | .1–.62 | DHCP .10–.55 | 10.50.70.63 |
| 80 | Impressão | 10.50.80.0/27 | 255.255.255.224 | 10.50.80.1 | .1–.30 | reservas .10–.25 | 10.50.80.31 |
| 90 | Gerência | 10.50.90.0/27 | 255.255.255.224 | 10.50.90.1 | .1–.30 | estáticos .2–.25 | 10.50.90.31 |

**Cálculo:** /27 = 2^(32-27)-2 = 30 hosts; /26 = 2^(32-26)-2 = 62 hosts. Endereços em blocos distintos de terceiro octeto, sem sobreposição. No texto das faixas, o prefixo do endereço é o da rede correspondente. Gateways fixos .1 devem ficar fora do pool DHCP.

**Mapeamento de pessoas:** VLAN10 = 6 (recepção 2, financeiro 2, RH 1, diretoria 1); VLAN20 = 24 (publicação 8, suporte 2, roteiro 8, pesquisa 6); VLAN30 = 16 (edição 10, design 4, áudio 2); VLAN40 = 4 (TI). Total = 50. O perfil de hardware OP inclui TI, mas a segmentação de rede de TI é separada.

**Nota de capacidade:** a VLAN30 reserva somente 16 concessões para 16 estações criativas, sem folga no pool .10–.25. Antes da implantação ampliar para .10–.29 ou separar Wi-Fi corporativo de dispositivos móveis em VLAN própria; a sub-rede tem no máximo 30 endereços utilizáveis e não comporta expansão ilimitada.

## Matriz mínima de firewall (origem → destino)
| Origem | Destino | Serviço | Política | Razão |
|---|---|---|---|---|
| VLAN70 | Internet | DNS/HTTPS/HTTP autorizados | Permitir com NAT | acesso de visitantes |
| VLAN70 | Redes 10.50.0.0/16 | Qualquer | Negar e registrar | isolamento |
| VLAN10 | Servidores autorizados | DNS/HTTPS/SMB conforme função | Permitir específico | trabalho administrativo |
| VLAN20 | VM-APP01, VM-ID01 | HTTPS/DNS/autenticação | Permitir específico | produção de roteiros/publicação |
| VLAN30 | VM-FILES01 e VM-ID01 | SMB, DNS, autenticação | Permitir específico | projetos criativos |
| VLAN40 | Administração por jump host | SSH/HTTPS/RDP apenas quando necessário | Permitir com MFA/logs | suporte restrito |
| VLAN60 | VM-MON01 | Telemetria futura homologada | Negado até implantação do sensor conectado | Arduino do trabalho NÃO usa rede |
| VLAN80 | Servidor de impressão e gestão autorizada | Portas documentadas | Permitir específico | impressão |
| Qualquer VLAN de usuário | VLAN90 | Gerenciamento | Negar exceto jump host | proteção dos switches/APs |
| Demais inter-VLAN | Qualquer | Não autorizado | Negar por padrão | menor privilégio |

O isolamento é efetivo somente se firewall/ACLs controlarem **todos** os caminhos entre VLANs; roteamento no core L3 sem ACL pode contornar o firewall. Escolher topologia L3 com ACLs no core **ou** encaminhar tráfego inter-VLAN ao firewall, documentando a escolha.

## DHCP, DNS e reservas
VM-NET01 oferece DHCP com relay (ip helper-address no gateway/SVI, se aplicável). VM-ID01 oferece DNS interno, com encaminhadores de confiança. Reservar estáticos para infraestrutura e VMs; registrar IP por hostname e impedir conflitos. DHCP de visitantes não deve anunciar DNS privado corporativo.

## Segurança Wi-Fi
SSID DarkFrame-Corp: autenticação 802.1X/RADIUS após implantação do serviço e certificado. SSID DarkFrame-Guest: VLAN70, isolamento entre clientes e das VLANs privadas. Necessária validação presencial de cobertura, interferência e canalização antes de fixar posição definitiva dos oito APs.

**Validação pendente:** calcular plano final com simulador/planilha, configurar, verificar comunicação permitida/negada, conferir DHCP e capturar evidências do Packet Tracer.
