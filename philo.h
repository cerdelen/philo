/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:05:23 by cerdelen          #+#    #+#             */
/*   Updated: 2022/03/25 20:58:03 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo		t_philo;
typedef struct s_tabledata	t_tabledata;

typedef struct s_philo
{
	int				name;
	int				count_meals;
	int				fork_1;
	int				fork_2;
	long long		t_last_meal;
	t_tabledata		*t_ptr;
	pthread_t		thread_id;
}	t_philo;

typedef struct s_tabledata
{
	int				philo_amount;
	int				tte;
	int				ttd;
	int				tts;
	int				max_amount_of_meals;
	long long		t_start;
	int				end_of_meal;
	pthread_mutex_t	*forks;
	pthread_mutex_t	action_right;
	t_philo			*philos;
}	t_tabledata;

int			check_arguments(int argc, char **argv);
long long	ft_get_time_ms(void);
void		init_tabledata(t_tabledata *table, int argc, char **argv);
void		get_philo(t_tabledata *table, int name, t_philo *philo);
void		init_forks(t_tabledata *table);
void		init_philos(t_tabledata *table);
void		set_up_table(t_tabledata *table, int argc, char **argv);
void		*ft_die(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_grab_forks(t_philo *philo);
void		*routine(void *arg);
void		start_lunch(t_tabledata *table);
void		check_for_end(t_tabledata *table);
void		ft_exception(char **argv);
void		free_remains(t_tabledata *table);
int			ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nelem, size_t elsize);
int			ft_isdigit(int c);
int			ft_strlen(const char *s);
void		ft_grab_fork2(t_philo *philo);
void		ft_grab_fork1(t_philo *philo);
long long	ft_get_time_differece_last_meal(t_philo *philo);
void		routine_loop(t_philo *philo);
void		*routine(void *arg);

#endif