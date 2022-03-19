#include "philo.h"

int	fill_struct(int argc, char **argv, philo_data *data)
{
	data->philos = ft_atoi(argv[1]);
	data->t_to_die = ft_atoi(argv[2]);
	data->t_to_eat = ft_atoi(argv[3]);
	data->t_to_sleep = ft_atoi(argv[4]);
	data->end = -1;
	data->philo_state = malloc(sizeof(int) * ft_atoi(argv[1]));
	if(argc == 6)
		data->end = ft_atoi(argv[5]);
	data->dead = 0;
	return (0);
}