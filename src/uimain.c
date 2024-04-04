#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"

int main(){
  char input[100];
  char *str;
  char **tokens = (char** )malloc(100 * sizeof(input));
  List *history = init_history();

  goto main;

 main:
  printf("Enter your input. If done inputting, enter an empty input \n");
  printf("Enter '!' + the ID of an input you want to view \n");
  printf("Enter '*' to view the entire history \n");

  do{
    printf("> ");
    int id;
    fgets(input, sizeof(input), stdin);
    str = input;

    //checks if the input is empty indicating the user is done inputting lines
    if(input[0] == '\n'){
      break;
    }

    //switch cases for user input, if the user inputs ! it will print the id otherwise it will
    //add the users inputted string into the history

    switch(input[0]){

    case '!':
      //converts the character after the ! into a number and assigns it to the id value
      id = input[1] - 0;
      printf(get_history(history,id));
      break;

      //case that prints entire history
    case '*':
      print_history(history);
  
      break;
      
    //default case that adds the users input to the history list
    default:
      tokens = tokenize(str);

      for(int i = 0; i < count_tokens(str); i++){
	add_history(history, tokens[i]);
      }
      break;
    }
  }while(input[0] != '\n');

}
