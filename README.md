# DarkFrame Studios — Infraestrutura Computacional (v3.0)

**Estado:** projeto técnico e acadêmico em fase de fechamento. A empresa é fictícia; equipamentos, servidores e redes descritos não foram implantados em ambiente físico.

**Repositório oficial:** https://github.com/willianmm/DarkFrame

## Escopo
Infraestrutura proposta para produção e administração de canais no YouTube, com **50 funcionários em um edifício de quatro andares**. Disciplinas: Arquitetura de Computadores, Sistemas Operacionais, Redes e IoT.

## Documentação principal
| Pasta | Conteúdo |
|---|---|
| [01_Relatorio](01_Relatorio) | Resumo executivo, estrutura de PDF, apresentação e instruções de submissão |
| [02_Arquitetura](02_Arquitetura) | Perfis dos 50 postos, pesquisa de preços, homologação e custos |
| [03_Sistemas_Operacionais](03_Sistemas_Operacionais) | Serviços, licenças, permissões, segurança e recuperação |
| [04_Redes](04_Redes) | Plantas, VLANs, IPv4, [topologia nativa Packet Tracer](04_Redes/DarkFrame_topologia.pkt) |
| [05_IoT](05_IoT) | Código, memorial e evidências Tinkercad |
| [06_Governanca](06_Governanca) | Critérios de aceite e matriz atualizada de pendências |
| [07_Referencias](07_Referencias) | Fontes de apoio |

## Evidências práticas já publicadas
**Packet Tracer:** [arquivo editável](04_Redes/DarkFrame_topologia.pkt), [captura dos quatro andares](04_Redes/evidencias/DarkFrame_topologia.png), [registro técnico](04_Redes/ROTEIRO-PACKET-TRACER.md). O registro da equipe indica montagem e abertura no Packet Tracer 9.0.1. VLANs, ACLs, DNS e DHCP não estão demonstrados como configurados, conforme o roteiro.

**Tinkercad:** [código Arduino](05_IoT/monitor_tmp36.ino), [protocolo de testes](05_IoT/PROTOCOLO-DE-TESTES.md) e capturas [24 °C](05_IoT/evidencias/teste-24c.png), [29 °C](05_IoT/evidencias/teste-29c.png), [35 °C](05_IoT/evidencias/teste-35c.png). [Abrir circuito compartilhado](https://www.tinkercad.com/things/9YpYYnOT4nK-darkframe-monitor-tmp36?sharecode=IinUTfr2kZB4kWGQIVWQxDl-odx-CBLEJG6nf4tWruU). As leituras registradas foram 23,8 °C, 29,2 °C e 35,0 °C, respectivamente; são resultados em simulador, não em hardware físico.

## Pendências reais de fechamento
1. Completar/homologar equipamentos e orçamento integral, incluindo servidores, rede, gabinetes, fontes e DDR5; confirmar fornecedor, SKU, garantia, frete, data e preço.
2. Conferir versões, modelo de licenças, custos e eventual teste de recuperação. Não afirmar implantação de serviços ou backup sem evidência.
3. Gravar e publicar o vídeo final; inserir URL no PDF e conferir acesso sem login.
4. Personalizar a **cópia privada** do PDF com identificação acadêmica exigida e submetê-la no canal oficial.


## Revisão técnica e financeira — 23/11/2026
- [Matriz de compatibilidade da arquitetura](02_Arquitetura/HOMOLOGACAO-MATRIZ-2026-11-23.md): confirma plataformas AMD/placas em documentação oficial e destaca QVL, limites NAS e homologação pendente.
- [Controle de orçamento e itens a cotar](02_Arquitetura/ORCAMENTO-BASE-E-ITENS-A-COTAR-2026-11-23.md): concilia o subtotal parcial sem inventar preços ausentes.
- [Decisão de sistemas e licenciamento](03_Sistemas_Operacionais/DECISAO-PLATAFORMA-E-LICENCIAMENTO-2026-11-23.md): proposta Proxmox VE, Ubuntu Server 24.04 LTS, Samba AD e Windows 11 Pro com condições de aceite.
- Planilha XLSX de controle foi gerada para revisão e preenchimento pela equipe; **não está anexada automaticamente ao repositório**.

## Pastas legadas
`02_Planejamento`, `03_Redes`, `04_IoT` e `05_Governanca` contêm versões anteriores; usar as pastas da estrutura v3.0 acima como referência.

**Privacidade:** não publicar RAs, credenciais, dados pessoais de participantes ou pasta `ENTREGA_PRIVADA` no repositório aberto.  
**Entrega prevista:** 27/11/2026.
