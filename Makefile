# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achakour <achakour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 14:53:03 by achakour          #+#    #+#              #
#    Updated: 2024/04/14 12:51:00 by achakour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap_utils.c push_swap.c stack_recovery.c moves.c lst_utils.c find_lsi_sequence.c	\
	count_push_price.c	chekers.c extra_utils.c extra_utils2.c

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