# Trabalho final - Software Básico em C

Aluno: **Mateus Brazil de Oliveira**
Matricula: **202003447031**

###Questão 1 
No código q1.c foi feito um exemplo de aquisição de dados utilizando um sensor de temperatura e um sensor de umidade do solo. 

Link tinkercad: https://www.tinkercad.com/things/aCN34IVPqDT?sharecode=c4sXnb3R9JCt24S4rsg9y2-Tm9A3wvPyI9dv2FyzWPU

Bibliotecas utilizadas: **LiquidCrystal.h**

Foi utilizado o display LCD 16x2 de comunicação paralela. 

#####Configuração dos pinos
|  Pino |  Descrição |
| ------------ | ------------ |
| A1  | Entrada analógica sensor de temperatura  |
| A2  | Entrada analógica sensor de umidade |
|  9 |  Pino reset do display |
|  8 |  Pino enable do display |
|  4 |  Data 4 do display |
|  5 |  Data 5 do display |
|  6 |  Data 6 do display|
|  7 |  Data 7 do display |

#####Aquisição dos valores

Para que os valores analógicos fossem adquiridos corretamente foram necessárias algumas conversões. 

Para o sensor de temperatura multiplico por uma constante de valor **0.004882814** que é produto da divisão de **5/1024**. 5V de tensão dividido pela quantidade de inteiros que o canal analógico do arduino Uno é capaz de ler. O canal analógico do arduino uno tem 10 bits.

O valor de 0.5 é o offset do sensor de temperatura TMP36, utilizado no Tinkercad. Após isso basta normalizar o valor de mV para V. 

**OBS**: A conversão para mV é feita multiplicando por 100 e não por 1000 pois a escala do sensor é de 10mv/C

Datasheet TMP36: https://www.analog.com/media/en/technical-documentation/data-sheets/tmp35_36_37.pdf

Para a leitura do sensor de umidade foi utilizada a função map(). Estou indicando qual a variavel sera lida e qual o intervalo de leitura e o valor correspondente ao intervalo.

###Questão 2
Para construir a régua digital foi utilizado o sensor ultrassonico HC-SR04 para efetuar a medição de distância e um display lcd 16x2 paralelo para visualizar as informações.

Link tinkercad: https://www.tinkercad.com/things/l8OqqMqI3n9?sharecode=_sGyuvZzjgcTZv0PWum43IA6AB91Qi3VzqUCF6pm5Ws

Bibliotecas utilizadas: **LiquidCrystal.h**

#####Configuração dos pinos
|  Pino |  Descrição |
| ------------ | ------------ |
| 6  | Trigger sensor ultrassonico |
| 5  | Echo do sensor ultrassonico |
|  12 |  Pino reset do display |
|  11 |  Pino enable do display |
|  10 |  Data 4 do display |
|  9 |  Data 5 do display |
|  8 |  Data 6 do display|
|  7 |  Data 7 do display |

#####Aquisição da distância

Para que o sensor ultrassonico seja habilitado é preciso enviar um sinal para o trigger com uma duração de 10uS.  

Após o sinal ser enviado é preciso medir o tempo em que o pino echo permaneceu no no nível alto. Para efetuar essa medição utilizei o método pulseIn() do arduino.

Após efetuar a medição multiplica-se a duração do pulso pela velocidade do som (340M/S) dividido por 2. 

O valor da velocidade esta como 0.034 pois o valor medido esta em ms. A divisão por 2 ocorre pois o valor do pulso corresponde a ida e volta do som.

Após a medição é feita uma espera de 500ms e a rotina se repete novamente. O datasheet recomendo uma espera minima de 60ms.

Datasheet HC-SR04: https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf

###Questão 4

Para exemplificar a utilização do Mutex foi feito um sistema de saque e deposito.

As operações de saque e deposito foram executadas em threads, porém para evitar que as operações fossem executadas simultaneamente utilizei o mutex para efetuar o bloqueio das outras threads enquanto a operação de saque/deposito não é finalizada.

Caso queira simular casos diferentes basta mudar os valores assumidos para as variáveis deposit_amounts e withdraw_amounts. Não esquecer também de atribuir uma nova quantidade de threads compatível com a nova quantidade de valores assumidos.

###Questão 5

Nesta questão foi escolhida a operação de fatorial. 

Foi criado um mutex para controlar a manipulação da variável global **result**. A função **partial_factorial** recebe como argumento o id da thread que esta efetuando a execução dela.

#####Como o cálculo é efetuado?

Cada thread fica responsável pelo cálculo de uma parte do fatorial. 

O estado inicial de cada execução do for é igual a **1 + thread_id**.

Suponha que desejamos calcular o fatorial de 10.

1° thread: **1.5.9**
2° thread: **2.6.10**
3° thread: **4.8**
4° thread: **3.7**

No caso do primeiro thread seu id é igual a 0, logo thread_id + 1 = 1, na segunda iteração soma-se o número de threads pelo valor de i, resultando no valor de 5. A execução do código se mantem enquanto i for menor ou igual a N (Valor do fatorial).
