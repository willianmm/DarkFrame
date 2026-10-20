# DarkFrame Studios — Infraestrutura Computacional (v3.0)

**Estado:** projeto técnico e acadêmico em desenvolvimento. A empresa é fictícia; equipamentos, servidores e redes descritos não foram implantados.

**Repositório oficial:** https://github.com/willianmm/DarkFrame

## Escopo
Infraestrutura proposta para empresa de produção e administração de canais do YouTube, com **50 funcionários em um único edifício de quatro pavimentos**. Abrange Arquitetura de Computadores, Sistemas Operacionais, Redes e IoT.

## Documentação principal (v3.0)
| Pasta | Conteúdo |
|---|---|
| [01_Relatorio](01_Relatorio) | Memorial e relatório técnico |
| [02_Arquitetura](02_Arquitetura) | Perfis dos 50 postos, compatibilidade, servidores, RAID e orçamento |
| [03_Sistemas_Operacionais](03_Sistemas_Operacionais) | Serviços, permissões, proteção e recuperação |
| [04_Redes](04_Redes) | Plantas conceituais, VLANs, IPv4 e topologias |
| [05_IoT](05_IoT) | Protótipo Arduino com TMP36 e roteiro de testes |
| [06_Governanca](06_Governanca) | Riscos, critérios de aceite, pendências e responsáveis |
| [07_Referencias](07_Referencias) | Fontes e documentação de suporte |

## Pastas legadas
As pastas `02_Planejamento`, `03_Redes`, `04_IoT` e `05_Governanca` correspondem a versões anteriores e **não são a referência oficial da v3.0**. Permanecem no repositório até revisão e eventual arquivamento. Ver [auditoria de publicação](06_Governanca/AUDITORIA_PUBLICACAO_2026-10-20.md).

## Pendências de comprovação
- Elaborar/validar a topologia nativa no **Cisco Packet Tracer** (`.pkt`) e guardar suas evidências.
- Executar no **Tinkercad** o circuito TMP36 + Arduino e registrar resultados de **24 °C, 29 °C e 35 °C** com capturas do circuito e Monitor Serial.
- Homologar hardware e compatibilidade por modelo, reunindo referências e **cotações datadas** de fornecedores. Totais atuais são apenas estimativas.
- Conferir licenças, garantias, capacidades de armazenamento, backup e recuperação.
- Preparar vídeo final e inserir o URL na entrega acadêmica.

**Privacidade:** nomes completos e RAs dos integrantes pertencem à documentação acadêmica privada; não publicar a pasta `ENTREGA_PRIVADA` nem credenciais, tokens ou backups reais.

**Data de entrega prevista no enunciado:** 27/11/2026.
