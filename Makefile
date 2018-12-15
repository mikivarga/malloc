ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so
LIB = libft_malloc_$(HOSTTYPE).so

PATH_SRC = src
PATH_OBJ = obj
PATH_INC = inc

SRC = $(addprefix $(PATH_SRC)/, malloc.c)
OBJ = $(SRC:$(PATH_SRC)/%.c=$(PATH_OBJ)/%.o)
INC = $(addprefix $(PATH_INC)/, alloc_in_heap.h)

FLAGS = -Wall -Wextra -Werror
CC = gcc

RED = \033[01;31m
GREEN = \033[01;32m
YELLOW = \033[01;33m
BLUE = \033[01;34m
PINK = \033[01;35m
CYAN = \033[01;36m
WHITE = \033[01;37m
RESET = \033[00m]

all: $(NAME)

$(NAME): $(LIB)
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
	rm -rf $(OBJ)
	rm -rf $(PATH_OBJ)
	@echo "$(BLUE)clean:$(RESET)\t(OBJ)"

fclean:
	rm -rf $(NAME)
	@echo "$(BLUE)clean:$(RESET)\t(NAME)"
	rm -rf $(LIB)
	@echo "$(BLUE)clean:$(RESET)\t(LIB)"

re: fclean all

.PHONY: clean fclean re