# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labenall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:04:26 by labenall          #+#    #+#              #
#    Updated: 2022/03/15 18:41:47 by labenall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c action.c exit_free_malloc.c validation.c sort.c 

OBJFD  = temporary

OBJ = $(addprefix $(OBJFD)/,$(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(OBJFD):
	mkdir $@

$(OBJFD)/%.o: %.c | $(OBJFD)
	gcc -g $(FLAGS)  -c $< -o $@ 

$(NAME): $(OBJ)
	gcc -g $(OBJ)  -o $@ 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJFD)

re: fclean all

.PHONY: all clean fclean re
