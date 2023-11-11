#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void printNumber(int number){
  if (number < 0) {
        putchar('-');
        number = -1 * number ;
    }

    if (number == 0) {
        putchar('0');
        return;
    }

    int reversed = 0;
    while (number > 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }

    while (reversed > 0) {
        int digit = reversed % 10;
        char digit_char = '0' + digit; // Convert digit to character
        putchar(digit_char);
        reversed /= 10;
    }
}
/*------------------------------------------*/
void printStr(const char* string) {
  int i, len;
  len = strlen(string);
  for (i = 0 ; i < len ; i++)
    putchar (string[i]);
}
/*----------------------------------------*/
void _printf(const char* format, ...) {
    int i,len;
    len = strlen(format);
    va_list ptrArgList;
    va_start(ptrArgList, format);

    if (format[i]  != '\0') {
      for (i = 0 ; i < len ; i++)
        if (format[i] == '%') {
            i++; // Move past '%'
            
           if (format[i] == 's') {
                char* string = va_arg(ptrArgList, char*);
                printStr(string);
            }
	   else if  (format[i] == 'd'){
	     int number = va_arg(ptrArgList,int);
	       printNumber(number);
	   }
	   else {
                putchar('%');
                putchar(format[i]);
            }
        } else {
            putchar(format[i]);
        }
        
    }

    va_end(ptrArgList);
}




int main() {
  _printf("Hello World %s cohort %d\n","ALXSWE", 20);
    return 0;
}
