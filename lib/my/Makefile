##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

SRC	=	my_is_prime.c\
		my_sort_int_array.c\
		my_str_isnum.c\
		my_strncpy.c\
		my_compute_power_rec.c\
		my_putchar.c\
		my_strcapitalize.c\
		my_strstr.c\
		my_compute_square_root.c\
		my_put_nbr.c\
		my_strcat.c\
		my_str_isupper.c\
		my_strupcase.c\
		my_find_prime_sup.c\
		my_putstr.c\
		my_strcmp.c\
		my_strlen.c\
		my_swap.c\
		my_getnbr.c\
		my_revstr.c\
		my_strcpy.c\
		my_strlowcase.c\
		my_showmem.c\
		my_str_isalpha.c\
		my_strncat.c\
		my.h\
		my_isneg.c\
		my_showstr.c\
		my_str_islower.c\
		my_strncmp.c\
		base8.c\
		base16.c\
		base16_min.c\
		base2.c\
		fill_str.c\
		base16to10.c\
		my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	copy_lib

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a *.o
	cp libmy.a ../
	cp my.h ../../include
	rm *.o

clean:
	rm ../libmy.a
	rm libmy.a
	rm ../../include/my.h
