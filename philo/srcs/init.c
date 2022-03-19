/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:47:12 by msahli            #+#    #+#             */
/*   Updated: 2021/08/20 17:47:13 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	check_init_set(t_settings *settings)
{
	int	res;

	res = 0;
	if (settings->number < 1 || settings->number > 200)
		res++;
	else if (settings->time_die < 60 || \
			settings->time_eat < 60 || \
			settings->time_sleep < 60)
		res++;
	return (res);
}

t_settings	*init_settings(char **argv)
{
	int			flag;
	t_settings	*settings;

	settings = (t_settings *)malloc(sizeof(t_settings));
	if (!settings)
	{
		error("Error: malloc error\n");
		return (NULL);
	}
	flag = 0;
	settings->is_die = 0;
	settings->number = get_arg(argv[0], &flag);
	settings->time_die = get_arg(argv[1], &flag);
	settings->time_eat = get_arg(argv[2], &flag);
	settings->time_sleep = get_arg(argv[3], &flag);
	settings->start_time = get_time();
	settings->column_eat_for_die = set_eat_arg(argv[4], &flag);
	pthread_mutex_init(&(settings->m_die), NULL);
	if (flag || check_init_set(settings))
	{
		free(settings);
		error("Error: its not a valid arguments\n");
		return (NULL);
	}
	return (settings);
}

pthread_mutex_t	*init_mutex(int number)
{
	int				i;
	pthread_mutex_t	*mutex;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * number);
	if (!mutex)
	{
		error("Error: malloc error\n");
		return (NULL);
	}
	i = -1;
	while (++i < number)
		pthread_mutex_init(&(mutex[i]), NULL);
	pthread_mutex_init(&g_m_massage, NULL);
	return (mutex);
}

t_pthread_philo	*init_philo(t_settings *settings, pthread_mutex_t *mutex)
{
	int				i;
	long int		time;
	t_pthread_philo	*philo;

	philo = (t_pthread_philo *)malloc(sizeof(t_pthread_philo) * \
												settings->number);
	if (!philo)
	{
		error("Error: malloc error\n");
		return (NULL);
	}
	i = -1;
	time = get_time();
	while (++i < settings->number)
	{
		philo[i].i = i + 1;
		philo[i].col_eat = 0;
		philo[i].data = settings;
		philo[i].left = &(mutex[i]);
		philo[i].right = &(mutex[(i + 1) % settings->number]);
		philo[i].limit = time + philo->data->time_die;
	}
	return (philo);
}

int	init(char **argv, t_pthread_philo **p_philo)
{
	t_settings		*settings;
	t_pthread_philo	*philo;
	pthread_mutex_t	*mutex;

	settings = init_settings(argv);
	if (!settings)
		return (1);
	mutex = init_mutex(settings->number);
	if (!mutex)
		return (1);
	philo = init_philo(settings, mutex);
	if (!philo)
		return (1);
	*p_philo = philo;
	return (0);
}
