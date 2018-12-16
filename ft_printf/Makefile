NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)/inc

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

SRC =	$(addprefix $(SRC_DIR)/, conversions_c_wc.c \
		conversions_signed_digit.c\
		conversions_str.c\
		conversions_unsigned_digit.c\
		conversions_wstr.c\
		conversions_pointer.c\
		flags.c\
		ft_printf.c\
		get_data_from_va_list.c\
		print.c\
		pr_point.c\
		print_digits.c)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC = $(addprefix $(INC_DIR)/, ft_printf.h)

RED = \033[01;31m
GREEN = \033[01;32m
YELLOW = \033[01;33m
BLUE = \033[01;34m
PINK = \033[01;35m
RESET = \033[00m

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "$(YELLOW)make:$(RESET)\t$@"

$(LIBFT) :
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) ./$(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)create:$(RESET)\t$(OBJ_DIR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(CC) $(FLAGS)  -c $< -o $@ -I $(INC_DIR)
	@echo "$(GREEN)compil:$(RESET)\t$@"

clean :
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)clean:$(RESET)\t$(OBJ)"
	@make clean -C $(LIBFT_DIR)

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)fclean:$(RESET)\t$(NAME)"
	@make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY: clean fclean re