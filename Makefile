# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 11:09:54 by vpelc             #+#    #+#              #
#    Updated: 2024/08/18 15:02:43 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SOURCE = atol big_sort check_arg get_arg main \
operations_push operations_reverse_rotate operations_rotate \
operations_swap push_swap_utils small_sort sort_cases_check \
sort_cases_do sort_utils split

SOURCES = $(addsuffix .c, ${SOURCE})

OBJECTS = ${SOURCES:.c=.o}

.c.o:
		${CC}  -g -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
		make -C ./ft_printf
		${CC} ${CFLAGS} ${OBJECTS} ./ft_printf/libftprintf.a -o ${NAME} -I ./

all:	${NAME} 

clean:
		${RM} ${OBJECTS}
		$(MAKE) -C ./ft_printf fclean

fclean:		clean
		${RM} ${NAME} 

re:		fclean all
	
.PHONY: all clean fclean re 