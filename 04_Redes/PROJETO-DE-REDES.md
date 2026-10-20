# Projeto de redes — DF-RED-001

**Topologia física proposta:** 2 circuitos de operadoras distintas → firewall de borda → switch L3 central → uplinks de fibra 10 Gb/s até quatro switches de acesso por piso → estações/APs/impressoras. VLANs interligadas somente via firewall/ACL. Monitorar disponibilidade e ocupar <= 80% das portas. **Não há evidência de implantação física ou arquivo .pkt gerado.**

## Endereçamento IPv4 e VLANs

| VLAN | Função | Rede | Máscara | Gateway | DHCP/reservas | Broadcast |
|---:|---|---|---|---|---|---|
| 10 | ADMIN | 10.50.10.0/27 | 255.255.255.224 | 10.50.10.1 | 10.50.10.10–10.50.10.25 | 10.50.10.31 |
| 20 | OPERACIONAL | 10.50.20.0/26 | 255.255.255.192 | 10.50.20.1 | 10.50.20.10–10.50.20.55 | 10.50.20.63 |
| 30 | CRIATIVO | 10.50.30.0/27 | 255.255.255.224 | 10.50.30.1 | 10.50.30.10–10.50.30.25 | 10.50.30.31 |
| 40 | TI | 10.50.40.0/27 | 255.255.255.224 | 10.50.40.1 | 10.50.40.10–10.50.40.24 | 10.50.40.31 |
| 50 | SERVIDORES | 10.50.50.0/27 | 255.255.255.224 | 10.50.50.1 | estático .2–.25 | 10.50.50.31 |
| 60 | IOT | 10.50.60.0/27 | 255.255.255.224 | 10.50.60.1 | estático/reserva .10–.25 | 10.50.60.31 |
| 70 | VISITANTES | 10.50.70.0/26 | 255.255.255.192 | 10.50.70.1 | 10.50.70.10–10.50.70.55 | 10.50.70.63 |
| 80 | IMPRESSAO | 10.50.80.0/27 | 255.255.255.224 | 10.50.80.1 | reservas .10–.25 | 10.50.80.31 |
| 90 | GERENCIA | 10.50.90.0/27 | 255.255.255.224 | 10.50.90.1 | estático .2–.25 | 10.50.90.31 |


Sub-redes /27 possuem 30 hosts utilizáveis e /26 possuem 62. Somente a VLAN operacional precisa acomodar 28 postos, adicionais por Wi-Fi e expansão; os intervalos foram reservados em cada rede sem sobreposição. Os IPs estáticos usam faixas fora do DHCP efetivamente configurado.

## Matriz mínima de acessos

| Origem | Destino | Decisão | Motivação |
|---|---|---|---|
| Visitantes VLAN70 | Internet via NAT | permitir DNS/HTTP/HTTPS | navegação isolada |
| Visitantes VLAN70 | todas as RFC1918 internas | negar | separação de convidados |
| IoT VLAN60 | monitoramento VLAN50 | permitir somente serviço monitorado | telemetria |
| IoT VLAN60 | Financeiro/AD | negar | reduzir superfície |
| Criativo VLAN30 | compartilhamentos da própria equipe em VLAN50 | permitir SMB autenticado | edição colaborativa |
| Operacional VLAN20 | serviços web/dados autorizados em VLAN50 | permitir por porta | operação |
| TI VLAN40 | interfaces de gestão, via bastion e MFA | permitir auditado | suporte |
| Demais setores | VLAN90 gerência | negar | controles de infraestrutura |

## Dimensionamento físico inicial

| Piso | Funcionários | Switch | APs | Reservas |
|---|---:|---|---:|---|
| 1 | 12 | 1×48 portas PoE | 2 | + impressoras, telefones e crescimento |
| 2 | 14 | 1×48 portas PoE | 2 | + impressoras, telefones e crescimento |
| 3 | 16 | 1×48 portas PoE | 2 | + periféricos criativos e crescimento |
| 4 | 8 | 1×24 portas PoE | 2 | + IoT, gestão e servidores (core separado) |

**Portas brutas de acesso:** 168. Contar uplinks, portas consumidas por AP, impressoras e endpoints; a alocação física será validada em planta e tabela de portas. Conduíte/cabos Cat6 horizontal com enlaces de fibra entre pavimentos, patch panels identificados, racks ventilados, energia estabilizada. APs 802.11ax com SSIDs `DarkFrame-Corp` (802.1X, RADIUS) e `DarkFrame-Guest` (portal ou WPA com isolamento); um SSID opcional de dispositivos operacionais pode ser limitado por ACL. Cobertura e canalização dependem de site survey.

## Packet Tracer: checklist para arquivo nativo

1. Adicionar duas nuvens/roteadores WAN, firewall/roteador de borda, core L3, switches de piso, oito APs, seis VMs representadas por servidores, 50 estações representativas e IoT.
2. Identificar enlaces 10 Gb/s por legenda (se o modelo no simulador não implementar 10G, usar nomenclatura e registrar limitação).
3. Criar VLAN 10–90, gateways e reservas de IP; desenhar isolamento de visitantes e IoT.
4. Salvar `DarkFrame_topologia.pkt`, capturar topologia e tabela lógica. A rubrica exige desenho no Packet Tracer; **não exige configuração ou simulação**, conforme checklist final do professor.
