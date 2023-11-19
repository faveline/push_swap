NAME = push_swap

SRCS = ft_creat_stack.c			\
	   ft_ope_swap_push.c		\
	   ft_ope_reverse.c			\
	   ft_ope_rotate.c			\
	   ft_sort_stack.c			\
	   ft_utils_push_swap.c		\
	   ft_check_stack.c			\
	   ft_median.c				\
	   ft_max.c					\
	   ft_size_inf_five.c		\
	   ft_sort_loop.c			\
	   main.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
RM = rm -f
AR = ar rcs

all : $(NAME)

$(NAME):
	make -C libft/	
	$(CC) $(SRCS) libft/libft.a $(CFLAGS) -o $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -I. -c $< -o ${<:.c=.o}

clean :
	make clean -C libft/

fclean :
	make fclean -C libft/
	$(RM) $(NAME)

re : fclean all

.PHONY:	all clean fclean re
