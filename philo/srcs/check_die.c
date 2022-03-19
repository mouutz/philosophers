/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:47:08 by msahli            #+#    #+#             */
/*   Updated: 2021/08/20 17:47:08 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*check_die(void *arg)
{
	t_pthread_philo	*philo;

	philo = (t_pthread_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&(philo->data->m_die));
		if (philo->data->is_die == 0 && philo->limit <= get_time() \
			&& is_need_eat(philo))
		{
			massage(WR_DIE, get_time() - philo->data->start_time, philo->i);
			philo->data->is_die = philo->i;
			return (NULL);
		}
		pthread_mutex_unlock(&(philo->data->m_die));
	}
	pthread_detach(philo->p_check_die);
	return (NULL);
}
