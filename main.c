#include <limits.h>
#include <stdio.h>
#include "main.h"
#define ZERO 0

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
 void *addr ;
 char * r ="lina";
   unsigned int ui;
   addr = (void *)0x7ffe637541f0;
    ui = (unsigned int)INT_MAX + 1024;
    _printf("empty Character:[%c]\n", ' ');
    printf("empty Character:[%c]\n", ' ');
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("Character:[%c%c]\n", 'H', 'I');
    printf("Character:[%c%c]\n", 'H', 'I');
    _printf("Character:[%c%c%c]\n", 'H', 'I', '!');
    printf("Character:[%c%c%c]\n", 'H', 'I', '!');

    _printf("Character:[%c %c %c]\n", 'H', 'I', '!');
    printf("Character:[%c %c %c]\n", 'H', 'I', '!');
    _printf("Two c with Space:[%c %c]\n", 'H', 'I');
    printf("Two c with Space:[%c %c]\n", 'H', 'I');
    _printf("empty String:[%s]\n", "");
    printf("empty String:[%s]\n", "");
    _printf("Space String:[%s]\n", " ");
    printf("Space String:[%s]\n", " ");
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("String:[%s%s]\n", "I am a string !", "second string !");

   _printf("String:[%s%s]\n", "I am a string !", "second string !");
    printf("String:[%s %s]\n", "I am a string !", "second string !");
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
     _printf("Unsigned hexadecimal:[%x,%X]\n", ui , ui);
    printf("Unsigned hexadecimal:[%x,%X]\n", ui , ui);
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
      _printf("Unknown:[%r]\n",r);
   
      _printf("Unknown:[%s]\n",r);
   
    return (0);
}
