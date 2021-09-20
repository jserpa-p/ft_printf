# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 15:42:52 by jserpa-p          #+#    #+#              #
#    Updated: 2021/05/07 12:07:06 by jserpa-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard ./*.c)

OBJS	= ${SRCS:.c=.o}

BONUS	=	ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\

BONUS_OBJS	= ${BONUS:.c=.o}

NAME	= libft.a

CC		= gcc
ARRC	= ar rcs
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

$(NAME):	${OBJS}
			${ARRC} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:	${OBJS} ${BONUS_OBJS}
			${ARRC} ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY: all clean fclean re