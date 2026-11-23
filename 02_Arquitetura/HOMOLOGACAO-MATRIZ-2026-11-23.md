# DF-ARC-009 — Matriz de compatibilidade e decisão técnica

**Revisão:** 23/11/2026. **Status:** verificação documental parcial com fontes oficiais. Não representa montagem física, aceite de fornecedor nem homologação de todos os SKUs.

## 1. Três perfis de estação

| Perfil | Qtde | Plataforma | Memória | GPU | Situação de compatibilidade |
|---|---:|---|---|---|---|
| Administrativo | 6 | AMD Ryzen 5 5600G + ASUS TUF GAMING B550M-PLUS (AM4) | Kit 2×8 GB DDR4-3200 | Integrada | **Compatibilidade de plataforma confirmada** por CPU e lista ASUS; revisar BIOS mínima, QVL e gabinete |
| Operacional | 28 | AMD Ryzen 5 5600G + ASUS TUF GAMING B550M-PLUS (AM4) | Kit 2×16 GB DDR4-3200 | Integrada | **Compatibilidade de plataforma confirmada**; revisão de memória, SSD e BIOS ainda necessária |
| Especializado | 16 | AMD Ryzen 7 7700 + MSI PRO B650M-P (AM5) | Kit 2×32 GB DDR5; referência JEDEC-5200 | RTX 4060 8 GB | AM5/DDR5 e slot PCIe x16 compatíveis em classe, **mas kit exato, QVL, fonte e gabinete não homologados** |

### Fontes primárias e comprovações
- AMD Ryzen 5 5600G — plataforma AM4 e DDR4: https://www.amd.com/en/support/downloads/drivers.html/processors/ryzen/ryzen-5000-series/amd-ryzen-5-5600g.html
- ASUS TUF B550M-PLUS — Ryzen 5 5600G na lista de CPU, BIOS mínima indicada 1401: https://www.asus.com/supportonly/tuf%20gaming%20b550m-plus/helpdesk_cpu/
- AMD Ryzen 7 7700 — AM5 e memória oficial DDR5-5200: https://www.amd.com/en/products/processors/desktops/ryzen/7000-series/amd-ryzen-7-7700.html
- MSI PRO B650M-P — DDR5, M.2 e PCIe: https://www.msi.com/Motherboard/PRO-B650M-P/Specification
- Kingston — consulta de memória para placa MSI; módulos de 32/64GB podem exigir atualização de BIOS: https://www.kingston.com/br/memory/search/model/108483/msi-pro-b650m-p-motherboard

## 2. Decisões de arquitetura ainda não homologadas
1. **Memória DDR5:** usar 2×32 GB em dual-channel; DDR5-5200 é referência do CPU. DDR5-5600/XMP/EXPO só após QVL e teste de estabilidade, não presume garantia a 5600 MT/s.
2. **SSD NV3:** formato M.2 2280 previsto; Ryzen 5 5600G pode operar slot em PCIe 3.0 conforme placa/CPU. Verificar TBW, desempenho sustentado e demanda real de edição.
3. **Fonte:** candidatos de 450 W (ADM), 500 W (OP), 650 W (ESP) são classes e não substituem seleção de SKU com proteções, conectores e garantia. Conferir dimensões e ventoinhas do gabinete.
4. **NAS:** DS925+ tem 2×2,5 GbE, não ligação única a 10 GbE. **Decisão provisória:** aceitar limite de 2,5 GbE por porta e documentar gargalo; antes da compra, comparar NAS com suporte verificável a 10 GbE para operações criativas.
5. **Host:** requisitos 128 GB ECC, duas fontes, 10GbE e 2 SSDs espelhados; **não há modelo comercial de servidor homologado**. Os 16 vCPU virtuais são alocação lógica, não exigência de 16 núcleos físicos reservados.
6. **NAS RAID 6:** 4×12TB = 24TB úteis nominais, aproximadamente 19,2TB como alvo de ocupação com reserva de 20%; RAID não equivale a backup.
7. **Nobreak:** dimensionamento não fechado porque watts reais, fator de potência, expansão e autonomia não foram medidos/contratados. Não inventar VA nem autonomia.

Fonte DS925+: https://www.synology.com/en-br/products/DS925%2B

## 3. Condições de aceite comercial
Só carimbar 'HOMOLOGADO' por conjunto após fabricante e SKU exato de cada componente, QVL/BIOS, dimensões, potência e conexões, quantidade de 50 unidades, estoque, garantia e documentação de fornecedor. A plataforma proposta é tecnicamente plausível, mas **a matriz não substitui os testes e a cotação exigidos**.
