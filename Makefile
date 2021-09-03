NAME = libftprintf.a
CC = gcc

INCLUDE = ./includes/	\

SRCS =	atoi.c				\
		check.c				\
		ft_printf.c			\
		itoa.c				\
		pre_print_diuxX.c	\
		print_c.c			\
		print_di.c			\
		print_final.c		\
		print_u.c			\
		print_xX.c			\
		print_s.c			\
		utils.c				\
		print_p.c			\

CFLAGS = -Wall -Wextra -Werror -Iincludes

OBJS	= $(SRCS:.c=.o)

.o.c :
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			ar -rc $(NAME) $(OBJS)

bonus	:	$(OBJS)
			ar -rc $(NAME) $(OBJS)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re	:	fclean	all

.PHONY	:  all clean fclean re
