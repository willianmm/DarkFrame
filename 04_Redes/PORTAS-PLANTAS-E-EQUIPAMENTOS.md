# DF-RED-003 — Dimensionamento físico por andar
**Revisão:** 1.0 | **Status:** estimativa de pontos, sujeita a vistoria e levantamento de instalações.

## Quantidades em projeto
| Andar | Departamentos | Estações cabeadas | AP PoE | Impressoras previstas | Porta de acesso estimada | Switch proposto | Portas livres estimadas |
|---|---|---:|---:|---:|---:|---|---:|
| 1 | Recepção (2), Publicação (8), Suporte (2) | 12 | 2 | 1 | 15 | 48p PoE | 33 |
| 2 | Roteirização (8), Pesquisa (6) | 14 | 2 | 1 | 17 | 48p PoE | 31 |
| 3 | Edição (10), Design (4), Áudio (2) | 16 | 2 | 1 | 19 | 48p PoE | 29 |
| 4 | TI (4), Financeiro (2), RH (1), Diretoria (1) | 8 | 2 | 1 | 11 | 24p PoE | 13 |
| **Total** | **50 colaboradores** | **50** | **8** | **4** | **62** | **168 portas brutas** | **106** |

**Premissas:** cada estação usa uma porta RJ-45; impressora e AP usam uma porta cada. Uplinks de fibra usam interfaces SFP/SFP+ dedicadas nos switches propostos e por isso não consomem portas RJ-45 do cálculo. Não foram contabilizados telefones IP, pontos de redundância, NAS, host, gestão central ou IoT cabeado; esses devem ser contados no rack/core com inventário separado. O total de portas livres não é uma validação de portas PoE disponíveis nem do orçamento de potência dos APs.

## Backbone e equipamentos
- 2 operadoras independentes, com confirmação de entrada física e SLA; firewall dual-WAN com disponibilidade planejada.
- 1 switch central L3 gerenciável, capacidade de uplink **mínima proposta 10 Gb/s por andar** e conectividade de servidores/NAS também a 10 Gb/s.
- 3 switches de acesso gerenciáveis de 48 portas PoE; 1 switch de 24 portas PoE; 8 APs 802.11ax; 4 impressoras de rede (proposta).
- Backbone vertical em fibra óptica com identificação de DIO e fusões; rede horizontal Cat6 (categoria e comprimento final após levantamento). Dimensionar caminhos, eletrocalhas, patch panels, racks e PoE segundo normas e desenhos arquitetônicos.
- Core e servidor no 4º andar em sala protegida, com inventário separado de portas ocupadas no core e patch panels. Links duplicados e redundância elétrica são opção técnica a cotar, não entregues.

## Capacidade versus demanda
O maior volume de tráfego vem do 3º andar. O uplink 10Gb/s e acesso cabeado 1Gb/s são escolhas iniciais, mas a edição simultânea sobre o NAS pode exigir 2,5GbE/10GbE nas estações criativas e storage com IOPS adicionais. Estimar bitrate, transferências simultâneas e tempo de upload para verificar. Para os links de Internet, medir horas de pico e calcular fluxo de upload: `tempo = bytes de mídia / taxa útil de upload`. A quantidade de 8 APs será confirmada por site survey.

## Plano de identificação
Estações: `PT-A1-001...012`, `PT-A2-001...014`, `PT-A3-001...016`, `PT-A4-001...008`. APs: `AP-A{andar}-01/02`. Impressoras: `IMP-A1` a `IMP-A4`. Uplinks: `FO-CORE-A{andar}-01`. Documentar rack, patch panel, porta, cabo, destino, VLAN e ocupação.

## Pontos nas plantas
- Andar 1: PT-A1-001 a 012, AP-A1-01/02, IMP-A1, switch SW-A1.
- Andar 2: PT-A2-001 a 014, AP-A2-01/02, IMP-A2, switch SW-A2.
- Andar 3: PT-A3-001 a 016, AP-A3-01/02, IMP-A3, switch SW-A3.
- Andar 4: PT-A4-001 a 008, AP-A4-01/02, IMP-A4, switch SW-A4, core e sala de servidores.

**Importante:** plantas conceituais existentes no repositório não substituem medição de área, cotas, rota de cabos ou verificação da posição real dos APs. Nenhum modelo comercial de switch, firewall ou nobreak está homologado sem SKU, preço, energia, garantia e suporte.
