#include "main.h"
#include <stdint.h>
#include <string.h>
int func_octal(char *buffer, int *bi, va_list list)
{
    unsigned int num = va_arg(list, unsigned int);
    char octalRepresentation[12];
     int i = 0;
    do {
        octalRepresentation[i++] = '0' + (num % 8); 
	num /= 8;
	 } while (num > 0);
     while (i > 0) {
        *(buffer + (*bi)++) = octalRepresentation[--i];
    }
(*bi)--;
    return i; 
}

int func_hexadecimal(char *buffer, int *bi, va_list list, int uppercase)
{    int i;
    unsigned int num = va_arg(list, unsigned int);
    char hexDigitsLower[] = "0123456789abcdef";
     char hexDigitsUpper[] = "0123456789ABCDEF";
     char *hexDigits = uppercase ? hexDigitsUpper : hexDigitsLower;
    char hexRepresentation[9];
       i = 0;
    do {
        hexRepresentation[i++] = hexDigits[num % 16]; 
        num /= 16;
	 } while (num > 0);
        while (i > 0) {
        *(buffer + (*bi)++) = hexRepresentation[--i];
    }
 (*bi)--;
    return i; 
}

int func_pointer(char *buffer, int *bi, va_list list)
{ int i;
    uintptr_t address = (uintptr_t)va_arg(list, void *);
    char hexDigits[] = "0123456789abcdef";
    char hexRepresentation[17];

    
    buffer[(*bi)++] = '0';
    buffer[(*bi)++] = 'x';

  
     i=0;
    do {
        hexRepresentation[i++] = hexDigits[address % 16]; 
        address /= 16; 
    } while (address > 0);

    while (i > 0) {
        *(buffer + (*bi)++) = hexRepresentation[--i];
    }
      (*bi)--;
    return i + 2;
}

void reverse_string(char *str) {
    int length = _strlen(str);
    int start = 0;
    int end = length - 1;
    char temp ;
    while (start < end) {
	    printf("%d ,%d \n",start,end);
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
	printf("%d ,%d \n",start,end);
    }

}
int func_reverse(char *buffer, int *bi, va_list list) {
    char *str = va_arg(list, char *);
     int length;
     int i;
    reverse_string(str);

     length = _strlen(str);
    for (i = 0; i < length; i++)
                buffer[(*bi)++] = str[i];
        (*bi)--;

    return length;
}
