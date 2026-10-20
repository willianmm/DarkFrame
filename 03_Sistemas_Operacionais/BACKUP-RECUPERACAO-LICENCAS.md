# DF-SO-004 — Continuidade, backup e licenciamento
**Revisão:** 1.0 | **Status:** metas para dimensionamento e validação, não SLAs medidos.

## 1. Política planejada
| Ativo | Frequência | Retenção proposta | Destino separado | RPO-alvo | RTO-alvo |
|---|---|---|---|---|---|
| Projetos audiovisuais ativos | Snapshot a cada 4h + backup diário | 30 dias + mensal 12 meses (se permitido) | Backup isolado + externo criptografado | 4h | 8h |
| Administrativo (RH/Finanças) | Backup diário | 30 dias; retenções legais a aprovar | Isolado/off-site criptografado | 24h | 8h |
| Diretório e DNS | Backup diário e antes de mudança | 30 dias | Backup isolado | 24h | 8h |
| VMs e configurações | Backup diário e antes de alterações | 30 dias | Repositório separado | 24h | 8h |
| Código e documentação | Versionamento + backup diário de exportações | Conforme política | Fora do host principal | 24h | 8h |

**3-2-1:** 3 cópias incluindo original, 2 mídias/locais de armazenamento distintos, 1 fora da sede; pelo menos uma cópia imutável ou offline com credenciais independentes. RAID 6 do NAS **não substitui backup**. Snapshots no mesmo NAS não são cópia independente.

### Teste de recuperação (a executar)
1. Selecionar projeto de amostra não confidencial e registrar hash, tamanho e horário de proteção.
2. Recuperar arquivo excluído em ambiente isolado; registrar tempo, hash e permissões após restauração.
3. Restaurar VM piloto a rede de teste segregada; verificar serviço, logs, tempo real e dependências.
4. Comparar perdas de dados e tempos reais com RPO/RTO planejados. Guardar relatórios e revisão pela TI.
5. Repetir mensalmente para arquivo e VM; simular incidente maior em revisão trimestral.

**Limitação operacional:** um único host físico é ponto único de falha. RTO de 8h depende de reposição/backup e pode não ser alcançado sem host de reserva ou contrato de suporte. Reportar risco e aprovar aceite formal.

## 2. Licenciamento e orçamento: quadro de apuração
| Categoria | Quantidade base | Modelo a verificar | Evidência necessária |
|---|---:|---|---|
| Windows 11 Pro | 50 dispositivos | OEM/volume conforme contrato | Fornecedor, SKU, preço, URL, data |
| Edição de vídeo / imagem / áudio | Até 16 usuários criativos | Assinaturas por usuário ou software livre conforme teste | Política de licença, plano, custo anual |
| Ferramentas de escritório | Até 50 usuários | Suite contratada a selecionar | Licença, plano, custo recorrente |
| Servidor de identidade | 1 serviço | Windows Server + CALs **ou** Samba AD conforme decisão | SKU e prova de direito de uso |
| Hipervisor | 1 host | Produto/versão/subscrição a escolher | Direitos de uso, manutenção e suporte |
| Backup off-site | Volume ainda a dimensionar | Armazenamento externo + tráfego/egresso | Custo por GB/TB e retenção |
| EDR/gestão de dispositivos | 50 estações e servidores aplicáveis | Produto e licenciamento a selecionar | Quantidade, cobertura, renovação |

Sem cotação, **não há valor fechado de TCO**. Separar CAPEX (equipamentos), OPEX (energia, nuvem, Internet, subscrições e suporte) e reserva de contingência. Licenças de sistema podem estar vinculadas ao equipamento; não duplicar no total.

## 3. Responsabilidade e aprovação
TI: implantar e comprovar backup, revisão de permissões e testes. Gestão: definir criticidade e custos toleráveis por indisponibilidade. Financeiro: validar preços e contratos. Segurança/LGPD: revisar retenção e tratamento de dados pessoais. Equipe acadêmica: produzir evidências correspondentes ao ambiente simulado, sem alegar implantação real.
