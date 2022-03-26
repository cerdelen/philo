# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:02:11 by Cerdelen          #+#    #+#              #
#    Updated: 2022/03/25 21:02:21 by cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Wall -Werror -pthread

NAME = philo

AR = ar rcs

SRCS = 	philo_actions_2.c routine.c main.c check_arg.c helper_func.c init_forks.c  init_philos.c  philo_actions.c  set_table.c ft_atoi.c  ft_bzero.c  ft_calloc.c  ft_isdigit.c  ft_strlen.c

OBJS = $(SRCS:.c=.o)

all: 
	$(CC) $(CFLAGS) -o  $(NAME) $(SRCS)

clean:
	

fclean:
	$(RM) $(NAME) 

re: fclean all