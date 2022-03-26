/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:19:31 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/22 22:19:31 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time_ms(void)
{
	struct timeval	time;
	long long		out;

	gettimeofday(&time, NULL);
	out = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (out);
}

void	ft_exception(char **argv)
{
	if (ft_atoi(argv[1]) == 0)
		return ;
	printf("0 1 has taken a fork\n");
	usleep(ft_atoi(argv[2]) * 1000);
	printf("%d 1 died\n", ft_atoi(argv[2]));
}

void	free_remains(t_tabledata *table)
{
	int	i;

	i = 0;
	while (i < table->philo_amount)
	{
		pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
	i = 0;
	free(table->forks);
	free(table->philos);
}
