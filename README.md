# ft_print
## NAME
ft_print - an alternative to printf compatible with "42" (school) with some extras.  
 
## LIBRARY
Standard C library (unistd)  

## SYNOPSIS
	#include <unistd.h>
 
 	int	ft_print(char *str, void *val)

## DESCRIPTION
ft_print() write the str input, replacing the "%" with the val input.  
There is 7 types of "%":
- "%d" = int
- "%f" = float
- "%c" = char
- "%s" = str
- "%d{nb}" = array of int
- "%s{nb}" = array of str
- "%d{rows}|{cols}" = matrix (int) with number of rows and number of columns  

You have to give a space between the '%' and the rest of the str.  

## RETURN VALUE
In case of error ft_print() return 1, else 0.  
The main purpose of ft_print() is not to return a result but to print, but the return value can say if the function print successfully.

## NOTES
The manual teach you how to use it but if you prefere to learn with examples there is a makefile and a test.c file.  
How to use the makefile:
- "make" = execute the program with test.c
- "make +" = execute and display warnings and makefile output
- "make clean" = clean the output file
