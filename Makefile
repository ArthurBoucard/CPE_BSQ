##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC	=	main.c\
		prepare_map.c\
		find_bsq.c

NAME	=	bsq

LFLAGS	=	-L./lib

MFLAGS	=	-C./lib/my

IFLAGS	=	-I./include

all:	$(NAME)

$(NAME):
	make $(MFLAGS)
	cc -o $(NAME) $(SRC) $(LFLAGS) -lmy $(IFLAGS) -g

clean:
	rm -f $(NAME)

fclean:	clean
	make $(MFLAGS) clean

re:	fclean all
