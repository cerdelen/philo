/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:18:44 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/25 20:37:32 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	get_fork(void)
{
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	return (mutex);
}

void	init_forks(t_tabledata *table)
{
	int	i;

	i = 0;
	while (i < table->philo_amount)
	{
		table->forks[i] = get_fork();
		i++;
	}
}
