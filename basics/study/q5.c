#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int numCharRepetidos(char str[])
{
  int fraseaux[100];
  int ascii[255];
  int i;

 for (i=0; i<255; i++){
  ascii[i]=0; 
    }
 for (i=0; i<strlen(str);i++){
  fraseaux[i]=str[i];
    }
 for (i=0; i<strlen(str); i++){
        if (fraseaux[i] > 64 && fraseaux[i] <91){
           fraseaux[i]=fraseaux[i]+32;
           }
    }
 for (i=0; i<strlen(str); i++){                       
  if (fraseaux[i] != 32){                            
        ascii[fraseaux[i]]++; 
        }
 }
int a =0;
 for (i=0; i<255; i++){
        if (ascii[i] > 1){
            a++;
        }
 }
 printf("\n %d letra(s) foram repetida(s) \n", a);
  return a;
}

int main() {
    numCharRepetidos("adoro programar em c");
    printf(numCharRepetidos("adoro programar em c"));

    return 0;
}