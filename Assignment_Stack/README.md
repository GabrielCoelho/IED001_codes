# Descrição do Projeto

- Algoritmo de Shunting Yard por Edgar Dijkstra:
- O programa começa com o usuário passando uma string com a
expressão.
- Essa string deve ser processada e os elementos precisam ser
divididos em elementos de um vetor.
- Vamos aceitar as seguintes operações: + - * / ( )
- A regra de precedência será a seguinte:
- Se o segundo operador for ( ou ) o resultado será
menor precedência
- Se o primeiro operador for * ou / e o segundo for +
ou - será menor precedência
- Senão será maior precedência
- Serão necessárias duas pilhas:
- - operadores (char)
- - valores (double)
- Tanto uma pilha quanto a outra devem ter uma função que seja
capaz de ver o elemento no seu topo sem retirá-lo.
- Também será necessário criar uma função que determina se as
pilhas estão vazias.
