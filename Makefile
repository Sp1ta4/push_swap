NAME = push_swap
BNAME = checker

SRC_DIR = src
BONUS_DIR = bonus
LIBFT_DIR = libft
INCLUDE = -I includes

SRCS = $(shell find $(SRC_DIR) -maxdepth 1 -name "*.c")
SRCS_B = $(shell find $(BONUS_DIR) -maxdepth 1 -name "*.c")

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
LIBFT = $(LIBFT_DIR)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -Llibft -lft -o $(NAME)

bonus: $(LIBFT) $(OBJS_B)
	$(CC) $(CFLAGS)  $(INCLUDE) $(OBJS_B) -Llibft -lft -o $(BNAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BNAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
