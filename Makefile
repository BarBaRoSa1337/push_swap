# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achakour <achakour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 14:53:03 by achakour          #+#    #+#              #
#    Updated: 2024/03/04 12:34:12 by achakour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap_utils.c	push_swap.c	stack_recovery.c	moves.c	lst_utils.c	ft_lbft_split.c	find_lsi_sequence.c	\
	count_push_price.c	chekers.c

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
AR = ar rcs
RM = rm -f
CC = cc

all:$(NAME)

$(NAME):$(OBJ)

%.o :%.c
	$(CC) -c $(CFLAGS) $^ -o $@
	$(AR) $(NAME) $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all