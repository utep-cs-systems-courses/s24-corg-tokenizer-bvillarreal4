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
  char **wordTokens = (char **)malloc(100 * sizeof(char*));

  char *token;
  char *tokenEnd;
  int strLen;

  for(int i = 0; i < count_tokens(str); i++){
    token = token_start(str);
    tokenEnd = token_terminator(tokenStart);
    strLen = 0;
    while(token[strLen] != ' '){
      strLen++;
    }
    wordTokens[i] = (char *)malloc((strLen + 1) * sizeof(char));
    wordTokens[i] = copy_str(token, strLen);

  }
  wordTokens[count_tokens(str)] = NULL;
  return wordTokens;
}

void print_tokens(char **tokens){
  for(int i = 0; tokens[i] != NULL; i++){
    printf(tokens[i]);

  }
}

void free_tokens(char **tokens){
  for(int i = 0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }
  free(tokens);
}

}



int main(){

  char *str = "h e llo";
  printf("%d\n", count_tokens(str));
  printf("%d\n", copy_string(str, 2));
}
