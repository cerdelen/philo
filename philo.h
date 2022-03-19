#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>
#include "Libft/libft.h"

#include <stdio.h> //delete

enum
{
	THINKING=1,
	HUNGRY=2,
	EATING=3,
};  


typedef struct
{
	int	philos;
	int	t_to_die;
	int	t_to_eat;
	int t_to_sleep;
	int end;									//end condition
	int	dead;									//check if i have to end loops
	int	cycle;
	int	*philo_state;
	void			**forks;
	pthread_t		*philos;
	pthread_mutex_t	nbr;
	int				XD;
} philo_data;

int	check_arguments(int argc, char **argv);
int	fill_struct(int argc, char **argv, philo_data *data);
int	start_philosophers(philo_data *data);;

#endif