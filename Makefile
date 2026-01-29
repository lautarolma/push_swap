# ============================================================================ #
#                                 PUSH_SWAP PROJECT                            #
#                           42 Madrid | by <laviles>                           #
# ============================================================================ #

# == Compilation Settings ==================================================== #

NAME        = push_swap
NAME_BONUS  = checker
CC          = cc
MAKEFLAGS  += --no-print-directory
CFLAGS      = -Wall -Wextra -Werror -g3 \
              -I$(INC_DIR) \
              -I$(LIBFT_DIR) \
              -I$(LIBFT_DIR)/get_next_line \
              -I$(LIBFT_DIR)/printf

# SRC Directories
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
SRC_DIR 	= src/
INC_DIR 	= include/
BONUS_DIR	= bonus/

# SRC Subdirectories
ALG_DIR = $(SRC_DIR)algorithm/
MOV_DIR = $(SRC_DIR)movements/
PAR_DIR = $(SRC_DIR)parser/
UTL_DIR = $(SRC_DIR)utils/

# SRC Files list (.c)
SRCS_COMMON = $(ALG_DIR)index.c \
              $(PAR_DIR)arg_parse.c \
              $(MOV_DIR)push.c \
              $(MOV_DIR)swap.c \
              $(MOV_DIR)rotate.c \
              $(MOV_DIR)rev_rotate.c \
              $(UTL_DIR)errors.c \
              $(UTL_DIR)utils.c

# Mandatory specific files
SRCS_MANDATORY = $(SRC_DIR)push_swap.c \
                 $(ALG_DIR)algorithm.c \
                 $(SRCS_COMMON)

# Bonus specific files
SRCS_BONUS	= $(BONUS_DIR)checker_bonus.c \
              $(SRCS_COMMON)

OBJS		= $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

# == Colores =================================================================== #

GREEN       = \033[0;32m
BLUE        = \033[0;34m
RESET       = \033[0m

# == Rules ==================================================================== #
all: $(LIBFT) $(NAME)

# Objects and library rules
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled.$(RESET)"

bonus: $(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(BLUE)$(NAME_BONUS) (bonus) compiled successfully.$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) -s
	@$(MAKE) -C $(LIBFT_DIR) bonus -s 2>/dev/null || true

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@echo "Objects removed."

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean -s
	@echo "Executable and libraries removed."

re: fclean all
# include "libft.h"
.PHONY: all clean fclean re bonus
# ============================================================================ #