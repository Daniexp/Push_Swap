# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dexposit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:34:43 by dexposit          #+#    #+#              #
#    Updated: 2022/03/02 17:28:04 by dexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra -I.
LIBFT = ./libft/libft.a
LIBOBJ = ./libft/*.o
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
		@make bonus -C ./libft
		@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
		@make clean -C ./libft
		@$(RM) $(OBJS)

fclean:	clean
		@make fclean -C ./libft
		@$(RM) $(NAME)

re:		fclean $(NAME)

bonus:

.PHONY: all clean fclean re
