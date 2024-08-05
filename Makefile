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

SOURCE = atol big_sort check_arg get_arg main operations_push operations_reverse_rotate operations_rotate operations_swap push_swap_utils small_sort sort_cases_check sort_cases_do sort_utils split

SOURCES = $(addsuffix .c, ${SOURCE})

OBJECTS = ${SOURCES:.c=.o}

all:	${NAME} 

.c.o:
		${CC} ${CFLAGS} -I ./ -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
		${CC} -o ${NAME} ${OBJECTS}

clean:
		${RM} ${OBJECTS} 

fclean:		clean
		${RM} ${NAME} 

re:		fclean all
	
.PHONY: all clean fclean re 