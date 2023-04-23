#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int handle_format(va_list args, const char *format);
const char *skp_space_percent(const char *s);
int print_str(va_list args);

#endif
