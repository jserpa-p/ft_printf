# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 15:25:24 by jserpa-p          #+#    #+#              #
#    Updated: 2021/05/24 13:07:58 by jserpa-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard ./srcs/*.c) $(wildcard ./ft_printf.c)

LIBFT	=	./libft/libft.a

NAME	= 	libftprintf.a

OBJS = ${SRCS:.c=.o}

INCS	=	-I includes

CC		=	gcc
ARRC	=	ar rcs
RM		=	rm -f
CLIB	=	ar -rc
CFLAGS	=	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} $(INCS)

all:	${NAME}

bonus:	${NAME}

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp $(LIBFT) $(NAME)
	$(CLIB) $(NAME) $(OBJS)


clean:	
	$(MAKE) clean -C ./libft
	${RM} ${OBJS}

fclean:		clean
	$(MAKE) fclean -C ./libft
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re