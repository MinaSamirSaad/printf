#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int handle_format(va_list args, const char *format);
const char *skp_space_percent(const char *s);
int print_str(va_list args, char tag);
int print_integer(va_list args);
int print_unsigned_integer(va_list args, char tag);
int print_binary(va_list args);
int print_address(va_list args);

#endif
