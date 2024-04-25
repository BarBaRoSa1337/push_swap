# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achakour <achakour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 14:53:03 by achakour          #+#    #+#              #
#    Updated: 2024/04/25 15:58:45 by achakour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap_utils.c \
		push_swap.c \
		stack_recovery.c \
		moves.c \
		lst_utils.c \
		find_lsi_sequence.c	\
	    count_push_price.c	\
		chekers.c \
		extra_utils.c \
		ft_split.c \
		extra_utils2.c \
		extra_utils3.c checker_linux.c get_next_line.c 

OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
NAME = push_swap
RM = rm -rf
CC = cc

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re