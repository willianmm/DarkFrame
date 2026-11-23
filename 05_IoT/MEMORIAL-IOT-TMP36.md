# DF-IOT-002 — Memorial técnico do monitor TMP36

**Situação:** circuito montado e validado no Tinkercad. Os três testes de temperatura foram executados com sucesso, com evidências registradas.

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
| Normal | 24 °C | Apenas LED verde | 23,8 °C | [Evidência 24 °C](evidencias/teste-24c.webp) | Aprovado |
| Atenção | 29 °C | Apenas LED amarelo | 29,2 °C | [Evidência 29 °C](evidencias/teste-29c.webp) | Aprovado |
| Crítico | 35 °C | Apenas LED vermelho | 35,0 °C | [Evidência 35 °C](evidencias/teste-35c.webp) | Aprovado |

Os três testes foram realizados no Tinkercad, verificando o comportamento dos LEDs e os valores apresentados no Monitor Serial.

As diferenças absolutas entre as temperaturas configuradas e medidas foram de 0,2 °C, 0,2 °C e 0,0 °C, respectivamente.

## Integração com o projeto de Redes

Este protótipo Arduino Uno **não envia dados pela rede** e não precisa usar a VLAN 60. Ela fica reservada para expansão futura, não contemplada pelo exercício.

## Entrega e intervenção do grupo

1. Circuito montado no Tinkercad, utilizando Arduino Uno R3, sensor TMP36, três LEDs e resistores de 220 Ω.
2. Código implementado conforme o arquivo [monitor_tmp36.ino](monitor_tmp36.ino).
3. Testes realizados nas temperaturas de 24 °C, 29 °C e 35 °C.
4. Resultados registrados no Monitor Serial e documentados por capturas de tela.
5. Link de compartilhamento do circuito disponibilizado no repositório.
6. Revisão e explicação da lógica do programa previstas para a apresentação em vídeo.

## Simulação no Tinkercad

**Projeto:** DarkFrame — Monitor TMP36

[Clique aqui para acessar o circuito no Tinkercad](https://www.tinkercad.com/things/9YpYYnOT4nK-darkframe-monitor-tmp36?sharecode=IinUTfr2kZB4kWGQIVWQxDl-odx-CBLEJG6nf4tWruU)

O circuito permite simular diferentes temperaturas e verificar o acionamento dos LEDs conforme os limites definidos no programa.

## Registro de execução e validação

A montagem do circuito foi realizada no ambiente Tinkercad. Durante os testes iniciais, foram identificados e corrigidos problemas nas conexões e na polaridade dos LEDs.

Após os ajustes, os três cenários apresentaram os resultados esperados:

- **24 °C:** LED verde aceso, leitura de 23,8 °C.
- **29 °C:** LED amarelo aceso, leitura de 29,2 °C.
- **35 °C:** LED vermelho aceso, leitura de 35,0 °C.

O sistema demonstrou funcionamento adequado nos três cenários simulados, realizando a leitura da temperatura, a classificação das faixas e a sinalização visual correspondente.

**Limitação:** a validação foi realizada exclusivamente no ambiente de simulação Tinkercad. Não foram realizados testes em hardware físico.
