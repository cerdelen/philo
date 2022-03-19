# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:02:11 by Cerdelen          #+#    #+#              #
#    Updated: 2022/03/13 20:44:57 by cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Wall -Werror

NAME = philo

AR = ar rcs

SRCS = 	main.c setup_struct.c check_arg.c start_philosophers.c

OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(MAKE) -C Libft	
	$(AR) $(NAME).a $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) philo.a ./Libft/libft.a

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	$(MAKE) fclean -C Libft
	$(RM) $(OBJS) $(NAME).a

fclean: clean
	$(RM) $(NAME) 

re: fclean all