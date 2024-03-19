#include "tokenizer.h"
#include "history.h"

List* init_history(){
  List *history = (List*)malloc(sizeof(List));

  history->root = NULL;

  return history;

}

void add_history(List *list, char *str){
  Item *add_item = (Item*)malloc(sizeof(Item));

  if(list->root == NULL){
    list->root = add_item;
    list->next = NULL;
  }
  else{
    list->next = add_item;
    list->next->next = NULL;
  }

 


}
