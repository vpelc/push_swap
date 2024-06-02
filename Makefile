# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 11:09:54 by vpelc             #+#    #+#              #
#    Updated: 2024/05/28 20:07:43 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

AR = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SOURCE = 

SOURCES = $(addsuffix .c, ${SOURCE})

OBJECTS = ${SOURCES:.c=.o}

all:	${NAME} 

.c.o:
		${CC} ${CFLAGS} -I ./ -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
		${AR} ${NAME} ${OBJECTS}

clean:
		${RM} ${OBJECTS} 

fclean:		clean
		${RM} ${NAME} 

re:		fclean all
	
.PHONY: all clean fclean re 