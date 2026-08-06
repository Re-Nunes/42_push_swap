NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra # -Werror
LDFLAGS = -L./libft
LDLIBS  = -lft

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

INC_DIR	= includes
SRC_DIR	= srcs
OBJ_DIR	= objs

INCLUDES	= -I $(INC_DIR) -I $(LIBFT_DIR)

SRCS_FILES	= \
	parsing_utils.c \
	parsing.c \
	stack_utils.c \
	teste.c
#aqui vem todos os arquivos .c que ainda vamos criar

SRCS	= $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDLIBS) $(LDFLAGS)

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

.PHONY: all clean fclean 
