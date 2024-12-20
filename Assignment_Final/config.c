// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.

#include "config.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "btree.h"
#include "linkedList.h"
#include "list.h"

int regi = 0;

void initializer() {
  initialize_btree();
  initialize_dlist();
  initialize_list();
  // puxar informações do arquivo @TODO
}

void terminatorAll() {
  // imprimir no arquivo @TODO
  finalize_btree(btree_start);
  terminator_dlist(start_dlist);
  free(list_pointer);
}

void read_line(char *input_buffer, int length) {
  if (fgets(input_buffer, length, stdin) != NULL) {
    if (strlen(input_buffer) > 0 &&
        input_buffer[strlen(input_buffer) - 1] == '\n') {
      input_buffer[strlen(input_buffer) - 1] = '\0';
    } else {
      int c;
      while ((c = getchar()) != '\n' && c != EOF) {
      }
    }
  }
}

bool addNewItem(char cpf[]) {
  char name[40], address[100], email[60], phone[14];
  if (localize_btree(cpf, btree_start) == NULL || btree_start == NULL) {
    regi = regi + 1;
    addNewData_btree(newData_btree(cpf), btree_start);
    printf("Nome: ");
    read_line(name, 40);
    printf("Endereço: ");
    read_line(address, 100);
    printf("Telefone: ");
    read_line(phone, 14);
    printf("Email: ");
    read_line(email, 60);

    addNewData_dlist(name);
    list_add(name, address, cpf, phone, email);

    return true;
  }
  return false;
}

bool search_cpf(char cpf[]) {
  if (localize_btree(cpf, btree_start) != NULL) {
    list_search_value(cpf);
    return true;
  }

  return false;
}

bool exclude_item(char *cpf) {
  int returned_regi = 0;
  if (localize_btree(cpf, btree_start) != NULL) {
    returned_regi = localize_btree_int(cpf, btree_start);
    if (returned_regi != -1) {
      removeData_btree(cpf);
      removeItem(returned_regi);
    } else {
      printf("Não pode excluir própriamente... \n\nSaindo...\n");
      terminatorAll();
      return EXIT_FAILURE;
    }
    return true;
  }
  return false;
}

bool setNewData(char *cpf) {
  if (localize_btree(cpf, btree_start) != NULL) {
    list_set(list_search_value(cpf));
  }

  return false;
}

/*void get_data_file() {*/
/*  FILE *persist = fopen("./database.txt", "r");*/
/*  /*int per_end_of_file = fseek(persist, 0, SEEK_END);*
    /*  int count = 0;*/
/*  char line[256], cpf[11], name[60], address[100], phone[11], email[60];*/
/*  while (fgets(line, sizeof(line), persist)) {*/
/*    switch (count) {*/
/*      case 0:*/
/*        strcpy(cpf, line);*/
/*        printf("%s", cpf);*/
/*        if (localize_btree(cpf, btree_start) == NULL || btree_start ==
   NULL)*/
/*          {*/
/*          printf("entrou aqui");*/
/*          addNewData_btree(newData_btree(cpf), btree_start);*/
/*          printf("cadastrou antes daqui");*/
/*        }*/
/*        count += 1;*/
/*        break;*/
/*      case 1:*/
/*        strcpy(name, line);*/
/*        printf("%s", line);*/
/*        count += 1;*/
/*        break;*/
/*      case 2:*/
/*        strcpy(address, line);*/
/*        printf("%s", line);*/
/*        count += 1;*/
/*        break;*/
/*      case 3:*/
/*        strcpy(phone, line);*/
/*        printf("%s", line);*/
/*        count += 1;*/
/*        break;*/
/*      case 4:*/
/*        strcpy(email, line);*/
/*        printf("%s", line);*/
/*        count = 0;*/
/*        regi += 1;*/
/*        if (localize_btree(cpf, btree_start) == NULL || btree_start ==
   NULL) {*/
/*          addNewData_btree(newData_btree(cpf), btree_start);*/
/*        }*/
/*        list_add(name, address, cpf, phone, email);*/
/*        addNewData_dlist(name);*/
/*        list_search_value(cpf);*/
/**/
/*        break;*/
/*    }*/
/*  }*/
/*}*/
