#include "stdio.h"
#include "stdlib.h"
#include "history.h"

List* init_history(){
  List *history = (List*)malloc(sizeof(List));

  history->root = NULL;

  return history;

}

void add_history(List *list, char *str){
  Item *add_item = (Item*)malloc(sizeof(Item));
  Item *tempRoot = list->root;
  int id = 0;

  if(list->root == NULL){
    list->root = add_item;
    add_item->next = NULL;
    add_item->str = str;
    add_item->id = 0;
  }
  else{
    while(tempRoot->next != NULL){
      tempRoot = tempRoot->next;
      id++;
    }
    tempRoot->next = add_item;
    add_item->next = NULL;
    add_item->str = str;
  }
}

char *get_history(List *list, int id){
  Item *tempRoot = list->root;

  while(tempRoot != NULL){
    if(tempRoot->id == id){
      return tempRoot->str;
    }
    else{
      tempRoot = tempRoot->next;
    }
   
  return "No previous history";

  }
}

void print_history(List *list){
  Item *tempRoot = list->root;

  while(tempRoot != NULL){
    printf(tempRoot->str);
    tempRoot = tempRoot->next;
  }
}

void free_history(List *list){
  Item *tempRoot = list->root;

  while(tempRoot != NULL){
    free(list->root);
    tempRoot = tempRoot->next;
    list->root = list->root->next;
  }

  free(list);
}
  




 



