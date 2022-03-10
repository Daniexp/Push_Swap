# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dexposit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:34:43 by dexposit          #+#    #+#              #
#    Updated: 2022/03/10 21:02:20 by dexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra -I.
LIBDIR = ./srcs/libft/
LIBFT = libft.a
SRCS	=	main.c ./srcs/argv_utils.c ./srcs/main_utils.c ./srcs/list_utils.c \
			./srcs/stack_moves.c
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
		@make bonus -C $(LIBDIR)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBDIR)$(LIBFT)

clean:
		@make clean -C $(LIBDIR)
		@$(RM) $(OBJS)

fclean:	clean
		@make fclean -C $(LIBDIR)
		@$(RM) $(NAME)

re:		fclean $(NAME)

bonus:

.PHONY: all clean fclean re
