# Plano de Sistemas Operacionais e Continuidade — DF-SO-001

**Ambiente:** 50 desktops Windows 11 Pro x64, servidor de virtualização com plataforma a homologar, VMs Ubuntu Server 24.04 LTS x64. Confirmar licenças de Windows, softwares criativos e qualquer subscrição de virtualização; não foram cotadas. Ubuntu 24.04 LTS recebe manutenção de segurança padrão até maio/2029 (Canonical).

## Serviços propostos

| Máquina lógica | Serviços | vCPU | RAM GB | Armazenamento inicial GB |
|---|---|---:|---:|---:|
| VM-ID01 | Identidade corporativa, LDAP/Kerberos, DNS interno | 2 | 8 | 100 |
| VM-NET01 | DHCP, NTP, registros internos | 2 | 4 | 80 |
| VM-FILES01 | SMB compartilhado com ACL, metadados do NAS | 4 | 16 | 160 |
| VM-APP01 | painel interno, CI editorial, automações aprovadas | 4 | 16 | 160 |
| VM-MON01 | métricas, syslog, alertas e inventário | 2 | 8 | 160 |
| VM-BKP01 | orquestração de cópias, catálogo de restauração | 2 | 8 | 160 |
| **Total provisionado** |  | **16** | **60** | **820** |

**Capacidade:** reservar RAM adicional no host para hypervisor, cache e crescimento. 128 GB é proposta inicial; CPU sobrecomprometida somente após medição de carga. Integrar autenticação Windows com solução licenciada e compatível; a modalidade (AD local, híbrido, Samba AD) será homologada antes da implantação.

## Menor privilégio e recursos

| Grupo | Roteiros | Produção/mídias | Financeiro/RH | Administração TI |
|---|---|---|---|---|
| GG-ROTEIRO | modificar | leitura de material aprovado | negar | negar |
| GG-CRIATIVO | leitura | modificar | negar | negar |
| GG-PUBLICACAO | leitura aprovada | leitura/publicação | negar | negar |
| GG-ADM | negar | negar | modificar apenas sua área | negar |
| GG-TI | acesso de suporte auditado | somente quando autorizado | negar por padrão | administrar |

MFA e contas nominativas nos serviços SaaS e canais; gerenciador empresarial de senhas; conta de emergência sob custódia; princípio de quatro olhos para recuperação de canais; revogação de acesso no desligamento; proibição de compartilhar credenciais no navegador; dispositivos com criptografia de disco, EDR e atualizações mensais após homologação.

## Continuidade

- **RPO-alvo para projetos ativos: 4 h** (snapshot/cópia incremental), **RTO-alvo: 8 h** para pastas críticas. São metas de projeto, não resultados obtidos.
- Dados administrativos: backup diário, retenção 30 dias; mídias ativas: snapshots em intervalos de 4 h, cópia diária independente, cópia off-site diária criptografada; retenção 30 dias + fechamento mensal 12 meses sujeito a política de privacidade.
- Restaurar 1 arquivo e 1 VM por mês com logs, hashes e tempos reais; revisar resultados trimestralmente.
- Regra 3-2-1: três cópias, dois suportes, uma fora da sede. Bloquear acesso da conta de produção à destruição dos backups imutáveis/offline.
- **Risco central:** site único. Ausência de segundo host impede alta disponibilidade local. Admitir janela de recuperação e documentar plano para substituição do host.

## Operação

| Atividade | Frequência | Responsável | Evidência |
|---|---|---|---|
| Patches críticos | conforme severidade; revisão mensal | TI | logs e inventário |
| Revisão de acessos | trimestral e desligamentos imediatos | TI + gestor | ata de aprovação |
| Backup | conforme política acima | TI | relatório e alerta |
| Restauração | mensal | TI | captura, arquivo e tempos |
| Licenças | trimestral | Administrativo/TI | notas e termo |
