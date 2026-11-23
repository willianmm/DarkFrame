# DarkFrame Studios — Resumo executivo, revisão de 23/11/2026
**Tipo:** projeto acadêmico de empresa fictícia, sem implantação física.

A DarkFrame Studios foi concebida para produção, edição, publicação e gestão de canais digitais, com **50 funcionários em 4 andares** e 3 perfis de estações: ADM 6, OP 28 e ESP 16.

## Arquitetura e sistemas
O planejamento propõe host corporativo com 128 GB ECC, seis VMs Ubuntu Server 24.04 LTS, NAS com 4 discos de 12 TB em RAID 6 e backups independentes. As estações usam Windows 11 Pro em especificação, mas o licenciamento, releases e serviços de identidade/hipervisor ainda necessitam de decisão formal.

A pesquisa de componentes de 22/11/2026 resultou em **R$ 332.059,70 de subtotal indicativo parcial**; não é o investimento total. A estimativa antiga de R$ 728.200,00 não foi homologada e não pode ser somada ao subtotal.

## Evidências de Redes
Há [arquivo `.pkt`](../04_Redes/DarkFrame_topologia.pkt) e [captura da topologia](../04_Redes/evidencias/DarkFrame_topologia.png) no GitHub. Segundo o roteiro, a topologia foi montada, aberta e salva no Packet Tracer 9.0.1 com 77 dispositivos, 76 enlaces e 50 postos. As nove VLANs, o IPv4 e os controles DHCP/DNS/ACL são planejados, mas não comprovadamente configurados na simulação.

## Evidências de IoT
O circuito Arduino Uno/TMP36 tem [código](../05_IoT/monitor_tmp36.ino), [relatório](../05_IoT/PROTOCOLO-DE-TESTES.md), três imagens e [link compartilhado](https://www.tinkercad.com/things/9YpYYnOT4nK-darkframe-monitor-tmp36?sharecode=IinUTfr2kZB4kWGQIVWQxDl-odx-CBLEJG6nf4tWruU). Os testes reportaram leitura 23,8 °C com LED verde (ajuste 24 °C), 29,2 °C com amarelo (29 °C) e 35,0 °C com vermelho (35 °C). A verificação é simulada, sem equipamento físico instalado.

## Pendências de entrega
- Homologação final de componentes, preços, licenças e limites da solução de backup.
- PDF final de submissão contendo identificação acadêmica **somente na versão privada**, GitHub e link da apresentação.
- Vídeo da equipe ainda não publicado/localizado neste projeto e conferência dos links.

**GitHub:** https://github.com/willianmm/DarkFrame  
**Vídeo:** PENDENTE DE PUBLICAÇÃO  
**Prazo informado:** 27/11/2026.
