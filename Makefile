ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so
LIB_MALLOC = libft_malloc_$(HOSTNAME).so

FLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib

SRC = $(addprefix $(PATH_SRC)/, malloc.c)
OBJ = $(SRC:$(PATH_SRC)/%.c=$(PATH_OBJ)/%.o)
INC = $(addprefix $(PATH_INC)/, alloc_in_heap.h)

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

all: $(NAME)

$(NAME): $(LIBFT) $(LIB_MALLOC) 
	@ln -s $^ $@
	@echo "$(YELLOW)make:$(RESET)\t$@"

$(LIB_MALLOC): $(OBJ)
	$(CC) $(HEADER_FLAGS) -shared $^ -o $@ $(FLAGS) $(LINK_FLAGS) -libftprintf.a
	@echo "$(YELLOW)make:$(RESET)\t$@"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)create:$(RESET)\t$(OBJ_DIR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(CC) $(HEADER_FLAGS) -c $< -o $@ $(FLAGS) #$(LINK_FLAGS) -libftprintf.a
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
	@rm -f $(LIB_MALLOC)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)fclean:$(RESET)\t$(NAME)"

re : fclean all

.PHONY: clean fclean re