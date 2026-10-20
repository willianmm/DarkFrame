# DF-SO-003 — Matriz de acesso e governança operacional
**Revisão:** 1.0 | **Status:** política proposta, sujeita à aprovação dos gestores.

## Grupos de acesso
R = leitura; M = modificar; A = administrar; N = negar. Para pastas administrativas, separar financeiro e RH. Controlar permissões no compartilhamento **e** sistema de arquivos.

| Grupo | Roteiros | Mídias em produção | Publicação final | Financeiro | RH | Administração TI |
|---|---|---|---|---|---|---|
| GG-RECEPCAO | N | N | N | N | N | N |
| GG-PUBLICACAO | R aprovados | R aprovadas | M | N | N | N |
| GG-SUPORTE-CANAIS | N | N | R se necessário | N | N | N |
| GG-ROTEIRO | M | R aprovadas | N | N | N | N |
| GG-PESQUISA | R | N | N | N | N | N |
| GG-EDICAO | R | M | R | N | N | N |
| GG-DESIGN | R | M no próprio projeto | R | N | N | N |
| GG-AUDIO | R | M no próprio projeto | R | N | N | N |
| GG-FINANCEIRO | N | N | N | M | N | N |
| GG-RH | N | N | N | N | M | N |
| GG-DIRETORIA | R sob aprovação | R sob aprovação | R | R | R com necessidade | N |
| GG-TI-OPERACAO | N padrão | N padrão | N padrão | N | N | A sob elevação/auditoria |

**Segregação:** administrador de infraestrutura não ganha automaticamente acesso ao conteúdo confidencial; acesso extraordinário é temporário, justificado, aprovado e auditado. Usuários devem ser nominativos, não contas coletivas.

## Identidades de canais YouTube
- Vincular contas corporativas e permissões por função; acesso à propriedade dos canais somente a pessoas designadas.
- Exigir MFA com recuperação guardada em cofre de credenciais e duas pessoas autorizadas no processo de recuperação.
- Não versionar tokens, senhas, cookies ou chaves da API do YouTube no GitHub; segredos devem ser gerenciados separadamente.
- Revisão de acessos trimestral e desligamento de funcionário com revogação imediata mediante comunicação formal.
- Verificar direitos de uso de trilhas, imagens, vozes, roteiros e mídias antes de publicar.

## Procedimentos
| Controle | Frequência/meta | Responsável | Evidência |
|---|---|---|---|
| Cadastro / desligamento | Cada evento | RH solicita; TI executa; gestor aprova | Solicitação e checklist |
| Atualização de estações | Mensal, com correções emergenciais por criticidade | TI | Relatório por dispositivo |
| Atualização de servidores | Janela aprovada, com backup anterior | TI | Ticket, versão, rollback |
| Criptografia e proteção de endpoint | Contínuo; auditoria mensal | TI | Inventário e console |
| Acesso privilegiado | Por necessidade e tempo limitado | TI + gestor | Logs e aprovação |
| Firewall e segmentação | Revisão trimestral e mudança de serviço | TI/Redes | Matriz e revisão de regras |
| Revisão de licenças | Trimestral | TI/Financeiro | Registro de titularidade e vigência |
| Logs e monitoramento | Coleta contínua; retenção sujeita à política e LGPD | TI | Alarmes e testes |

## Testes de segurança projetados
1. Usuário de Publicação abre pasta de Publicação (permitido) e Financeiro (negado).
2. Usuário de RH abre pasta RH (permitido) e Mídias (negado).
3. Conta técnica realiza operação administrativa após elevação autorizada; login normal não possui privilégio.
4. Revogação de conta desliga os acessos a arquivos e serviços corporativos.
Todos **pendentes de execução**; guardar captura, data, ambiente e resultado real.
