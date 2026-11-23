# DF-REL-006 — Texto de apresentação gravável (10–12 minutos)
**Data:** 23/11/2026. **Uso:** roteiro pronto para leitura e demonstração. Ajustar o tempo e os nomes conforme orientações do professor. Uma pessoa pode apresentar, conforme o enunciado. **O vídeo não foi gravado por este documento.**

## 00:00–01:00 | Abertura e empresa
“Olá. Este é o projeto de infraestrutura computacional da DarkFrame Studios, empresa fictícia especializada em planejamento, edição, publicação e administração de canais de conteúdo digital. O objetivo é integrar arquitetura de computadores, sistemas operacionais, redes e Internet das Coisas em uma proposta única. O cenário escolhido é um edifício de quatro andares com 50 funcionários. Nesta apresentação mostraremos as escolhas técnicas, as simulações realizadas e as limitações ainda existentes.”

**Na tela:** capa do relatório e tabela de setores.

## 01:00–03:00 | Arquitetura
“Distribuímos 50 estações em três perfis. O administrativo conta com seis máquinas de referência Ryzen 5, 16 GB de RAM e SSD de 500 GB. O operacional contempla 28 máquinas, com 32 GB de RAM e SSD de 1 TB. O especializado reúne 16 estações de edição, design e áudio, com Ryzen 7, 64 GB de RAM, SSD de 2 TB e placa RTX 4060. Esses componentes são escolhas planejadas; ainda é preciso homologar todos os SKUs e a compatibilidade do conjunto.”

“Para os serviços internos, o projeto prevê um host de virtualização, seis máquinas virtuais e um NAS com quatro discos de 12 TB em RAID 6, oferecendo 24 TB nominais úteis antes de reservas e formatação. RAID reduz certos riscos de falha de disco, mas não substitui cópias de segurança. Também previmos nobreaks e medidas de proteção para o ambiente.”

“O levantamento comercial registrou R$ 332.059,70 para componentes selecionados, porém esse valor é apenas parcial: não contém todos os computadores completos, servidores, redes, licenças e custos de instalação. Não o apresentamos como orçamento integral.”

**Na tela:** memorial de arquitetura, perfis e reconciliação de preços.

## 03:00–04:40 | Sistemas operacionais
“A proposta utiliza Windows 11 Pro nas estações e Ubuntu Server 24.04 LTS para seis máquinas virtuais. Os serviços previstos incluem identidade, DNS, DHCP, arquivos, aplicação editorial, monitoramento e backup. As funções foram distribuídas para que permissões, armazenamento e responsabilidades sejam documentados.”

“Previmos segregação de acessos, princípio de menor privilégio, backups no modelo 3-2-1 e metas de recuperação por categoria de dados. No entanto, os sistemas não foram implantados: licenças, escolha do hipervisor e ensaios de restauração permanecem como validações futuras. Não confundimos o projeto com um ambiente em produção.”

**Na tela:** catálogo das seis VMs e plano de continuidade.

## 04:40–07:10 | Redes e Packet Tracer
“A sede foi dividida em quatro andares: o primeiro tem 12 colaboradores; o segundo, 14; o terceiro, 16; e o quarto, oito. O núcleo da rede liga quatro switches de acesso, oito pontos de acesso Wi-Fi, impressoras, servidores, NAS e o roteador de borda ligado a duas operadoras.”

“O planejamento lógico utiliza nove VLANs: administrativa, operacional, criativa, TI, servidores, IoT reservada, visitantes, impressão e gerenciamento. O endereçamento foi separado por sub-redes de acordo com os perfis. A topologia nativa foi montada e salva no Cisco Packet Tracer 9.0.1; o registro do projeto indica 77 dispositivos e 76 conexões. Esta demonstração é conceitual: o desenho utiliza enlaces FastEthernet no simulador, enquanto a proposta física prevê fibra de 10 Gb/s para uplinks. Não foram demonstrados testes de DHCP, ACL ou roteamento.”

**Na tela:** abrir de fato `04_Redes/DarkFrame_topologia.pkt`; aproximar e exibir cada andar, depois a captura em `04_Redes/evidencias/`.

## 07:10–09:10 | IoT — Arduino e TMP36
“Para a sala de servidores, propusemos um monitor didático de temperatura com Arduino Uno R3, sensor TMP36 e três LEDs. O sinal do sensor é lido na porta analógica A0. Os LEDs verde, amarelo e vermelho são ligados nas portas digitais 8, 9 e 10, com resistores individuais de 220 ohms.”

“O comportamento depende da temperatura: abaixo de 28 graus Celsius, verde; entre 28 e menos de 32, amarelo; a partir de 32, vermelho. Foram realizados três testes no Tinkercad, documentados no repositório: com ajuste de 24 graus, leitura de 23,8 e LED verde; com 29 graus, leitura de 29,2 e LED amarelo; com 35 graus, leitura de 35,0 e LED vermelho. Os três foram classificados como aprovados pelo relatório da equipe. O projeto é um protótipo local, sem conexão à rede corporativa.”

**Na tela:** abrir circuito Tinkercad compartilhado e exibir as três capturas, o código e o Monitor Serial. Se não conseguir abrir em tempo real, mostrar as imagens registradas sem afirmar demonstração ao vivo.

## 09:10–10:40 | Integração, riscos e conclusão
“A integração entre as disciplinas foi planejada para suportar as demandas da DarkFrame Studios: o hardware atende os perfis, os sistemas organizam os serviços, a rede conecta os departamentos e o IoT fornece uma demonstração de monitoramento. Nosso projeto documenta uma proposta, não uma implantação comercial já contratada.”

“As pendências técnicas incluem fechamento do orçamento integral, licenciamento, escolha definitiva do servidor e NAS, compatibilidade de componentes e testes operacionais de recuperação. A documentação e as evidências ficam disponíveis no GitHub, junto do arquivo do Packet Tracer e dos testes do Tinkercad.”

“Obrigado. Este foi o projeto DarkFrame Studios.”

**Na tela:** links públicos e resumo do relatório.

## Conferência antes de gravar
- Abrir `.pkt` e conferir visibilidade dos quatro andares.
- Revisar que as leituras e capturas de IoT são as registradas, sem inventar novos resultados.
- Não anunciar compras, rede roteada ou serviços implantados.
- Gravar áudio audível, legível e dentro de **8 a 15 minutos** segundo checklist do enunciado.
- Publicar o vídeo como não listado, validar link em janela anônima e inserir a URL na **cópia privada** do PDF acadêmico.
- O vídeo deve ser gravado e disponibilizado pela equipe; este arquivo é somente o texto para apresentação.
