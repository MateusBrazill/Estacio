# Trabalho final - Software Básico em C

###Questão 1 
No código q1.c foi feito um exemplo de aquisição de dados utilizando um sensor de temperatura e um sensor de umidade do solo. 

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







