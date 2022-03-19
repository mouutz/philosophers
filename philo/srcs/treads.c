/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treads.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:47:22 by msahli            #+#    #+#             */
/*   Updated: 2021/08/20 17:47:23 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eating(t_pthread_philo *philo)
{
	if (philo->i % 2)
	{
		if (philo->data->number % 2)
			my_sleep(philo->data->time_eat / 2);
		right_fork_up(philo);
		left_fork_up(philo);
	}
	else
	{
		left_fork_up(philo);
		right_fork_up(philo);
	}
	massage(WR_EAT, get_time() - philo->data->start_time, philo->i);
	philo->limit = get_time() + philo->data->time_die;
	if (philo->data->column_eat_for_die > -1 && \
		philo->data->column_eat_for_die != philo->col_eat)
		(philo->col_eat)++;
	my_sleep(philo->data->time_eat);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}

void	sleeping(t_pthread_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	massage(WR_SLEEP, time, philo->i);
	my_sleep(philo->data->time_sleep);
}

void	thinking(t_pthread_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	massage(WR_THINK, time, philo->i);
}

void	*life(void	*arg)
{
	t_pthread_philo	*philo;

	philo = (t_pthread_philo *)arg;
	pthread_create(&(philo->p_check_die), NULL, check_die, (void *)philo);
	while (!(philo->data->is_die))
	{
		eating(philo);
		if (!(is_need_eat(philo)))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	pthread_detach(philo->pd);
	return (NULL);
}

int	go_treads(t_pthread_philo *philo)
{
	int			i;
	int			number;
	pthread_t	*pd;
	pthread_t	p_check_die;

	number = philo->data->number;
	pd = (pthread_t *)malloc(sizeof(pthread_t) * number);
	if (!pd)
		return (error("Error: malloc error\n"));
	i = -1;
	while (++i < number)
	{
		philo[i].pd = pd[i];
		if (pthread_create(&(pd[i]), NULL, life, (void *)&(philo[i])))
			return (error("Error: pthread_create error\n"));
	}
	if (is_need_eat(philo) == 1)
		wait_die(pd, philo);
	else
		wait_eat(pd, philo->data->number);
	return (0);
}
