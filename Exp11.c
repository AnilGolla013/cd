// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// const char *input;
// int pos = 0;

// int S();
// int L();

// void error() {
//     printf("Error at position %d\n", pos);
//     exit(1);
// }

// char lookahead() {
//     return input[pos];
// }

// int S() {
//     if (lookahead() == 'a') {
//         pos++;
//         return 1;
//     } 
//     else if (lookahead() == '(') {
//         pos++;
//         if (!L()) error();
//         if (lookahead() == ')') {
//             pos++;
//             return 1;
//         } else error();
//     }
//     return 0;
// }

// int L() {
//     if (!S()) return 0;
//     while (lookahead() == ',') {
//         pos++;
//         if (!S()) error();
//     }
//     return 1;
// }

// int main() {
//     char buffer[100];
//     printf("Enter input string: ");
//     scanf("%s", buffer);

//     input = buffer;
//     pos = 0;

//     if (S() && input[pos] == '\0')
//         printf("String is successfully parsed.\n");
//     else
//         error();

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *input;
int pos=0;
int l();
int s();
void error(){
  printf("\nError at pos %d ",pos);
  exit(0);
}
char la(){
  return input[pos];
}
int s(){
  if(la()=='a'){
    pos++;return 1;
  }
  else if(la()=='('){
    pos++;
    if(!l()) error();
    else if(la()==')'){
      pos++;
      return 1;
    }
    else error();
  }
  return 0;
}
int l(){
  if(!s()) return 0;
  while(la()==','){
    pos++;
    if(!s()) error();
  }
  return 1;
}

int main(){
  char buffer[100];
  printf("\nEnter the input : ");
  scanf("%s",buffer);
  input=buffer;
  if(s() && input[pos]=='\0'){
    printf("accepted");
  }
  else{
    error();
  }
  return 0;
}