# DF-RED-005 — Kit de montagem Cisco Packet Tracer (configuração de referência)
**Status:** comandos preparados para copiar e adaptar. **Não é um arquivo `.pkt` e não foi executado no Packet Tracer.**

## Decisão de arquitetura para o protótipo
Para simplificar a montagem didática, CORE-DF é um switch L3 que hospeda os gateways das nove VLANs. O firewall é a borda de Internet. A ACL `ACL-GUEST-IN` protege visitantes no core. **As demais regras de menor privilégio ainda precisam de ACLs específicas no core ou de arquitetura alternativa com roteamento inter-VLAN no firewall.** Não alegar isolamento geral porque as VLANs existem.

## Endereços de serviços reservados (propostos)
| Servidor | IP | Função |
|---|---|---|
| VM-ID01 | 10.50.50.2/27 | identidade/DNS |
| VM-NET01 | 10.50.50.3/27 | DHCP/NTP |
| VM-FILES01 | 10.50.50.4/27 | arquivos |
| VM-APP01 | 10.50.50.5/27 | portal editorial |
| VM-MON01 | 10.50.50.6/27 | monitoramento |
| VM-BKP01 | 10.50.50.7/27 | orquestração de cópias |
| Gateway servidores | 10.50.50.1/27 | CORE-DF |

## Montagem passo a passo
1. Abrir Cisco Packet Tracer e criar projeto novo `DarkFrame_topologia.pkt`.
2. Adicionar switch L3 compatível, quatro switches de acesso, equipamento WAN, seis servidores representativos, computadores por piso e oito APs; identificar as portas reais.
3. Criar VLANs 10–90 no core e nos switches. Inserir comandos de [CORE-DF-BASE.txt](CORE-DF-BASE.txt), **adaptando** as interfaces conforme o switch escolhido.
4. Ligar uplinks dos switches ao core como trunk e permitir apenas as VLANs necessárias em cada pavimento. Distribuir as portas das estações nas VLANs correspondentes (ADM 6, OP 24, CRIATIVO 16, TI 4). APs deverão suportar SSIDs/VLANs no modelo utilizado; declarar limitações da versão do Packet Tracer.
5. Configurar VM-ID01 (DNS) e VM-NET01 (DHCP) com escopos:
   - VLAN 10: `10.50.10.10–25`, gateway `.1`.
   - VLAN 20: `10.50.20.10–55`, gateway `.1`.
   - VLAN 30: `10.50.30.10–25`, gateway `.1`.
   - VLAN 40: `10.50.40.10–24`, gateway `.1`.
   - VLAN 70: `10.50.70.10–55`, gateway `.1`, **DNS público**, não `10.50.50.2`.
   - No Packet Tracer, o servidor DHCP simulado pode não suportar todos os recursos de um Linux real; documentar diferenças.
6. Conferir SVI `up/up`, trunks, criação dos pools DHCP e mapeamento de endpoints antes de testar.
7. Executar comandos `show vlan brief`, `show interfaces trunk`, `show ip interface brief`, `show ip route`, `show access-lists`. Guardar saída/captura no GitHub.
8. Testes recomendados: IP automático nas VLANs 10, 20, 30 e 70; acesso de visitante a um IP interno deve falhar; acesso corporativo permitido deve funcionar conforme ACL; DNS e serviço editorial em casos com serviços configurados.
9. Salvar o arquivo `.pkt`, reabrir e guardar captura da topologia. Marcar cada teste como aprovado/reprovado **somente depois de executado**.

## Exemplos por switch de piso
Sintaxe orientativa Cisco IOS, conferir interfaces:
```text
enable
configure terminal
hostname SW-A1
vlan 10
vlan 20
vlan 70
vlan 80
! exemplo de uma estação da recepção
interface fastEthernet0/1
 switchport mode access
 switchport access vlan 10
 spanning-tree portfast
! uplink de exemplo; verificar nome real
interface gigabitEthernet0/1
 switchport mode trunk
 switchport trunk allowed vlan 10,20,70,80
end
write memory
```

## Pendências de engenharia
- Trunk 10Gb/s é referência de arquitetura real; modelos comuns do simulador podem oferecer somente 1Gb/s.
- A VLAN 60 é reservada: o Arduino do Tinkercad não participa da rede.
- Uplinks, PoE, cabeamento, potência e modelos comerciais ainda exigem conferência/cotação.
- Não transformar os comandos de demonstração em prova de configuração homologada.
