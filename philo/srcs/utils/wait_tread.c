/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_tread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:47:03 by msahli            #+#    #+#             */
/*   Updated: 2021/08/20 17:47:04 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	wait_die(pthread_t *pd, t_pthread_philo *philo)
{
	while (philo->data->is_die == 0)
		;
}

void	wait_eat(pthread_t *pd, int number)
{
	int	i;

	i = -1;
	while (++i < number)
		pthread_join(pd[i], NULL);
}
