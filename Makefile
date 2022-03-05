# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dexposit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:34:43 by dexposit          #+#    #+#              #
#    Updated: 2022/03/05 13:14:11 by dexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra -I.
LIBFT = ./srcs/libft/libft.a
SRCDIR = ./srcs/
SRCS = argv_utils.c
MAIN = main.c
OBJS = $(SRCDIR)$(SRCS:.c=.o) $(MAIN:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
		@make bonus -C ./srcs/libft
		@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
		@make clean -C ./srcs/libft
		@$(RM) $(OBJS)

fclean:	clean
		@make fclean -C ./srcs/libft
		@$(RM) $(NAME)

re:		fclean $(NAME)

bonus:

.PHONY: all clean fclean re
