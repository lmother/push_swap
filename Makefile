# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmother <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 15:28:34 by lmother           #+#    #+#              #
#    Updated: 2021/06/06 15:42:00 by lmother          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_LIB		=	./Libft
LIBFT		=	libft.a
INC			=	./includes/push_swap.h

NAME		=	push_swap
SRCS		=	push_swap.c\
				check_stack.c\
				q_sort_arr.c\
				instructions.c\
				instructions1.c\
				sort_3_5_digits.c\
				sort.c\
				instructions2.c\
				sort_1.c\
				push_swap_2.c\
				check_steck_2.c\
				init_stack.c\

BNAME		=	checker
BSRCS		=	get_next_line.c\
				get_next_line_utils.c\
				instructions.c\
				instructions1.c\
				instructions2.c\
				push_swap_2.c\
				check_stack.c\
				q_sort_arr.c\
				init_stack.c\
				check_steck_2.c\
				checker.c\

BINC		=	./includes/get_next_line.h
BOBJS		=	$(BSRCS:.c=.o)
OBJS		=	$(SRCS:.c=.o)

%.0:%.c
			$(CC) $(CFLAGS) -c -o $@ $<

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g -include $(INC)

all:		$(NAME)

bonus:		$(BNAME)

$(NAME):	$(OBJS)
			$(MAKE) -C $(SRC_LIB)
			$(CC) $(CFLAGS) -c $(SRCS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(SRC_LIB)/$(LIBFT)

$(BNAME):	$(BOBJS)
			$(MAKE) -C $(SRC_LIB)
			$(CC) $(CFLAGS) -c $(BSRCS)
			$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS) $(SRC_LIB)/$(LIBFT)

clean:
			$(MAKE) clean -C $(SRC_LIB)
			$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(MAKE) clean -C $(SRC_LIB)
			$(RM) $(NAME) $(BNAME)

re :		fclean all

.PHONY:	all clean fclean re bonus
