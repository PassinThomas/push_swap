# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpassin <tpassin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 17:12:27 by tpassin           #+#    #+#              #
#    Updated: 2024/03/20 23:18:29 by tpassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

LIBFT = libft.a

SRCS =  main.c \
        srcs/check.c \
        srcs/utils/utils_1.c \
        srcs/utils/utils_2.c \
        srcs/swap.c \
        srcs/reverse_rotate.c \
        srcs/rotate.c \
        srcs/push.c \
        srcs/algo.c \
        srcs/utils/input_utils.c \
        srcs/update_index.c \
        srcs/big_algo.c \
        srcs/mouv.c \

BONUS = bonus/check_bonus.c \
		bonus/input_utils_bonus.c \
		bonus/push_bonus.c \
		bonus/reverse_rotate_bonus.c \
		bonus/rotate_bonus.c \
		bonus/swap_bonus.c \
		bonus/utils_1_bonus.c \
		bonus/utils_2_bonus.c \
		bonus/checker_bonus.c \

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}

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
	${RM} ${OBJS} ${BONUS_OBJS}
	$(MAKE) -C ./libft clean

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}
	$(MAKE) -C ./libft fclean

re: fclean all

bonus: ${BONUS_OBJS}
	$(MAKE) -C ./libft
	${CC} ${BONUS_OBJS} ${LFLAGS} -o $(NAME_BONUS)

.PHONY:  all clean fclean re bonus
