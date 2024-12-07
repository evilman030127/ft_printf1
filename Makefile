NAME = libftprintf.a
src_f = ft_printf_tools.c ft_printf.c
obj_f = $(src_f:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
all: $(NAME)
$(NAME): $(obj_f)
	$(AR) $(NAME) $(obj_f)
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
clean:
	$(RM) $(obj_f)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
