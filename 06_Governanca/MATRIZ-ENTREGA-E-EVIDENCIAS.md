# DF-GOV-002 — Matriz de entrega e evidências
**Revisão:** 23/11/2026 | **Prazo:** 27/11/2026 | **Estado:** simulações documentadas, entrega final pendente

| Disciplina | Evidências presentes no GitHub | Pendências / limitações |
|---|---|---|
| Arquitetura (Kaike) | 50 postos (6 ADM, 28 OP, 16 ESP); memorial, critérios de homologação, pesquisa indicativa | SKUs definitivos, compatibilidade por conjunto, alternativas comerciais, cotação integral com frete e licenças, nobreak e infraestrutura |
| Sistemas Operacionais (Guilherme) | Windows 11 Pro e Ubuntu Server 24.04 LTS planejados; catálogo de 6 VMs, permissões e backup | Versão/release, hipervisor, identidade, direitos de licença, custos, recuperação testada se exigida |
| Redes (Willian) | [Arquivo .pkt](../04_Redes/DarkFrame_topologia.pkt), [captura](../04_Redes/evidencias/DarkFrame_topologia.png), documentação de 4 pisos, 9 VLANs e relatório de montagem | Lógica VLAN/IPv4, DHCP, roteamento e ACLs são conceituais; não alegar testes de tráfego; aceite de portas/PoE depende de modelo comercial |
| IoT (Guilherme) | [Código](../05_IoT/monitor_tmp36.ino), [testes 24/29/35 °C](../05_IoT/PROTOCOLO-DE-TESTES.md), 3 imagens em `05_IoT/evidencias/` e [link Tinkercad](https://www.tinkercad.com/things/9YpYYnOT4nK-darkframe-monitor-tmp36?sharecode=IinUTfr2kZB4kWGQIVWQxDl-odx-CBLEJG6nf4tWruU) | Somente simulação; sem hardware físico. O circuito não foi integrado à rede e VLAN 60 fica reservada |
| Entrega (equipe) | Resumo, roteiro e arquivos de suporte | PDF acadêmico privado final, URL do vídeo e envio ao professor |

## Checklist de aceite revisado
- [x] Total de 50 funcionários e distribuição em 4 andares documentados
- [x] Código do sensor TMP36 disponibilizado
- [x] Teste Tinkercad 24 °C documentado com captura
- [x] Teste Tinkercad 29 °C documentado com captura
- [x] Teste Tinkercad 35 °C documentado com captura
- [x] Link do circuito Tinkercad publicado
- [x] Arquivo nativo `.pkt` e captura do Packet Tracer publicados
- [ ] Compatibilidade e preço final de todos os componentes homologados
- [ ] Licenciamento e custos consolidados; validações operacionais documentadas
- [ ] PDF final identificado para entrega privada
- [ ] Vídeo publicado com link acessível
- [ ] Conferência final e submissão acadêmica

## Critérios e riscos
- O registro da equipe relata 77 dispositivos e 76 enlaces no Packet Tracer 9.0.1. A existência do arquivo e da imagem foi conferida no GitHub; testes completos de rede **não estão documentados**.
- No Tinkercad, medições registradas: 24 °C configurados / 23,8 °C medidos; 29 °C / 29,2 °C; 35 °C / 35,0 °C.
- Orçamento de **R$ 332.059,70** refere-se a preços indicativos parciais, **não** ao CAPEX integral. Não misturar com a antiga estimativa de R$ 728.200,00.
- Não publicar identificação acadêmica sensível (RAs) no GitHub público.
