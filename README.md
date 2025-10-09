ft_printf ProjectBecause ft_putnbr() and ft_putstr() aren't enough.This project is about recoding the C printf() function. The main goal is to learn how to work with a variable number of arguments.Summaryft_printf is a custom implementation of the standard C library function printf. It formats and prints data to the standard output. This project handles several format specifiers and produces a static library (.a) that can be used in other C projects.Supported ConversionsThe following conversion specifiers are supported in this implementation:SpecifierOutput%cPrints a single character.%sPrints a string of characters.%pPrints a pointer's memory address in hex.%dPrints a signed decimal integer.%iPrints a signed integer in base 10.%uPrints an unsigned decimal integer.%xPrints a number in lowercase hexadecimal.%XPrints a number in uppercase hexadecimal.%%Prints a literal percent sign (%).How to Compile and Use1. Clone the RepositoryClone this repository to your local machine.2. Compile the LibraryNavigate to the root of the repository and run make:make
This will compile the source files and create a static library named libftprintf.a.3. Using the Library in Your ProjectTo use libftprintf.a in your own C project, you need to include the header file ft_printf.h and link the library during compilation.Example main.c:#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("The magic number is %d.\n", 42);
    ft_printf("A pointer address: %p\n", (void *)"hello");
    return (0);
}
Compilation Command:cc main.c -L. -lftprintf -o your_program_name
-L. tells the compiler to look for libraries in the current directory.-lftprintf links the libftprintf.a library.Makefile RulesThe included Makefile has the following rules:make all or make: Compiles the library libftprintf.a.make clean: Removes the object files (.o).make fclean: Removes the object files and the final library.make re: Runs fclean followed by all.
