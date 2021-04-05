# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 16:07:03 by mzhan             #+#    #+#              #
#    Updated: 2021/04/05 14:58:18 by mzhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS	 		= ${SRCS:.c=.o}

CFLAGS			= -Wall -Werror -Wextra -c

SRCS 			= ft_printf_flags.c \
				  ft_convert_percentage_percentage.c \
				  ft_convert_percentage_c.c \
				  ft_printf.c \
				  ft_convert_percentage_d.c \
				  ft_convert_percentage_s.c \
				  ft_convert_percentage_u.c \
				  ft_putunsign_fd.c \
				  ft_convert_percentage_x.c \
				  ft_convert_percentage_X.c \
				  ft_convert_percentage_p.c \


INCLUDE			= ft_printf.h


NAME			= libftprintf.a

RM				= rm -f

all : ${NAME}

${NAME}	:  ${OBJS} ${INCLUDE}
			make -C ./libft
			mv libft/libft.a .
			mv libft.a ${NAME}
			ar rcs ${NAME} ${OBJS}

${OBJS}:	${SRCS}
			gcc ${CFLAGS} ${SRCS} -I ${INCLUDE} -I ./libft/libft.h

clean :
			make -C ./libft clean
			${RM} ${OBJS}

fclean :	clean
			make -C ./libft fclean
			${RM} ${NAME}

re: 		fclean all
				
