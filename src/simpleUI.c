#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
#define max_lim 100


int main()
{
  char str[max_lim]; /* string to tokenize */

  List *list = init_history(); /*list to keep history */

  char num;

  printf("Welcome to tokenizer!\n");
  printf("Here you will be able to tokenize many strings and keep history of them\n");
  printf("Now read the following instructions to begin\n");
  printf("\n");
  
  while(num != -1){

    printf("Select 1 to tokenize a new string\n");
    printf("Select 2 to view history\n");
    printf("Select 0 to quit the program\n");

    scanf("%d", &num);

    char hold; //in order to get new strings
    scanf("%c", &hold);

    if(num == 1){
      printf("Enter string\n");
      fgets(str,60,stdin);
      char **token = tokenize(str);
      print_tokens(token);
      free_tokens(token);

      printf("\n");

      /*getting first word of sentence*/
      char *first = word_start(str);
      printf("The first word of the string is: ");
      printf("%c\n", first);

      /* getting the number of words*/
      int num_words = count_words(str);
      printf("The number of words in the string is: ");
      printf("%d\n", num_words);

      add_history(list, str); //adding the token into the history
     
      printf("\n ");
    }
    if(num == 0){
      break;
    }

    if(num == 2){
      printf("Here is the complete history of everything you have tokenized!\n");
      print_history(list);
      /* int string_num;
      printf("Select string number to print\n");
      scanf("%d", &string_num);

      char erase;
      scanf("%c", &erase);

      while(string_num != -1){
	char **token = tokenize(get_history(list, string_num));
	print_tokens(token);
	free_tokens(token);
	}*/
    }
  }

  free_history(list);
  printf("Thank you for using tokenizer\n");
  printf("please come back later\n");
  

  return 0;
}
