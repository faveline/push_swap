NAME = push_swap

NAME_CHECKER = checker

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

SRCS_CHECKER = ft_creat_stack.c			\
			   ft_ope_swap_push_bonus.c	\
			   ft_ope_reverse_bonus.c	\
			   ft_ope_rotate_bonus.c	\
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
			   ft_checker.c				\
			   ft_read_push.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
RM = rm -f
AR = ar rcs

all : $(NAME)

$(NAME):
	make -C libft/	
	$(CC) $(SRCS) libft/libft.a $(CFLAGS) -o $(NAME)

bonus:
	make -C libft/	
	$(CC) $(SRCS) libft/libft.a $(CFLAGS) -o $(NAME)
	$(CC) $(SRCS_CHECKER) libft/libft.a $(CFLAGS) -o $(NAME_CHECKER)


%.o: %.c libft.h
	$(CC) $(CFLAGS) -I. -c $< -o ${<:.c=.o}

clean :
	make clean -C libft/

fclean :
	make fclean -C libft/
	$(RM) $(NAME)
	$(RM) $(NAME_CHECKER)

re : fclean all

.PHONY:	all clean fclean re
