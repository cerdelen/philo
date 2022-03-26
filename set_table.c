/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:13:01 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/25 20:04:29 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_tabledata(t_tabledata *table, int argc, char **argv)
{
	table->philo_amount = ft_atoi(argv[1]);
	table->ttd = ft_atoi(argv[2]);
	table->tte = ft_atoi(argv[3]);
	table->tts = ft_atoi(argv[4]);
	if (argc == 6)
		table->max_amount_of_meals = ft_atoi(argv[5]);
	else
		table->max_amount_of_meals = -69;
	table->t_start = ft_get_time_ms();
	table->philos = ft_calloc(table->philo_amount, sizeof(t_philo));
	table->forks = ft_calloc(table->philo_amount, sizeof(pthread_mutex_t));
	table->end_of_meal = false;
}

void	set_up_table(t_tabledata *table, int argc, char **argv)
{
	init_tabledata(table, argc, argv);
	if (table->philo_amount == 0)
		return ;
	init_forks(table);
	init_philos(table);
	pthread_mutex_init(&table->action_right, NULL);
}
