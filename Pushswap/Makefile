NAME := push_swap

CC := cc
RM := rm -f

CFLAGS		= -Wall -Wextra -Werror
FT			= Libft
LIBFT		= $(FT)/libft.a

SOURCE := push_swap.c swap.c push.c rotate.c reverse_rotate.c lst_utils.c
OBJ 	= $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clear clean fclean re