NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = ../libft/

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

LIBFT_DIR = $(LIB_DIR)
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_INC = $(LIBFT_DIR)inc
LIBFT_FLAGS = -ltf -L$(LIBFT_DIR)

LINK_FLAGS = $(LIBFT_FLAGS)
HEADER_FLAGS = -I $(LIBFT_INC) -I $(INC_DIR)

RED = \033[01;31m
GREEN = \033[01;32m
YELLOW = \033[01;33m
BLUE = \033[01;34m
PINK = \033[01;35m
RESET = \033[00m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "$(YELLOW)make:$(RESET)\t$@"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)create:$(RESET)\t$(OBJ_DIR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(CC) $(HEADER_FLAGS) -c $< -o $@ $(FLAGS)
	@echo "$(GREEN)compil:$(RESET)\t$@"

$(LIBFT) :
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) ./$(NAME)

clean :
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)clean:$(RESET)\t$(OBJ)"

fclean : clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)fclean:$(RESET)\t$(NAME)"

re : fclean all

.PHONY: clean fclean re