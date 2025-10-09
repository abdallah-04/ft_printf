##  Introduction

The **ft_printf** project is part of the 42 curriculum.  
Its goal is to recreate the well-known C function `printf()` from scratch.  
This project helps you gain a deep understanding of **variadic functions**, **format specifiers**, and **data type handling** in C.

---

##  Purpose

This project teaches:
- How variadic arguments work using `va_start`, `va_arg`, and `va_end`
- Formatting and printing data in different ways
- Clean and maintainable C programming
- Proper use of Makefiles and static libraries

---

## ⚙️ Mandatory Requirements

### Function Prototype
```c
int ft_printf(const char *format, ...);
````

### Description

Recode the C standard library function `printf()` with the following specifications:

* Do **not** implement original buffer management.
* Must handle the following conversion specifiers:

| Specifier | Description                              |
| --------- | ---------------------------------------- |
| `%c`      | Prints a single character                |
| `%s`      | Prints a string                          |
| `%p`      | Prints a pointer address in hexadecimal  |
| `%d`      | Prints a signed decimal number           |
| `%i`      | Prints a signed integer                  |
| `%u`      | Prints an unsigned decimal number        |
| `%x`      | Prints a number in lowercase hexadecimal |
| `%X`      | Prints a number in uppercase hexadecimal |
| `%%`      | Prints a percent sign                    |

---

##  Allowed Functions

You are allowed to use the following functions:

```c
malloc, free, write,
va_start, va_arg, va_copy, va_end
```

---

##  Project Structure

| File              | Description                                              |
| ----------------- | -------------------------------------------------------- |
| `ft_printf.c`     | Main function handling format parsing and dispatch       |
| `ft_print_char.c` | Prints characters                                        |
| `ft_print_str.c`  | Prints strings                                           |
| `ft_print_ptr.c`  | Prints pointer addresses                                 |
| `ft_print_num.c`  | Prints signed and unsigned integers                      |
| `ft_print_hex.c`  | Prints hexadecimal numbers                               |
| `libft/`          | Your libft library (if authorized and included)          |
| `Makefile`        | Builds the project into a static library `libftprintf.a` |

---

##  Compilation

Your `Makefile` must include the following rules:

```makefile
NAME, all, clean, fclean, re
```

It should:

* Compile all required files with the flags `-Wall -Wextra -Werror`
* Create the static library `libftprintf.a` at the root of the project
* Avoid unnecessary relinking

To compile:

```bash
make
```

To clean:

```bash
make clean
make fclean
```

To rebuild:

```bash
make re
```

---

##  Testing

You can compare your implementation with the original `printf` using test cases like:

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1 = ft_printf("My printf: %d, %s, %x\n", 42, "hello", 255);
    int ret2 = printf("Real printf: %d, %s, %x\n", 42, "hello", 255);

    printf("My return: %d | Real return: %d\n", ret1, ret2);
    return (0);
}
```

---

##  Submission Rules

* Submit your work to your Git repository.
* Only the content in the repository will be graded.
* Follow the 42 **Norm** strictly — any error will result in a **0**.
* Memory leaks and crashes are not tolerated.
* You may include your `libft` if authorized.

---

##  Final Notes

A well-structured and readable codebase is key.
Once your `ft_printf` works correctly, you can include it in your **libft** for use in future projects.

---

Would you like me to also generate a **`requirements.txt`** and a **sample Makefile** to include in your repo for consistency?
```
