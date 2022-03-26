/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:17:28 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/25 20:57:48 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_lunch(t_tabledata *table)
{
	int	i;

	i = 0;
	while (i < table->philo_amount)
	{
		pthread_create(&table->philos[i].thread_id, NULL, routine,
			&table->philos[i]);
		i++;
	}
}

int	have_all_eaten(t_tabledata *table)
{
	int	i;

	i = 0;
	while (i < table->philo_amount)
	{
		if (table->philos[i].count_meals < table->max_amount_of_meals
			|| table->max_amount_of_meals == -69)
			return (false);
		i++;
	}
	return (true);
}

int	check_for_end_loop(t_tabledata *table, int i)
{
	long long	time;

	while (i < table->philo_amount)
	{
		pthread_mutex_lock(&table->action_right);
		if (table->end_of_meal == true)
		{
			pthread_mutex_unlock(&table->action_right);
			return (1);
		}
		if (have_all_eaten(table) == true)
			table->end_of_meal = true;
		time = ft_get_time_ms() - table->t_start;
		if ((ft_get_time_ms() - table->philos[i].t_last_meal) > table->ttd)
		{
			table->end_of_meal = true;
			pthread_mutex_unlock(&table->action_right);
			printf("%lld %d died\n", time, table->philos[i].name);
			return (1);
		}
		pthread_mutex_unlock(&table->action_right);
		i++;
	}
	return (0);
}

void	check_for_end(t_tabledata *table)
{
	int			i;
	int			ret;

	while (1)
	{
		i = 0;
		ret = check_for_end_loop(table, i);
		if (ret == 1)
			return ;
	}
}

int	main(int argc, char **argv)
{
	t_tabledata	table;

	if (check_arguments(argc, argv))
		return (0);
	if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[1]) == 1)
	{
		ft_exception(argv);
		return (0);
	}
	set_up_table(&table, argc, argv);
	start_lunch(&table);
	check_for_end(&table);
	free_remains(&table);
}
