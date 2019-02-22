ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so
LIB_MALLOC = libft_malloc_$(HOSTTYPE).so

FLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib

SRC = $(addprefix $(SRC_DIR)/, malloc.c realloc.c free.c lst_block.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC = $(addprefix $(INC_DIR)/, alloc_in_heap.h)

LIBFT_DIR = $(LIB_DIR)/ft_printf
LIBFT = $(LIBFT_DIR)/libftprintf.a
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT_FLAGS = -ltf -L$(LIBFT_DIR)

LINK_FLAGS = $(LIBFT_FLAGS)
HEADER_FLAGS = -I $(LIBFT_INC) -I $(INC_DIR)

RED = \033[01;31m
GREEN = \033[01;32m
YELLOW = \033[01;33m
BLUE = \033[01;34m
PINK = \033[01;35m
RESET = \033[00m

all: $(LIBFT) $(NAME)

$(NAME): $(LIB_MALLOC) 
	@ln -s $^ $@
	@echo "$(YELLOW)make:$(RESET)\t$@"

$(LIB_MALLOC): $(OBJ)
	$(CC) -shared -fPIC $^ -o $@ $(LIBFT)
	@echo "$(YELLOW)make:$(RESET)\t$@"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)create:$(RESET)\t$(OBJ_DIR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(CC) -fPIC $(FLAGS) -c $< -o $@ $(HEADER_FLAGS)
	@echo "$(GREEN)compil:$(RESET)\t$@"

$(LIBFT) :
	@make -C $(LIBFT_DIR)

clean :
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)clean:$(RESET)\t$(OBJ)"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(LIB_MALLOC)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)fclean:$(RESET)\t$(NAME)"

re : fclean all

.PHONY: clean fclean re

#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.