# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 11:09:54 by vpelc             #+#    #+#              #
#    Updated: 2024/08/23 17:55:09 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

<<<<<<< HEAD
SOURCE = atol big_sort check_arg get_arg main \
operations_push operations_reverse_rotate operations_rotate \
operations_swap push_swap_utils small_sort sort_cases_check \
sort_cases_do sort_utils split
=======
SOURCE = atol big_sort check_arg get_arg main operations_push operations_reverse_rotate operations_rotate operations_swap push_swap_utils small_sort sort_cases_check sort_cases_do sort_utils split
>>>>>>> efb3468901d235e884adde065b5bbe725029c79c

SOURCES = $(addsuffix .c, ${SOURCE})

OBJECTS = ${SOURCES:.c=.o}

.c.o:
		${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
<<<<<<< HEAD
		make -C ./ft_printf
		${CC} ${CFLAGS} ${OBJECTS} ./ft_printf/libftprintf.a -o ${NAME} -I ./

all:	${NAME} 
=======
		${CC} -o ${NAME} ${OBJECTS}
>>>>>>> efb3468901d235e884adde065b5bbe725029c79c

clean:
		${RM} ${OBJECTS}
		$(MAKE) -C ./ft_printf fclean

fclean:		clean
		${RM} ${NAME} 

re:		fclean all
	
.PHONY: all clean fclean re 