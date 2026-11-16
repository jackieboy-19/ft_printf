*This project has been created as part of the 42 curriculum by jbrito.*

# FT_PRINTF

## Description

This project consists of recoding a well-known function of the C library, `printf()`. The goal is to learn how variadic functions work in C (`va_list`, `va_start`, `va_arg` and `va_end`) and how to organise code so that it stays readable and easy to extend.

`ft_printf` writes formatted output to the standard output and returns the number of characters printed, like the original. It handles the following conversions:

- `%c`: a single character
- `%s`: a string
- `%p`: a pointer, in hexadecimal
- `%d` and `%i`: a signed decimal integer
- `%u`: an unsigned decimal integer
- `%x` and `%X`: a hexadecimal number, in lowercase or uppercase
- `%%`: a percent sign

The project is compiled into a static library, `libftprintf.a`, which also includes the `libft` functions it depends on.

## Instructions

To compile the library from the root of the repository:

```bash
make # builds libftprintf.a
make clean # removes the object files
make fclean # removes the object files and libftprintf.a
make re # fclean + all
```

To use it in your own program, include the header and link the archive.

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf
```

## Resources

- `man` pages of the functions (ex: `man printf`, `man stdarg`) 
- 42 ft_printf subject
- GNU make documentation
- Community tester used to check the work: printfTester(Tripouille), francinette (xicodomingues)

### How AI was used 

I used Claude (Anthropic) as a private tutor and professor while building this project. It was used for:

- **Step-by-step guidance**: questions and hints while I was building the main functions (`ft_printf` and `ft_handle_format`) without giving the code raw.

- **Concept explanation**: helped me understand variadic function, concept that was totally new for me and as well as its passage `va_list` as a pointer.

- **Debugging**: it helped me find the cause of some tester failures (wrong format flags passed for `%x`/ `%X`, and the `(nil)` output of `%p` for a `NULL` pointer).

- **Makefile**: helped me with the integration of the libft and cleaning rules and its structure.

- **README**: helped and guided me through the building of this readme.

## Algorithm

`ft_printf` has no buffer and no data structure: every character is written directly to the standard output with `write`, and the function only keeps a counter of the characters printed.

**Main loop.** `ft_printf` walks through the `format` string one character at a time. A normal character is written immediately and the counter is incremented. When a `%` is found, the loop moves to the next character (the conversion) and delegates it to `ft_handle_format`, adding the value it returns to the counter.

**Dispatch.** `ft_handle_format` receives the conversion character and the argument list, and calls the right function with `va_arg`. A chain of `if / else if` was chosen because it is simple, readable and fits the Norm when split in its own function. Adding a new conversion only means adding one more branch.

**`va_list` passed by pointer.** `va_arg` changes the state of the `va_list`. If it was passed by value, the function would only consume a copy and the caller would read the same argument again. Passing `va_list *` makes every `va_arg` advance the original list.

**Return values.** Every `ft_print_*` function returns the number of characters it wrote. This way `ft_printf` can just sum them and return the total, like the original `printf`.

**Conversions:**

- `%c`, `%%`: a single `write`, returning 1.
- `%s`: writes the string character by character and returns its length. A `NULL` string prints `(null)`, as the original does.
- `%d`, `%i`: uses `ft_itoa` from the libft, which already handles negative numbers and `INT_MIN`. The resulting string is printed with `ft_print_str` and then freed, so there are no leaks.
- `%u`: `ft_itoa` cannot represent values above `INT_MAX`, so it uses recursion. If `n >= 10`, it prints `n / 10` first and then `n % 10`. This prints the digits in the correct order without a buffer or allocation, and the counts of each call are summed.
- `%x`, `%X`: the same recursion in base 16. Digits above 9 are converted to letters, lowercase or uppercase depending on the conversion.
- `%p`: prints `0x` followed by the address converted to `unsigned long` and printed in lowercase hexadecimal. A `NULL` pointer prints `(nil)`, to match the original.

**Why this design.** The recursion avoids intermediate strings and `malloc` (except inside `ft_itoa`), keeps each function short and easy to test, and the separation between the loop, the dispatcher and the printing functions makes the code easy to extend.
