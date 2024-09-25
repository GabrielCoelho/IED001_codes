# Listas Dinâmicas Simples

Similar às pilhas e filas no modo como são inseridos novos valores, as **Listas** diferem no modo em que os elementos são retirados.

Enquanto as Pilhas utilizam do modelo FILO (First In Last Out - primeiro que entra, o último que sai), e as Filas utilizam do modelo FIFO (First In First Out - primeiro que entra e primeiro que sai), as listas não possuem um modelo específico de retirada de elementos.

O valor a ser retirado é procurado dentro da lista e, para removê-lo, todos os demais valores posteriores, devem "subir" na lista.

Exemplo:

| 1 | 2 | 3 | 4 | 5 |

valor a ser retirado: 3

passo 1: | 1 | 2 | _3_ | 4 | 5 |

passo 2: | 1 | 2 | 4 | _3_ | 5 |

passo 3: | 1 | 2 | 4 | 5 | _3_ |

passo 4: | 1 | 2 | 4 | 5 | <- remove a referência do tamanho/posição da lista.

## Funções da Lista

### Adicionar (list\_add)

Adiciona um item ao fim da lista. Como a lista é dinâmica, caso a lista esteja cheia, realocamos o tamanho com o `list_resize()`.

### Remover (list\_delete)

Remove um valor pesquisado da lista. Utilizamos uma outra função da lista `list_search_value()` que passomos o valor que queremos remover e, caso seja encontrado, execute a remoção. Caso contrário, o sistema retornará uma mensagem explicando o motivo de não ter dado certo.

### Atualizar um novo valor (list\_set)

Tendo os parâmetros `index` e `value`, esta função atualiza o item do índice proposto.

### Ordenar (list\_sort)

Ordena os valores da lista do menor para o maior. Não retorna, no fim da execução, nenhuma mensagem muito menos a lista de modo gráfico.

### Procurar pelo índice (list\_search\_index)

Dado um índice válido, imprime na tela o valor contido naquele índice. Caso seja inválido, retorna uma mensagem de erro.

### Procurar pelo valor (list\_search\_value)

Dado um valor qualquer, percorre a lista procurando seu índice. Caso exista, retorna o índice, caso contrário, exibe na tela uma mensagem de não encontrado.

### Mostrar a lista (list\_show)

Percorre a lista exibindo cada valor.

### Verificar tamanho da lista (list\_size)

Retorna o número de elementos presentes na lista

### Alterar tamanho da lista (list\_resize)

Dado uma variável determinando o maior valor para a lista, adiciona 50% deste mesmo valor à ela, e realoca uma porção de memória com este valor atualizado. Assim, a lista antiga é copiada para esta nova automáticamente e o ponteiro passa a apontar este novo espaço de memória.
