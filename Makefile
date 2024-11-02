# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 16:04:52 by lpolizzi          #+#    #+#              #
#    Updated: 2024/11/02 21:42:02 by lpolizzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR)

# Directories
INCDIR = include
SRCDIR = srcs
LIBFTDIR = libft

# Source files
SRC = $(SRCDIR)/checks.c \
      $(SRCDIR)/get_cost.c \
      $(SRCDIR)/get_pos.c \
      $(SRCDIR)/get_target.c \
      $(SRCDIR)/init.c \
      $(SRCDIR)/main.c \
      $(SRCDIR)/operations.c \
      $(SRCDIR)/push.c \
      $(SRCDIR)/reverse_rotate.c \
      $(SRCDIR)/rotate.c \
      $(SRCDIR)/sort.c \
      $(SRCDIR)/stack_utils.c \
      $(SRCDIR)/swap.c \
      $(SRCDIR)/utils.c \
      $(SRCDIR)/error_msg.c \
      $(SRCDIR)/free_all.c \
      $(SRCDIR)/move_stack.c

OBJ = $(SRC:.c=.o)

# Libraries
LIBFT = $(LIBFTDIR)/libft.a

# Output executable
NAME = push_swap

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFTDIR) -lft

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

# Clean rules
clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFTDIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
