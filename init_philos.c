/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:17:55 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/22 23:18:01 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_philo(t_tabledata *table, int name, t_philo *philo)
{
	philo->name = name;
	philo->count_meals = 0;
	philo->t_last_meal = table->t_start;
	philo->t_ptr = table;
	philo->fork_1 = name - 1;
	if (name != table->philo_amount)
		philo->fork_2 = name;
	else
		philo->fork_2 = 0;
}

void	init_philos(t_tabledata *table)
{
	int	i;

	i = 0;
	while (i < table->philo_amount)
	{
		get_philo(table, i + 1, &table->philos[i]);
		i++;
	}
}
