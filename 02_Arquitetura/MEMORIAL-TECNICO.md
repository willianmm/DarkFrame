# Memorial técnico de arquitetura — DF-ARC-001, revisão 3.0

**Escopo:** 50 estações, 4 pisos, ambientes audiovisuais, servidores e armazenamento. **Status:** especificação preliminar para homologação; não é proposta comercial.

## Mapa de postos

| Piso | Departamento | Pessoas | Perfil | Principal demanda |
|---|---|---:|---|---|
| 1 | Recepção | 2 | ADM | navegação, sistemas web e produtividade |
| 1 | Publicação | 8 | OP | navegação, sistemas web e produtividade |
| 1 | Suporte aos canais | 2 | OP | navegação, sistemas web e produtividade |
| 2 | Roteirização | 8 | OP | navegação, sistemas web e produtividade |
| 2 | Pesquisa e análise | 6 | OP | navegação, sistemas web e produtividade |
| 3 | Edição de vídeo | 10 | ESP | edição, renderização, áudio profissional |
| 3 | Design | 4 | ESP | edição, renderização, áudio profissional |
| 3 | Áudio | 2 | ESP | edição, renderização, áudio profissional |
| 4 | TI | 4 | OP | navegação, sistemas web e produtividade |
| 4 | Financeiro | 2 | ADM | navegação, sistemas web e produtividade |
| 4 | RH | 1 | ADM | navegação, sistemas web e produtividade |
| 4 | Diretoria | 1 | ADM | navegação, sistemas web e produtividade |


**Fechamento:** ADM 6 + OP 28 + ESP 16 = 50 dispositivos. Alocar um equipamento a cada colaborador; estações compartilhadas ou móveis só mediante revisão do inventário.

## Perfis com referência de componentes (alternativas a homologar)

| Componente | ADM — 6 | OP — 28 | ESP — 16 |
|---|---|---|---|
| Processador | AMD Ryzen 5 5600G | AMD Ryzen 5 5600G | AMD Ryzen 7 7700 |
| Placa-mãe | B550 / soquete AM4, modelo comercial a confirmar | B550 / AM4, modelo comercial a confirmar | B650 / AM5, modelo comercial a confirmar |
| Memória | 2×8 GB DDR4-3200 | 2×16 GB DDR4-3200 | 2×32 GB DDR5-5200 |
| SSD primário | NVMe 500 GB | NVMe 1 TB | NVMe 2 TB |
| Vídeo | Radeon integrada | Radeon integrada | NVIDIA RTX 4060 8 GB (edição e codecs sujeitos a homologação) |
| Fonte | 450 W 80 Plus | 500 W 80 Plus | 650 W 80 Plus com cabos PCIe compatíveis |
| Monitor | 24 pol. IPS | 24 pol. IPS | 27 pol. IPS QHD, calibrável |
| Rede | 1 GbE | 1 GbE | 1 GbE / 2.5 GbE onde compatível |
| Sistema | Windows 11 Pro 64 bits | Windows 11 Pro 64 bits | Windows 11 Pro 64 bits |

**Compatibilidade:** 5600G exige plataforma AM4 e DDR4; 7700 exige AM5 e DDR5. Confirmar na página específica da placa-mãe a revisão de BIOS, módulos aceitos, VRM, quantidade de portas M.2, fTPM 2.0 e Secure Boot. Verificar comprimento da GPU, conectores da fonte, altura do cooler, dimensões do gabinete, assistência e garantia. Nenhuma combinação está homologada sem SKUs de todos os itens.

## Servidores e armazenamento

- 1 host rack com 12 a 16 núcleos de CPU server-grade, 128 GB de RAM ECC, 2 SSD de 960 GB em espelhamento para hipervisor, 2 interfaces 10 GbE, fontes redundantes. **CPU, placa/chassi, controladora e licença do hipervisor ainda exigem SKU**.
- 1 NAS dedicado, 4 HDD de 12 TB em RAID 6: **48 TB brutos e 24 TB úteis nominais**, antes de formatação, snapshots e reserva. Usar 20% de reserva: ~19,2 TB para planejamento. Alternativa: RAID 10 resulta em 24 TB úteis nominais, com perfil diferente de escrita e tolerância de falhas; apresentar decisão segundo RPO/RTO e custo.
- RAID não substitui backup. Prever cópia local isolada e cópia externa criptografada, testadas; proteger mídia final, roteiros, licenças, credenciais em cofre e arquivos administrativos.
- Nobreak online com autonomia dimensionada por consumo medido, curva do fabricante e desligamento controlado. Prever alimentação elétrica, ar condicionado, terra, incêndio e sala restrita.

## Alternativas e decisão

| Decisão | Opção A | Opção B | Critério |
|---|---|---|---|
| Estação criativa | Ryzen 7 7700 + RTX 4060 | CPU intermediária + gráficos integrados | Escolha A quando codecs, render e memória de GPU demandarem; validar com prova de render |
| Servidores | 1 host + NAS + backup | 2 hosts em HA + NAS + backup | A tem menor CAPEX e ponto único de falha; B melhora continuidade com custo maior; decisão sujeita a RTO |

**Critérios de aceite:** matriz de SKU e compatibilidade concluída, inventário 50/50, 2 propostas comparadas por categoria crítica, preços com URL e data, 20% de capacidade livre e comprovação de backup/restauração.
