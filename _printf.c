#include <stdio.h>
#include <stdarg.h>
#include "hollberton.h"

/**
 * If States 0 Then it will be reguler
 * If States 1 Then it will be escape
 */
void printfHandel(const char *format, va_list args)
{
    int state = 0;
    while (*format)
    {
        if (state == 0)
        {
            if (*format == '%')
            {
                state = 1;
            }
            else
            {
                putchar(*format);
            }
        }
        else if (state == 1)
        {
            switch (*format)
            {
            case 'c':
            {
                putchar(va_arg(args, int));
                break;
            }
            case 's':
            {
                const char *s = va_arg(args, const char *);
                while (*s)
                {
                    putchar(*s++);
                }
                break;
            }
            }
            state = 0;
        }
        format++;
    }
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    printfHandel(format, args);
    va_end(args);
}
