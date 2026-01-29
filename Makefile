# ============================================================================ #
#                                 PUSH_SWAP PROJECT                            #
#                           42 Madrid | by <laviles>                           #
# ============================================================================ #

# == Compilation Settings ==================================================== #

NAME        = push_swap
CC          = cc
MAKEFLAGS  += --no-print-directory

# == Sources ================================================================= #

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

CFLAGS      = -Wall -Wextra -Werror \
              -I. \
              -I$(LIBFT_DIR) \
              -I$(LIBFT_DIR)/get_next_line \
              -I$(LIBFT_DIR)/printf

SRCS        = push_swap.c arg_parse.c utils.c errors.c index.c push.c swap.c \
              rotate.c rev_rotate.c algorithm.c
OBJS        = $(SRCS:.c=.o)
# == Colores =================================================================== #

GREEN       = \033[0;32m
RESET       = \033[0m

# == Rules =================================================================== #

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) -s

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Built $(NAME)$(RESET)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Objects removed."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Executable and libraries removed."

re: fclean all

.PHONY: all clean fclean re
