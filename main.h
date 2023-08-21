#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/* format_flags */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
        char fmt;
        int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;


int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
                                 va_list list, char output_buffer[], int format_flags,
                                 int min_width, int precision, int size_spec);

/* UTILITIES */
int is_digit(char);
int is_printable(char);
long int size_conv_number(long int num, int size_spec);
long int size_conv_unsgned(unsigned long int num, int size_spec);
int append_hex_code(char, char[], int);

/* PRINT CHARACTERS AND STRINGS */
int print_character(va_list args, char output_buffer[],
                                        int format_flags, int min_width, int precision, int size_spec);
int print_string(va_list args, char output_buffer[],
                                 int format_flags, int min_width, int precision, int size_spec);
int print_percent(va_list args, char output_buffer[],
                                  int format_flags, int min_width, int precision, int size_spec);

/* PRINT NUMBERS */
int print_integer(va_list args, char output_buffer[],
                                  int format_flags, int min_width, int precision, int size_spec);
int print_binary(va_list args, char output_buffer[],
                                 int format_flags, int min_width, int precision, int size_spec);
int print_unsigned_int(va_list args, char output_buffer[],
                                           int format_flags, int min_width, int precision, int size_spec);
int print_octal_number(va_list args, char output_buffer[],
                                           int format_flags, int min_width, int precision, int size_spec);
int print_hexadecimal(va_list args, char output_buffer[],
                                          int format_flags, int min_width, int precision, int size_spec);
int print_uppercase_hex(va_list args, char output_buffer[],
                                                int format_flags, int min_width, int precision, int size_spec);
int print_custom_hex(va_list args, char map_to[],
                                         char output_buffer[], int format_flags, char flag_ch,
                                         int min_width, int precision, int size_spec);

/* PRINT STRING IN REVERSE */
int print_reversed_string(va_list args, char output_buffer[],
                                                  int format_flags, int min_width, int precision, int size_spec);

/* PRINT STRING IN ROT13 ENCODING */
int print_rot13string(va_list args, char output_buffer[],
                                          int format_flags, int min_width, int precision, int size_spec);

/* PRINT NONPRINTABLE CHARACTERS */
int print_non_printable(va_list args, char output_buffer[],
                                                int format_flags, int min_width, int precision, int size_spec);

/* PRINT MEMORY ADDRESS */
int print_pointer(va_list args, char output_buffer[],
                                  int format_flags, int min_width, int precision, int size_spec);

/* OTHER SPECIFIERS */
int get_print_width(const char *format, int *i, va_list list);
int get_size_specifier(const char *format, int *i);
int get_format_flags(const char *format, int *i);
int get_print_precision(const char *format, int *i, va_list list);

/* WRITE HANDLERS */
int handle_write_char(char c, char output_buffer[],
                                          int format_flags, int min_width, int precision, int size_spec);
int write_integer(int is_positive, int index, char output_buffer[],
                                  int format_flags, int min_width, int precision,
                                  int size_spec);
int write_num_buff(int index, char buffer[], int format_flags,
                                        int min_width, int precision, int length,
                                        char padding_char, char extra_char);
int write_formatted_ptr(char output_buffer[], int index, int length,
int min_width, int format_flags, char padding_char, char extra_char,
int padding_start);
int write_unsigned_int(int is_negative, int index,
char output_buffer[], int format_flags, int min_width,
int precision, int size_spec);

#endif /* MAIN_H */

