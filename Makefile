# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 17:12:27 by tpassin           #+#    #+#              #
#    Updated: 2024/02/29 03:57:17 by tpassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

SRCS =	main.c \
		srcs/check.c \
		srcs/utils/utils_1.c \
		srcs/utils/utils_2.c \
		srcs/swap.c \
		srcs/reverse_rotate.c \
		srcs/rotate.c \
		srcs/push.c \
		srcs/algo.c \
		
OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -g3 -g -Wall -Wextra -Werror

LFLAGS = -L./libft -lft

RM = rm -f

all: ${NAME}

$(NAME): ${OBJS}
	$(MAKE) -C ./libft
	${CC} ${OBJS} ${LFLAGS} -o $(NAME)
	
%.o:%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}
	$(MAKE) -C ./libft clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY:  all clean fclean re
