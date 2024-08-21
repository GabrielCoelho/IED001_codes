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

## Reutilização e autoria do Código

- Foi reaproveitado, além do código disponibilizado pelo professor Marcos Nava, o arquivo de pilha e a função `bool precedencia()` do [Cleber Souza](https://github.com/SouzaCleber98)
- O Código foi executado e testado diversas vezes pelos participantes do projeto: [Gabriel Coelho Soares](https://github.com/GabrielCoelho) e [Marcos Moreira Martins](https://github.com/hmindiano) estando pronto para a entrega desde o dia 2024-08-21 às 10:15:48
- Todos os códigos estão identificados com os respectivos criadores, resepeitando a propriedade intelectual.
