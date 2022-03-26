/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:59:47 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/25 20:59:48 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_grab_fork2(t_philo *philo)
{
	pthread_mutex_lock(&philo->t_ptr->action_right);
	if (philo->t_ptr->end_of_meal == true)
	{
		pthread_mutex_unlock(&philo->t_ptr->action_right);
		return ;
	}
	pthread_mutex_unlock(&philo->t_ptr->action_right);
	pthread_mutex_lock(&philo->t_ptr->forks[philo->fork_2]);
	pthread_mutex_lock(&philo->t_ptr->action_right);
	if (philo->t_ptr->end_of_meal == true)
	{
		pthread_mutex_unlock(&philo->t_ptr->action_right);
		pthread_mutex_unlock(&philo->t_ptr->forks[philo->fork_2]);
		return ;
	}
	pthread_mutex_unlock(&philo->t_ptr->action_right);
	printf("%lld %d has taken a fork\n",
		ft_get_time_ms() - philo->t_ptr->t_start,
		philo->name);
}

void	ft_grab_fork1(t_philo *philo)
{
	pthread_mutex_lock(&philo->t_ptr->action_right);
	if (philo->t_ptr->end_of_meal == true)
	{
		pthread_mutex_unlock(&philo->t_ptr->action_right);
		return ;
	}
	pthread_mutex_unlock(&philo->t_ptr->action_right);
	pthread_mutex_lock(&philo->t_ptr->forks[philo->fork_1]);
	pthread_mutex_lock(&philo->t_ptr->action_right);
	if (philo->t_ptr->end_of_meal == true)
	{
		pthread_mutex_unlock(&philo->t_ptr->action_right);
		pthread_mutex_unlock(&philo->t_ptr->forks[philo->fork_1]);
		return ;
	}
	pthread_mutex_unlock(&philo->t_ptr->action_right);
	printf("%lld %d has taken a fork\n",
		ft_get_time_ms() - philo->t_ptr->t_start,
		philo->name);
}
