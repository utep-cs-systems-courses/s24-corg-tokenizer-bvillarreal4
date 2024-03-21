#include "tokenizer.h"
#include "history.h"

List* init_history(){
  List *history = (List*)malloc(sizeof(List));

  history->root = NULL;

  return history;

}

void add_history(List *list, char *str){
  Item *add_item = (Item*)malloc(sizeof(Item));
  Item *tempRoot = list->root;

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

 


}
