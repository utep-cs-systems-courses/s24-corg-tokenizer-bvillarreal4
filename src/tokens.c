#include "tokenizer.h"
#include "stdio.h"

int space_char(char c){
  if (c == '\t' || c == ' '){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c){
  if (!space_char(c)){
    return 1;
  }
  else{
    return 0;
  }
}

char *token_start(char *str){
  while(*str){
    if(space_char(*str)){
      str++;
    }
    else{
      return str;

    }
    return NULL;

  }
}
