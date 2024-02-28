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
  }
  return 0;
}

char *token_terminator(char *token){
  while(*token){
    if(non_space_char(*token)){
      token++;
    }
    else{
      return token;
    }
  }
  return NULL;
}

int count_tokens(char *str){
  char *s;
  char *t;
  int count = 0;
  while(*str){
    s = token_start(str);
    t = token_terminator(s);
    if(!(s==0) ){
      count++;
    }
    if(t==NULL) {
      return count;
    }
    str = t;
  }
}

char *copy_str(char *inStr, short len){
  char *outStr = (char *)malloc((len + 1) * sizeof(char));

  for(int i =0; i < len; i++){
    outStr[i] = inStr[i];
  }

  outStr[len] = "\0";

  return outStr;
}

char **tokenize(char* str){

}

}



int main(){

  char *str = "h e llo";
  printf("%d\n", count_tokens(str));
}
