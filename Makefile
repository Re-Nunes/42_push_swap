NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LDFLAGS = -L./libft
LDLIBS  = -lft

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = objs

INCLUDES    = -I $(INC_DIR) -I $(LIBFT_DIR)

# Lista completa de todos os arquivos fonte do projeto organizados por pastas
# Lista completa de todos os arquivos fonte do projeto
SRCS_FILES  = \
    main.c \
    parsing/parsing.c \
    parsing/parsing_utils.c \
    parsing/stack_utils.c \
    parsing/error.c \
    algorithms/compute_disorder.c \
    algorithms/strategy.c \
    algorithms/index.c \
    algorithms/bubble_sort.c \
    algorithms/bucket_sort.c \
    algorithms/radix_sort.c \
    operations/push.c \
    operations/swap.c \
    operations/rotate.c \
    operations/reverse_rotate.c

SRCS    = $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS    = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re