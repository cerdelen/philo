/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:57:34 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/25 20:57:35 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time_differece_last_meal(t_philo *philo)
{
	return (ft_get_time_ms() - philo->t_ptr->t_start - philo->t_last_meal);
}

void	routine_loop(t_philo *philo)
{
	while (!philo->t_ptr->end_of_meal)
	{
		ft_grab_fork1(philo);
		if (ft_get_time_differece_last_meal(philo) > philo->t_ptr->ttd)
			return ;
		ft_grab_fork2(philo);
		if (ft_get_time_differece_last_meal(philo) > philo->t_ptr->ttd)
			return ;
		ft_eat(philo);
		if (ft_get_time_differece_last_meal(philo) > philo->t_ptr->ttd)
			return ;
		ft_sleep(philo);
		if (ft_get_time_differece_last_meal(philo) > philo->t_ptr->ttd)
			return ;
		ft_think(philo);
		if (ft_get_time_differece_last_meal(philo) > philo->t_ptr->ttd)
			return ;
	}
	return ;
}

void	*routine(void *arg)
{
	t_philo		*philo;
	t_tabledata	*table;

	philo = (t_philo *)arg;
	table = philo->t_ptr;
	if ((philo->name % 2) == 0)
		usleep(table->tte * 500);
	routine_loop(philo);
	return (NULL);
}
