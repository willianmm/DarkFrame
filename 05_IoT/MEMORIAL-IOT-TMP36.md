# DF-IOT-002 — Memorial técnico do monitor TMP36
**Situação:** circuito e código projetados; simulação e evidências ainda não executadas.

## Finalidade
Monitor didático da temperatura da sala de servidores localizada no 4º andar. O Arduino Uno R3 lê o sensor TMP36 e informa condições com três LEDs e Monitor Serial. Os limiares do exercício são didáticos, não substituem sistema comercial de climatização, alarmes remotos ou proteção elétrica.

## Materiais obrigatórios
| Componente | Quantidade | Papel |
|---|---:|---|
| Arduino Uno R3 | 1 | Leitura e controle |
| Protoboard pequena | 1 | Conexões |
| Sensor TMP36 | 1 | Temperatura |
| LED verde, amarelo e vermelho | 1 de cada | Estado |
| Resistor 220 Ω | 3 | Limitação de corrente dos LEDs |
| Fios jumper | Conforme montagem | Interligação |

## Ligações
- Alimentação: 5V e GND do Arduino aos barramentos da protoboard.
- TMP36, **face plana voltada para a pessoa**: terminal esquerdo → 5V; central → A0; direito → GND. Conferir orientação na ferramenta.
- LED verde: ânodo ao D8, cátodo ao GND **através de resistor 220 Ω**.
- LED amarelo: ânodo ao D9, cátodo ao GND através de resistor 220 Ω.
- LED vermelho: ânodo ao D10, cátodo ao GND através de resistor 220 Ω.
- Cada LED deve possuir seu próprio resistor. Não conectar o LED diretamente à saída sem limitação de corrente.

## Algoritmo publicado
Código fonte: [monitor_tmp36.ino](monitor_tmp36.ino).

1. Ler A0 pelo conversor ADC de 10 bits (0–1023).
2. Converter para tensão: `V = leitura × 5 / 1023`.
3. TMP36: `temperatura_C = (V − 0,5) × 100`.
4. Quando T < 28 °C, ligar somente verde; quando 28 ≤ T < 32 °C, somente amarelo; quando T ≥ 32 °C, somente vermelho.
5. Enviar temperatura com uma casa decimal ao Monitor Serial, a 9600 baud; atualizar aproximadamente a cada segundo.

**Observação de engenharia:** o cálculo pressupõe referência analógica de 5 V. ADC, sensor e referência introduzem pequenas diferenças nos valores calculados. A simulação e os resultados reais devem ser registrados; não arredondar artificialmente para dizer que a leitura foi idêntica à escolhida no controle.

## Tabela de aceitação
| Caso | Temperatura ajustada no Tinkercad | Resultado esperado | Medição obtida | Captura do circuito e Serial | Situação |
|---|---:|---|---|---|---|
| Normal | 24 °C | Apenas LED verde | Não obtida | Não obtida | Pendente |
| Atenção | 29 °C | Apenas LED amarelo | Não obtida | Não obtida | Pendente |
| Crítico | 35 °C | Apenas LED vermelho | Não obtida | Não obtida | Pendente |

Além de registrar os valores, verificar o estado dos três LEDs e a saída serial. Não classificar como aprovado sem executar o teste.

## Integração com o projeto de Redes
Este protótipo Arduino Uno **não envia dados pela rede** e não precisa usar a VLAN 60. Ela fica reservada para expansão futura, não contemplada pelo exercício.

## Entrega e intervenção do grupo
1. Criar o circuito em Tinkercad → Circuits, com as ligações acima e o código de [monitor_tmp36.ino](monitor_tmp36.ino).
2. Rodar as três temperaturas, observar LED e Monitor Serial, salvar uma captura para cada caso.
3. Registrar resultado efetivamente obtido, aprovado/reprovado e eventuais ajustes no código.
4. Compartilhar link público do circuito e registrar no repositório, com screenshots no diretório de evidências.
5. Revisar e explicar a lógica do programa na apresentação em vídeo.

**Não executado neste documento:** criação do circuito no site, execução do Tinkercad, geração de capturas e comprovação física.
