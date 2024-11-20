// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Ordering {
  int register_number;
  char name[60];
  struct Ordering *next;
  struct Ordering *prev;
};

extern struct Ordering *start_dlist;
extern struct Ordering *end_dlist;
extern struct Ordering *newPointer_dlist;
extern struct Ordering *aux_dlist;
extern struct Ordering *prev_dlist;
extern struct Ordering *current_dlist;

/**
 * Struct LinkedList newData pointer.
 * This function allocates a memory of a Ordering struct size, and points to
 * it. Then it returns this pointer
 * @params data -> an integer value
 * @return pointer to a LinkedList Struct*/
struct Ordering *newData_dlist(char *data);

/**
 * Add new Data
 * This function recieves a integer data and checks if the list is already
 * created. Since the list is always ascendent sorted, this function checks
 * where to put the new value, and calls for other three functions.
 * @params data -> an integer value*/
void addNewData_dlist(char *data);

/**
 * Add the data at the begining of the list
 * This function is called by it's parent function "Add new Data", to literally
 * add this new item at the start of the list. Since all pointers has been
 * started, it doesn't need any parameter or return types*/
void addAtStart();

/**
 * Add the data at the end of the list
 * This function is called by it's parent function "Add new Data", to literally
 * add this new item at the end of the list. Since all pointers has been
 * started, it doesn't need any parameter or return types*/
void addAtEnd();

/**
 * Add the data in the middle of the list
 * This function is called by it's parent function "Add new Data", to literally
 * add this new item in between two pointers of the list. Since all pointers has
 * been started, it doesn't need any parameter or return types*/
void addInTheMiddle();

/**
 * Remove an item if it exists
 * This function removes an item of the list if it exists. Basically the
 * opposite of addNewData, this function is also a parent of this other three
 * functions, to remove at the begining, at the end and in between the middle.
 * @params data -> an integer value*/
void removeItem(char data);

/**
 * Remove the first item
 * This function is only called by its parent, and basically removes the first
 * item. It checks if the list has only one item or not to be precise and to not
 * derreferenciate any pointers*/
void removeAtStart();

/**
 * Remove the last item
 * This function is only called by its paretn, and removes the last item of the
 * list, pointing the previous one to NULL and freeing the memory. */
void removeAtEnd();

/**
 * Remove an item in the middle
 * This function is only called by its parent, sets the "next" field of the
 * previous pointer to the next field of the auxiliar pointer. Then, we just
 * need to free this auxiliar.*/
void removeInTheMiddle();

void initialize_dlist();

void terminator_dlist(struct Ordering *who);

char *peekFirst();

char *peekLast();

void toBeginning();

void toEnd();

bool toNext();

bool toPrevious();

bool getCurrent(char *ext_data);

void showFirstToLast();
#endif  // !LINKEDLIST_H
