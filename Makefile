# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 17:12:27 by tpassin           #+#    #+#              #
#    Updated: 2024/02/21 18:05:17 by tpassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	main.c \
		srcs/utils/ft_split.c \
		srcs/check.c \
		srcs/utils/utils_1.c \
		
OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror

RM = rm -f

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${OBJS} -o $(NAME)
	
%.o:%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:  all clean fclean re
