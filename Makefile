# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 20:10:28 by mponomar          #+#    #+#              #
#    Updated: 2018/07/15 20:10:34 by mponomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = src/
INC = includes/wolf3d.h
LIBFT = libft/
FT_INC = $(LIBFT)/includes

CMP =	main.o \
		hooks.o \
		initdata.o \
		threads.o

all: $(NAME)

$(NAME): $(CMP) $(INC)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L $(LIBFT) -lft $(CMP)
	@echo "made" $(NAME)

$(CMP): %.o: $(SRC)%.c
	@$(CC) -c $(FLAGS) -I $(FT_INC) -I $(INC) $< -o $@

clean:
	@-/bin/rm -f $(CMP)
	@-make clean -C $(LIBFT)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@-make fclean -C $(LIBFT)
	@echo "fcleaned" $(NAME)

re: fclean all

rmf:
	rm *~
	rm \#*
	rm *.out
