#include "philo.h"

void	*get_mutex(void)
{
	pthread_mutex_t	a;

	pthread_mutex_init(&a, NULL);
	return (&a);
}

void	**init_forks(philo_data *data)
{
	void	**forks;
	int		i;
	int		x;

	i = 0;
	x = data->philos;
	forks = malloc(sizeof(void *) * x);
	if(!forks)
	{
		write(2, "Error with malloc of forks!\n", 28);
		return (NULL);
	}
	while(i < data->philos)
	{
		forks[i] = get_mutex();
		i++;
	}
	return (forks);
}

pthread_t	*init_philos(philo_data *data)
{
	pthread_t	*philos;
	int			x;

	x = data->philos;
	philos = malloc(sizeof(pthread_t) * x);
	if(!philos)
	{
		write(2, "Error with malloc of philos!\n", 29);
		return (NULL);
	}
	return (philos);
}

int	get_philo_name(philo_data *data)
{
	int	philo_name;

	thread_mutex_lock(&data->nbr);
	philo_name = data->XD;
	data->XD++;
	pthread_mutex_unlock(&data->nbr);
	return (philo_name);
}

void		do_think(philo_data *data)
{
	if (data->philo_state == THINKING)
		return (0);
}

void		*philo_life(void *arg)
{
	philo_data	*data;
	int			philo_name;

	data = (philo_data *) arg;
	philo_name = get_philo_name(data);
	while (1)
	{
		do_think(data);
		take_forks(data);
		do_eat(data);
		put_down_forks(data);
		check_if_any_dead(data);
		if (philo_name == data->philos)
			//no fork + 1
		

			//then somehow check if its even or odd cycle and then mutex for forks[philo_name] & forks [philo_name + 1]
	}

}

int	start_philosophers(philo_data *data)
{
	int			i;	

	i = 0;
	data->XD = 0;
	data->forks = init_forks(data);
	if(!data->forks)
		return (0);
	data->philos = init_philos(data);
	if (!data->philos)
		return (0);
	pthread_mutex_init(&data->nbr, NULL);
	while (i < data->philos)
	{
		pthread_create(&data->philos[i], NULL, &philo_life, data);
	}
	pthread_mutex_destroy(&data->nbr);
	return (1);
}
