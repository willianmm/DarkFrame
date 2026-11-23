# DF-SO-005 — Arquitetura de sistemas e licenciamento proposta

**Revisão:** 23/11/2026. **Natureza:** decisão de projeto acadêmico, sem implantação nem direitos de licença comprados.

## 1. Escolhas consolidadas para orçamento
| Camada | Opção de projeto | Quantidade | Modelo de licença / implicação | Validação residual |
|---|---|---:|---|---|
| Estações | Windows 11 Pro 64 bits | 50 | Licenças válidas por dispositivo, preferencialmente OEM na compra; **não duplicar OEM já incluída** | SKU do PC, fatura/licença, TPM 2.0, UEFI/Secure Boot, drivers |
| Host | Proxmox VE 9.x | 1 | Software AGPLv3 utilizável sem assinatura; **suporte/enterprise repository opcionais e precificados separadamente** | Compatibilidade de hardware, HCL, NIC, armazenamento, escolha de suporte |
| VMs | Ubuntu Server 24.04 LTS 64 bits | 6 | Ubuntu Server instalável sem taxa por VM; Ubuntu Pro/suporte opcional | Versão de imagem e atualizações; termo de suporte |
| Identidade | Samba Active Directory Domain Controller em VM-ID01 | 1 | Software livre; **opção de projeto**, não identidade já implantada | Compatibilidade GPO, ingresso de estação, DNS/Kerberos e login de piloto |
| Backup | Proxmox Backup Server ou solução equivalente com repositório isolado | 1 | Ferramenta a validar; armazenamento fora do NAS produtivo | Capacidade, política 3-2-1, ensaio de restauração e off-site |
| Apps de escritório, criação, segurança | A selecionar por aplicação e usuário | Até 50 / 16 | Licenciamento e custos **a cotar**, sem presumir assinaturas gratuitas | Software específico, termos, custos recorrentes e cobertura EDR |

**Fontes oficiais:** Proxmox AGPLv3 e assinatura: https://www.proxmox.com/en/about/company-details/press-releases/proxmox-virtual-environment-9-0 e https://www.proxmox.com/en/products/proxmox-virtual-environment/pricing ; Microsoft comercial/OEM: https://learn.microsoft.com/pt-br/windows/whats-new/windows-licensing ; Ubuntu 24.04 LTS: https://documentation.ubuntu.com/release-notes/24.04/ ; Samba DC: https://www.samba.org/samba/docs/current/man-html/smb.conf.5.html

## 2. Capacidade e alocação virtual
| VM | vCPU | RAM | Disco virtual inicial | Serviço |
|---|---:|---:|---:|---|
| VM-ID01 | 2 | 8 GB | 100 GB | Samba AD / DNS |
| VM-NET01 | 2 | 4 GB | 80 GB | DHCP / NTP |
| VM-FILES01 | 4 | 16 GB | 160 GB | SMB / ACLs |
| VM-APP01 | 4 | 16 GB | 160 GB | Aplicações editoriais |
| VM-MON01 | 2 | 8 GB | 160 GB | Monitoramento e syslog |
| VM-BKP01 | 2 | 8 GB | 160 GB | Orquestração de cópia, destino externo |
| **TOTAL** | **16** | **60 GB** | **820 GB** | Virtualização planejada |

O host nominal possui 128 GB ECC; os 68 GB restantes são diferença aritmética, não garantia de capacidade útil sem dimensionar overhead, cache e picos. Repositório de backup independente do NAS não deve ser confundido com o disco da VM-BKP01.

## 3. Política de implantação e segurança (proposta)
1. Atualizar firmware do host; instalar Proxmox VE no par de SSDs espelhados; criar administração com MFA e acesso restrito à VLAN de gestão.
2. Implementar segmentação conforme projeto de Redes; criar VM-ID01 com Samba AD e DNS, VM-NET01 com DHCP e horário consistente.
3. Associar máquinas Windows a domínio piloto e testar usuário comum, grupo restrito, impressoras e pastas de edição; documentar GPOs suportadas.
4. Implementar contas de serviço separadas, ACLs, logs e monitoramento; não supor que as ACLs estejam executadas no Packet Tracer.
5. Implementar backup 3-2-1, cópia externa independente, restauração de arquivo e de uma VM de teste; guardar tempos realmente medidos, sem alegar que já ocorreram.
6. Registrar licenças OEM reais e eventual assinatura enterprise; precificar renovação anual e suporte técnico.

## 4. Custos de software — classificação
- Proxmox VE: **R$ 0 de taxa de licença do software básico**; contratação de suporte é despesa opcional e **não foi cotada**.
- Ubuntu Server 24.04 LTS: **R$ 0 de taxa de licença do sistema básico**; suporte Ubuntu Pro opcional.
- Samba AD: **R$ 0 de licença básica do projeto livre**; implantação e suporte não são gratuitos necessariamente.
- Windows 11 Pro: **50 direitos de uso a comprovar** por OEM/contrato, custo por estação **a cotar**.
- EDR, aplicações criativas, produtividade, backup off-site, conectividade e suporte: **A COTAR**.

**Conclusão:** as escolhas do projeto agora são coerentes para apresentação técnica, mas não equivalem a instalação, auditoria jurídica de direitos de uso, contratos assinados nem teste de recuperação concluído.
