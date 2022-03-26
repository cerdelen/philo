/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:16:14 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/25 21:00:00 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_die(t_philo *philo)
{
	long long	time;

	if (philo->t_ptr->end_of_meal == false)
	{
		philo->t_ptr->end_of_meal = true;
		time = ft_get_time_ms() - philo->t_ptr->t_start;
		printf("%lld %d died\n", time, philo->name);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->t_ptr->action_right);
	if (philo->t_ptr->end_of_meal == false)
	{
		time = ft_get_time_ms();
		if (time - philo->t_last_meal > philo->t_ptr->ttd)
		{
			pthread_mutex_unlock(&philo->t_ptr->forks[philo->fork_1]);
			pthread_mutex_unlock(&philo->t_ptr->forks[philo->fork_2]);
			return ;
		}
		printf("%lld %d is eating\n", time - philo->t_ptr->t_start,
			philo->name);
		philo->count_meals++;
		philo->t_last_meal = time;
		pthread_mutex_unlock(&philo->t_ptr->action_right);
		usleep(philo->t_ptr->tte * 1000);
		pthread_mutex_unlock(&philo->t_ptr->forks[philo->fork_1]);
		pthread_mutex_unlock(&philo->t_ptr->forks[philo->fork_2]);
	}
	else
		pthread_mutex_unlock(&philo->t_ptr->action_right);
}

void	ft_sleep(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->t_ptr->action_right);
	if (philo->t_ptr->end_of_meal == false)
	{
		pthread_mutex_unlock(&philo->t_ptr->action_right);
		time = ft_get_time_ms();
		printf("%lld %d is sleeping\n", time - philo->t_ptr->t_start,
			philo->name);
		usleep(philo->t_ptr->tts * 1000);
	}
	else
		pthread_mutex_unlock(&philo->t_ptr->action_right);
}

void	ft_think(t_philo *philo)
{
	long long	time;

	time = ft_get_time_ms() - philo->t_ptr->t_start;
	pthread_mutex_lock(&philo->t_ptr->action_right);
	if (philo->t_ptr->end_of_meal == false)
		printf("%lld %d is thinking\n", time, philo->name);
	pthread_mutex_unlock(&philo->t_ptr->action_right);
}
