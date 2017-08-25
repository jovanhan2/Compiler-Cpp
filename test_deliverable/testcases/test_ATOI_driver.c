#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f (const char* s);



int main () {

      char str[20];
    strcpy(str, "3");

  return !(3 == f(str));
}
