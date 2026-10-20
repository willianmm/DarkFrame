# DF-ARC-002 — Homologação técnica de estações e armazenamento
**Revisão:** 1.0 — 20/10/2026  
**Referência:** [MEMORIAL-TECNICO.md](MEMORIAL-TECNICO.md)  
**Natureza:** projeto preliminar com especificações verificadas em fabricantes; não representa compra, teste de montagem nem implantação.

## 1. Consolidação de demanda
| Perfil | Departamentos | Estações | CPU de referência | RAM | Armazenamento local |
|---|---|---:|---|---|---|
| ADM | Recepção, Financeiro, RH, Diretoria | 6 | Ryzen 5 5600G | 16 GB DDR4 | 500 GB NVMe |
| OP | Publicação, Suporte, Roteirização, Pesquisa, TI | 28 | Ryzen 5 5600G | 32 GB DDR4 | 1 TB NVMe |
| ESP | Edição, Design e Áudio | 16 | Ryzen 7 7700 + RTX 4060 | 64 GB DDR5 | 2 TB NVMe |
| **Total** | | **50** | | | |

Para capacidade local nominal, 6×0,5 + 28×1 + 16×2 = **63 TB** de SSD em todas as estações. Não é armazenamento compartilhado nem backup. Para a edição, todo arquivo de projeto deve ser sincronizado ao storage corporativo segundo as políticas de trabalho.

## 2. Verificação fundamentada em fabricantes
| Item | Evidência do fabricante | Consequência para homologação |
|---|---|---|
| Ryzen 5 5600G | Soquete AM4, DDR4 até 3200 MT/s, 65 W, GPU Radeon integrada, PCIe 3.0 | Placa-mãe precisa ser AM4 com BIOS compatível; RAM DDR4; conferir uso de M.2 e saídas de vídeo |
| Ryzen 7 7700 | Soquete AM5, DDR5, 65 W; suporta DDR5-5200 em 2 módulos conforme topologia indicada | Placa-mãe AM5/B650 de modelo exato, kit DDR5 validado, BIOS e VRM apropriados |
| RTX 4060 | 8 GB GDDR6, AV1 encode, TGP de referência 115 W, sistema recomendado 550 W | Fonte proposta 650 W oferece margem nominal, mas cabo PCIe, potência real, dissipação e gabinete exigem verificação por SKU |
| Armazenamento em rede | 4×12 TB em RAID 6 = 24 TB nominais úteis | Reservar ~20%: 19,2 TB nominais para planejamento; snapshots, sistema de arquivos e unidades TiB diminuem o valor disponibilizado |

**Fontes (consultadas em 20/10/2026):**
- AMD 5600G: https://www.amd.com/pt/support/downloads/drivers.html/processors/ryzen/ryzen-5000-series/amd-ryzen-5-5600g.html
- AMD Ryzen 7 7700: https://www.amd.com/pt/products/processors/desktops/ryzen/7000-series/amd-ryzen-7-7700.html
- NVIDIA RTX 4060: https://www.nvidia.com/pt-br/geforce/graphics-cards/40-series/rtx-4060-4060ti/

## 3. Matriz de compatibilidade a preencher antes da compra
| Verificação obrigatória | ADM | OP | ESP | Evidência necessária |
|---|---|---|---|---|
| Modelo e revisão exata da placa-mãe | Pendente | Pendente | Pendente | URL e ficha oficial |
| Soquete e suporte de BIOS à CPU | Pendente | Pendente | Pendente | CPU support list/versão mínima |
| Kit de RAM, capacidade, frequência e QVL | Pendente | Pendente | Pendente | Manual e QVL |
| SSD M.2: chave, formato, pista e slots | Pendente | Pendente | Pendente | Manual e dados do SSD |
| Saídas de vídeo e monitores | Pendente | Pendente | Pendente | Portas e resoluções |
| Fonte: potência, proteções e conectores | Pendente | Pendente | Pendente | SKU, manual e consumo calculado |
| Gabinete: formato e espaço físico | Pendente | Pendente | Pendente | Dimensões e airflow |
| Windows 11: TPM 2.0 / Secure Boot | Pendente | Pendente | Pendente | Firmware e requisitos do sistema |
| Garantia e suporte local | Pendente | Pendente | Pendente | Termos do fabricante |

**Bloqueio de aceite:** não usar “compatível” como resultado final até fechar todas as linhas por SKU. Uma família de chipsets (B550/B650) não é modelo completo.

## 4. Memória, produção e armazenamento
- 50 colaboradores, 50 postos e **16 estações criativas**: validar codecs, efeitos e resolução no software escolhido; a RTX 4060 com 8 GB não está automaticamente homologada para toda produção 4K/6K.
- NAS em RAID 6: resistência à falha simultânea de até dois discos, mas não protege contra exclusões, ransomware ou incêndio. Implementar backup isolado e externo.
- Estimar espaço a partir de uma amostra de projetos: tamanho bruto por vídeo × vídeos simultâneos × versões e retenção; comparar com 19,2 TB disponíveis para produção após reserva.
- 1 host de virtualização significa ponto único de falha. Definir RPO/RTO com negócio antes de aceitar ou exigir segundo host.

## 5. Duas decisões em aberto
**Estação criativa:** manter Ryzen 7 7700 + RTX 4060 como referência A e comparar com uma configuração B cotada de outro fabricante/plataforma; usar um pequeno teste de exportação e critérios de codec, tempo, consumo, garantia e preço.

**Servidor:** comparar (A) host único + NAS + recuperação versus (B) dois hosts com HA + NAS + backup externo. A opção B só se justifica se RTO de negócio exigir menor indisponibilidade.

## 6. Gates de aceitação
- 50 estações distribuídas por departamento, quantidades fechadas.
- Todos os componentes com fabricante, SKU, revisão, URL, garantia e evidência de compatibilidade.
- Pelo menos duas alternativas para perfil criativo e servidor.
- Orçamento por item com fornecedor, preço, URL, data e subtotal; licenças separadas de CAPEX.
- Estratégia de armazenamento com RAID, capacidade e restauração documentadas.
- Aprovação do grupo antes de transformar estimativa em proposta comercial.

**Situação atual:** especificações gerais dos três componentes centrais confirmadas em fontes oficiais; homologação de sistemas completos e preço comercial **pendentes**.
