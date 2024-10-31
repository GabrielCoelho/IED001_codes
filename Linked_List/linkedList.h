// Copyright (c) 2024 Gabriel Coelho Soares. All Rights Reserved.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct linkedList {
  int data;
  struct linkedList *next;
};

extern struct linkedList *start;
extern struct linkedList *end;
extern struct linkedList *newPointer;
extern struct linkedList *aux;
extern struct linkedList *prev;
extern struct linkedList *current;

/**
 * Struct LinkedList newData pointer.
 * This function allocates a memory of a linkedList struct size, and points to
 * it. Then it returns this pointer
 * @params data -> an integer value
 * @return pointer to a LinkedList Struct*/
struct linkedList *newData(int data);

/**
 * Add new Data
 * This function recieves a integer data and checks if the list is already
 * created. Since the list is always ascendent sorted, this function checks
 * where to put the new value, and calls for other three functions.
 * @params data -> an integer value*/
void addNewData(int data);

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

#endif  // !LINKEDLIST_H
