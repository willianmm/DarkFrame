# DF-ARC-008 — Reconciliação econômica e homologação (23/11/2026)
**Status:** quadro de aprovação preliminar, com base nos estudos do repositório. Não representa cotação fechada ou compra.

## Subtotais já registrados
| Grupo | Total indicativo em pesquisa | Fonte no repositório |
|---|---:|---|
| CPU, placa-mãe e GPU selecionadas | R$ 159.556,94 | [DF-ARC-004](PESQUISA-PRECOS-2026-11-22.md) |
| SSDs (50 dispositivos) | R$ 74.039,50 | [DF-ARC-005](PESQUISA-SSDS-2026-11-22.md) |
| RAM DDR4 e monitores | R$ 98.463,26 | [DF-ARC-006](PESQUISA-RAM-MONITORES-2026-11-22.md) |
| **Subtotal de componentes pesquisados** | **R$ 332.059,70** | **Não é o orçamento total** |

## Componentes ainda sem valor homologado
| Item | Quantidade / base planejada | Status |
|---|---|---|
| Memória DDR5 64 GB criativa | 16 kits 2×32 GB | Preços históricos em [DF-ARC-007](CANDIDATOS-HARDWARE-E-INFRA-2026-11-22.md); sem cotação atual |
| Fontes ADM/OP/ESP | 50 | Necessário separar por potência, SKU, compatibilidade e garantia |
| Gabinetes e refrigeração | 50 | Candidatos definidos; sem aprovação de orçamento final |
| Periféricos, cabeamento e acessórios por posto | 50 postos | Sem custo final |
| Host corporativo, discos do hipervisor e suporte | 1 | Sem SKU e cotação de fornecedor |
| NAS e 4 HDDs 12 TB | 1 + 4 | Candidato ao NAS; exigir discos certificados, capacidade e compatibilidade de rede |
| Energia/nobreaks, rack, firewall, core, 4 switches, 8 APs, 4 impressoras | Conforme projeto | Cotar SKU, PoE, banda, autonomia e instalação |
| Licenças Windows 11 Pro, ferramentas e hipervisor | 50 estações + 1 host + aplicações | Direitos de uso e CAPEX/OPEX ainda não decididos |
| Backups externos, serviços, energia, suporte e contingência | A dimensionar | OPEX e condições contratuais em aberto |

## Ajustes técnicos antes da aprovação
- **Memória criativa:** o memorial indica DDR5-5200 e uma pesquisa apresentou candidatos DDR5-5600. A capacidade de 64 GB é comum, mas velocidade/perfil e QVL do conjunto AM5/B650 ainda requerem escolha.
- **NAS:** a proposta de backbone/servidores de 10 Gb/s precisa ser reconciliada com o candidato Synology DS925+ indicado com duas interfaces 2,5 GbE. Não anunciar 10 Gb/s no NAS sem solução verificada.
- **RAID 6:** quatro discos de 12 TB fornecem 24 TB úteis nominais antes de formatação/reserva, não cópia de backup independente.
- **Windows e aplicações:** checar licença por equipamento/usuário e evitar contagem duplicada quando a estação já incluir licença OEM.
- **Proposta financeira:** não somar a estimativa antiga R$ 728.200,00 ao subtotal indicativo R$ 332.059,70. A estimativa antiga não equivale a orçamento homologado.

## Regra de fechamento de preços
Cada linha aprovada deve conter **fabricante, SKU exato, quantidade, valor unitário, subtotal, URL individual, fornecedor/vendedor, data e hora, frete, impostos, garantia e disponibilidade para o lote**. Quando isso faltar, manter como `A COTAR`. Não preencher preços por adivinhação.

## Licenças e recuperação
O documento [DF-SO-004](../03_Sistemas_Operacionais/BACKUP-RECUPERACAO-LICENCAS.md) já possui matriz de categorias, mas ainda não produto/contrato e preço final. A restauração de arquivos e VMs é procedimento previsto, não teste comprovado. Entregar essas ressalvas com transparência caso não haja ambiente implantado.
