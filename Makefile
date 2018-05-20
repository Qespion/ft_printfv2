CC          =     gcc
AR          =   ar
ARFLAGS     =     rc
CFLAGS      =     -Wall -Wextra -Werror
NAME        =     libftprintf.a
SRC         =     srcs/ft_printf.c	\
				  srcs/tools.c		\
				  srcs/ft_printable.c	\
				  srcs/ft_strlen.c	\
				  srcs/ft_putstr.c	\
				  srcs/ft_putchar.c	\
				  srcs/ft_strdel.c	\
				  srcs/ft_atoi.c	\
				  srcs/ft_putstrn.c	\
				  srcs/printable_adv.c	\
				  srcs/ft_putcharn.c


C_GREEN	=	"\033[32m"
C_BLUE	=	"\033[36m"
C_BASE	=	"\033[00m"

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(C_GREEN)"[PRINTFv2.1 PLUS FORT en pomme !]" $(C_BASE)
%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I includes/
	@echo "file =" $(C_BLUE){ $< } $(C_BASE)
clean:
	@rm -f $(OBJ)
	@echo $(C_GREEN)"[CLEAN]" $(C_BASE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
