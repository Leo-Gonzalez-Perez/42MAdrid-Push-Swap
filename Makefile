# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 19:09:19 by lgonzal2          #+#    #+#              #
#    Updated: 2023/03/08 19:17:06 by lgonzal2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRC =	main.c prepare_data.c split_1.c split_2_and_atoi.c order_few_nbr.c\
errors.c motions_1.c motions_2.c

OBJ = $(SRC:.c=.o)
INCLUDE = push_swap.h

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) 

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all