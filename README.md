# C - printf

## Description
This custom-made printf project is an implementation of a simplified version of the standard C library's printf function. This project aims to provide a flexible and extensible way of formatting and printing various types of data. It includes variadic functions, structs, formating functions and utility functions which handle different data types, formatting options, and special cases to achieve this goal.

The function returns the number of characters that have been successfully printed (excluding the null byte used to terminate output for strings) if the function executes without errors. In case of an error or if the string argument is (NULL), the function returns (-1). When encountering an unknown specifier, it is treated as a string and printed accordingly.

### Prototype
`int _printf(const char *format, ...)`

### File Usage
File Name | Description
--- | ---
[main.h](https://github.com/germanchuks/printf/blob/master/main.h) | The header file containing all prototypes, definitions, struct and the standard libraries used.
[_printf.c](https://github.com/germanchuks/printf/blob/master/_printf.c) | Contains the main logic of this custom _printf function, handling the formatting and printing of data based on the provided format string and arguments.
[printf_manpage](https://github.com/germanchuks/printf/blob/master/printf_manpage.3) | The _printf function man page.
[_putchar.c](https://github.com/germanchuks/printf/blob/master/_putchar.c) | Prints a single character to the standard output.
[type_handler.c](https://github.com/germanchuks/printf/blob/master/type_handler.c) | Contains the handle_print function which prints different types of arguments based on the provided format string. It iterates through an array of format types and invokes corresponding print functions for characters, strings, integers, binaries, etc.
[get_print_precision.c](https://github.com/germanchuks/printf/blob/master/get_print_precision.c) | Calculates the precision specification for formatting an argument. Precision is the maximum number of characters to be printed from a string or the number of decimal places for a floating-point number.
[get_print_width.c](https://github.com/germanchuks/printf/blob/master/get_print_width.c) | Calculates the print width for a field by  examining the format string provided as input and identifies the width specification for formatting the printed output. 
[get_size.c](https://github.com/germanchuks/printf/blob/master/get_size.c) | Contains the get_size_specifier function which calculates the size specifier for argument casting by examining the format string provided as input and identifies specific characters that indicate the desired size for argument casting. 
[get_flags.c](https://github.com/germanchuks/printf/blob/master/get_flags.c) | Contains the get_format_flags function which calculates the active formatting flags for argument printing.
[handle_write.c](https://github.com/germanchuks/printf/blob/master/handle_write.c) | Contains handle_write_char, write_num_buff, write_integer, write_formatted_ptr and write_unsigned_int functions. Each responsible for specific formatting and printing operations.
[printf_func_0.c](https://github.com/germanchuks/printf/blob/master/printf_func_0.c) | Contains actual implementation of functions which handles printing of characters, strings, percent sign, integer, and binary.
[printf_func_1.c](https://github.com/germanchuks/printf/blob/master/printf_func_1.c) | Contains actual implementation of functions which handles printing of unsigned integer, unsigned number in octal format, unsigned number in hexadecimal, uppercase and lowercase hexadecimals.
[printf_func_2.c](https://github.com/germanchuks/printf/blob/master/printf_func_2.c) | Contains actual implementation of functions which handles printing string in reverse order, string in ROT13 encoding, value of a pointer, and non-printable characters.
[utilities.c](https://github.com/germanchuks/printf/blob/master/utilities.c) | Contains functions which handles tasks including checking if a character is a digit or printable, converting numbers to different sizes, and appending hexadecimal codes to the buffer. 
### Format Specifiers
This _printf program will replicate the effects of the listed format specifiers as they are commonly found in the standard C library's printf function.

Function name | Description | Format Specifier
--- | --- | ---
`print_character` | Prints a single character | `%c`
`print_string` | Prints a string of characters | `%s`
`print_percent` | Prints % symbol | `%%`
`print_integer` | Prints an integer in base 10 | `%d` & `%i`
`print_reversed_string` | Prints the string in reverse | `r`
`print_rot13string` | Prints the string using ROT13 encoding | `R`
`print_pointer` | Prints the binary form of the integer | `p`
`print_non_printable` | Prints the binary form of the integer | `S`
`print_binary` | Prints the binary form of the integer | `b`
`print_unsigned_int` | Prints an unsigned integer | `u`
`print_octal_number` | Prints an octal number | `o`
`print_hexadecimal` | Prints the hexadecimal number in lowercase | `x`
`print_uppercase_hex` | Prints the hexadecimal number in uppercase | `X`
### Compilation

$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c
```

### Bugs
No known bugs.

## Authors
* **Michael Chukwunwe** (https://github.com/stuckwithprogression)
* **German Daniel** (https://github.com/germanchuks)

