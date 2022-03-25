# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dexposit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:34:43 by dexposit          #+#    #+#              #
#    Updated: 2022/03/25 19:48:05 by dexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONNAME = checker
CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra -I.
LIBDIR = ./srcs/libft/
LIBFT = libft.a
SRCS	=	main.c ./srcs/argv_utils.c ./srcs/main_utils.c ./srcs/list_utils.c	\
			./srcs/stack_moves.c ./srcs/filter_moves.c ./srcs/stack_utils.c		\
			./srcs/three_numbers.c ./srcs/five_numbers.c ./srcs/chunks.c		\
			./srcs/create_chunks.c ./srcs/move_chunks.c

BONSRC	=	./srcs/checker/checker.c ./srcs/checker/gnl/get_next_line.c			\
			./srcs/checker/gnl/get_next_line_utils.c ./srcs/argv_utils.c		\
			./srcs/main_utils.c ./srcs/list_utils.c ./srcs/stack_moves.c		\
			./srcs/filter_moves.c

OBJS	=	$(SRCS:.c=.o)

BONOBJ	=	$(BONSRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
		@make bonus -C $(LIBDIR)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBDIR)$(LIBFT)

clean:
		@make clean -C $(LIBDIR)
		@$(RM) $(OBJS) $(BONOBJ)

fclean:	clean
		@make fclean -C $(LIBDIR)
		@$(RM) $(NAME) $(BONNAME)

re:		fclean $(NAME)

bonus:	$(BONNAME)

$(BONNAME):	$(NAME) $(BONOBJ)
		@$(CC) $(FLAGS) -o $(BONNAME) $(BONOBJ) $(LIBDIR)$(LIBFT)

.PHONY: all clean fclean re
