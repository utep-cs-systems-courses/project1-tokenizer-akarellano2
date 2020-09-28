#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

/* Return true (non-zero) if c is a whitespace character 
   ('\t' or ' ') */
int space_char(char c)
{
  if(c == ' ' || c == '\t'){
      return true;
    }
  else{
      return false;
    }
}

/* Return true (non-zero) if c is a non-whitespace character
   (not tab or space)*/
int non_space_char(char c)
{
  if(c == ' ' || c == '\t'){
      return false;
  }
  else{
      return true;
  }
}
/* Returns a pointer to the first character of the next space-seperated
   word in zero-terminated str. Return a zero pointer if str does not
   contain any words. */
char *word_start(char *str)
{
  while(!non_space_char(*str)){
      str++;
  }
  return str;
}
/* Returns apointer terminator char following *word */
char *word_terminator(char *word)
{
  while(non_space_char(*word)) {
      word++;
  }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char* str)
{
  int temp = 0;
  int counter = 0;

  while(*str){
      if(temp == 0){
	  temp = 1;
	  counter++;
	}
      else if(*str == ' ' ||  *str == '\t' || *str == '\n'){
	  temp = 0;
	}
      str++;
  }
  return counter;
}

/* Returns a freshly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *new_string = NULL;
  char *current = inStr;

  new_string = (char*) malloc(sizeof(char)*(len+1));
  new_string[len] = '\0';

  int i = 0;

  while( *current != '\0') /*fix this loop */ {
      new_string[i++] = *current++;
    }
  return new_string;  
}

/* Returns a freshly allocated zero-terminated vector of freshly
   allocated space-seperated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
   tokens[0] = "hello"
   tokens[1] = "world"
   tokens[2] = "string"
   tokens[3] = 0
*/
char **tokenize(char* str)
{
  char *start_word = str;
  char *end_word = word_terminator(str);
  int num_words = count_words(str);
  char **token;
  token = (char**) malloc((num_words+1) * sizeof(char*));

  for(int i = 0; i < num_words; i++){
      if(i > 0) /* fix this later, do opposite change to i == 0 */{
	  start_word = word_start(end_word);
	  end_word = word_terminator(start_word);
      }

      int size_token = end_word - start_word;

      token[i] = malloc(size_token * sizeof(char));
      for(int k = 0; k< size_token; k++){
	  token[i][k] = start_word[k];
      }
  }
  return token;
}

/* Print all tokens */
void print_tokens(char **tokens)
{
  int count = 0;
  while(tokens[count] != NULL){
      printf("%s\n", tokens[count]);
      count++;
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens)
{
  int count = 0;
  while(tokens[count]) {
      free(tokens[count]);
      count++;
  }
  free(tokens);
}

#endif
