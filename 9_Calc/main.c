#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
 
double calc(const char* s){
  char*  p, c;
  double n, sum = strtod(s, &p);
  if(s == p)
    return 0.0;
 
  for(s = p; *s; s = p){
    while(*s && isspace(*s)) ++s;
    	if(! *s)
        break;
      c = *s++;
      n = strtod(s, &p);
      if(s == p)
        break;
      switch(c){
        case '+':
          sum += n;
          break;
        case '-':
          sum -= n;
          break;
        default:
          return 0.0;
        }
    }
    return sum;
}
 
int main(void){
    char s[128];
 
    fgets(s, sizeof(s), stdin);
    printf("%lg\n", calc(s));

    system("pause");

    return 0;
}
