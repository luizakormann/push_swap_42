# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 18:13:07 by lukorman          #+#    #+#              #
#    Updated: 2025/05/04 18:17:05 by lukorman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                               configuration                                  #
# **************************************************************************** #

# common comp
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -rf

# **************************************************************************** #
#                                directories                                   #
# **************************************************************************** #

# common structure
INC_DIR	= include
SRC_DIR	= src/
OBJ_DIR	= obj/
BIN_DIR	= bin/
LIB_DIR = libft


# **************************************************************************** #
#                                  ext libs                                    #
# **************************************************************************** #

# libft
LIBFT = $(LIB_DIR)/bin/libft.a
LIBFT_FLAGS = -L$(LIB_DIR)/bin -lft

# **************************************************************************** #
#                                   files                                      #
# **************************************************************************** #

# executable
NAME	= $(BIN_DIR)push_swap

# header
HEADERS = $(shell find $(INC_DIR) -name '*.h')

# sources
SRC	= $(shell find $(SRC_DIR) -name '*.c')

# objects
OBJS = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))

# **************************************************************************** #
#                              compile commands                                #
# **************************************************************************** #

# comb flags
CFLAGS += -I$(LIB_DIR)/include
LDFLAGS += $(LIBFT_FLAGS)

# comp
COMP_OBJS	= $(CC) $(CFLAGS) -c $< -o $@
COMP	= $(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# **************************************************************************** #
#                                  targets                                     #
# **************************************************************************** #

all: git_submodule $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(COMP_OBJS)

$(NAME): $(LIBFT) $(OBJS)
	mkdir -p $(BIN_DIR)
	$(COMP)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR) all

MAP ?= maps/test.ber

LEAKS	:=	valgrind --leak-check=full --show-leak-kinds=all\
		--track-origins=yes --log-file=valgrind-out.txt --track-fds=yes

supmlx: all
	@$(LEAKS) ./bin/so_long $(MAP)

git_submodule:
	git submodule update --init --recursive

clean:
	$(RM) $(OBJ_DIR)
	$(RM) valgrind-out.txt

fclean: clean
	$(RM) $(BIN_DIR)
	$(RM) valgrind-out.txt
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re git_submodule
