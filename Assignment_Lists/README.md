# Projeto de Lista Dinâmica

## Objetivo

Criar um sistema que usa uma lista para simular um arquivo em disco.

### Dados a serem armezenados

- Nome;
- Endereço;
- CPF;
- Telefone;
- Email.

## Conteúdo

O programa deverá conter o seguinte menu:

```md
1. Adicionar
2. Excluir
3. Alterar
4. Imprimir
5. Imprimir Todos
6. Ordenar
7. Sair
```

A chave de pesquisa será o `CPF`. Portanto, deve-se previnir o cadastro de dois CPFs iguais.

### Adicionar

Para adicionar, o programa deverá pedir o CPF, realizar a verificação se já possui um cadastro, e em caso negativo, solicitar os outros dados e gravar. Caso positivo, emitir uma mensagem alertando que o CPF já está cadastrado.

### Excluir

Para Excluir, solicitar o CPF e excluir se ele existir. Caso não exista, ignorar e continuar o programa normalmente, sem exibir nenhuma mensagem.

### Alterar

Para alterar, o programa deverá solicitar o CPF e verificar se já está cadastrado. Caso não esteja, emitir a mensagem que o CPF não consta e voltar ao menu.

No entanto, caso exista o CPF indicado, o programa deverá mostrar o campo cadastrado referente àquele CPF e possibilitar a entrada de novos valores.

Caso o usuário não queira alterar um valor específico, basta apertar `ENTER` que o mesmo não será alterado. Caso contrário, alterar com o valor digitado.

### Imprimir

Para imprimir um valor, o programa deverá solicitar o CPF e imprimir caso exista. Caso contraŕio, emitir mensagem de alerta.

### Imprimir Todos

Imprime todos os elementos cadastrados

### Ordenar

O programa deverá ordenar a lista pelos nomes cadastrados.

### Sair

Sai do sistema.

-------
