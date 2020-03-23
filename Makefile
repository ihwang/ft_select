NAME = ft_select

SRCS_PATH = src/
LIBFT_PATH = libft/

FLAGS = -Wall -Werror -Wextra
TERMCAP = -ltermcap
INC = -I ./includes/ -I ./libft/includes

SRCS_NAME = main.c \
			function_keys.c \
			parse_key.c \
			print_args.c \
			sig_set.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS_NAME:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc -c $(FLAGS) $(INC) $(SRCS)
	@gcc $(FLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME) $(TERMCAP)

clean:
	@make -C ./libft clean
	@/bin/rm -f *.o

fclean: clean
	@make -C ./libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
