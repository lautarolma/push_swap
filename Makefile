# ============================================================================ #
#                                 PUSH_SWAP PROJECT                            #
#                           42 Madrid | by <laviles>                           #
# ============================================================================ #

# == Compilation Settings ==================================================== #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)

# == Sources ================================================================= #

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = push_swap.c arg_parse.c utils.c errors.c index.c push.c swap.c rotate.c rev_rotate.c algorithm.c

OBJS        = $(SRCS:.c=.o)
# == Colores =================================================================== #

GREEN       = \033[0;32m
RESET       = \033[0m

# == Rules =================================================================== #

all: $(LIBFT) $(NAME)

# La regla NAME depende de los objetos Y de la librería
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compilado.$(RESET)"

# Compila la libft llamando a su propio Makefile
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) -s

# Regla genérica para compilar .c en .o (evita relinking)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@echo "Objetos eliminados."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean -s
	@echo "Ejecutable y librerías eliminados."	

re: fclean all

.PHONY: all clean fclean re
