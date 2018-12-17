ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so
LIB = libft_malloc_$(HOSTTYPE).so

PATH_SRC = src
PATH_OBJ = obj
PATH_INC = inc
PRINTF_DIR = ../ft_printf/
LIBFT_DIR = ../libft/

SRC = $(addprefix $(PATH_SRC)/, malloc.c)
OBJ = $(SRC:$(PATH_SRC)/%.c=$(PATH_OBJ)/%.o)
INC = $(addprefix $(PATH_INC)/, alloc_in_heap.h)

FLAGS = -Wall -Wextra -Werror
CC = gcc

PRINTF = $(PRINTF_DIR)libft.a
PRINTF_INC = $(PRINTF_DIR)inc
PRINTF_FLAGS = -ltf -L$(PRINTF_DIR)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_INC = $(LIBFT_DIR)inc
LIBFT_FLAGS = -ltf -L$(LIBFT_DIR)

LINK_FLAGS = $(LIBFT_FLAGS) $(PRINTF_FLAGS)
HEADER_FLAGS = -I $(INC_DIR) -I $(LIBFT_INC) -I $(PRINTF_INC)


RED = \033[01;31m
GREEN = \033[01;32m
YELLOW = \033[01;33m
BLUE = \033[01;34m
PINK = \033[01;35m
CYAN = \033[01;36m
WHITE = \033[01;37m
RESET = \033[00m]

all: $(NAME)

$(NAME): $() $(LIB)
	ln -s $^ $@
	@echo "$(PINK)link:$(RESET)\t$@"

$(LIB): $(OBJ)
	$(CC) -shared $^ -o $@
	@echo "$(GREEN)make:$(RESET)\t$@"

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c $(INC)
	mkdir -p $(PATH_OBJ)
	$(CC) $(FLAGS) -c $< -o $@ -I $(PATH_INC)
	@echo "$(YELLOW)compil:$(RESET)\t$@"




clear:
	@rm -f $(OBJ)
	@rm -rf $(PATH_OBJ)
	@make clean -C $(PRINTF_DIR)
	@echo "$(RED)clean:$(RESET)\t$(OBJ)"

fclean:
	@rm -f $(NAME)
	@rm -rf $(LIB)
	@make fclean -C $(PRINTF_DIR)
	@echo "$(RED)clean:$(RESET)\t$(NAME)"
	@echo "$(RED)clean:$(RESET)\t$(LIB)"

re: fclean all

.PHONY: clean fclean re