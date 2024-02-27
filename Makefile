# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 17:12:27 by tpassin           #+#    #+#              #
#    Updated: 2024/02/26 05:18:00 by tpassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

SRCS =	main.c \
		srcs/check.c \
		srcs/utils/utils_1.c \
		
OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror

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
