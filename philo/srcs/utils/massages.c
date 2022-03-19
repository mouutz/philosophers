/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:46:53 by msahli            #+#    #+#             */
/*   Updated: 2021/08/20 17:46:53 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	left_fork_up(t_pthread_philo *philo)
{
	pthread_mutex_lock(philo->left);
	massage(WR_LEFT_FORK_UP, get_time() - philo->data->start_time, philo->i);
}

void	right_fork_up(t_pthread_philo *philo)
{
	pthread_mutex_lock(philo->right);
	massage(WR_RIGHT_FORK_UP, get_time() - philo->data->start_time, philo->i);
}

void	massage(int mas, long int time, int i)
{
	pthread_mutex_lock(&g_m_massage);
	if (mas == WR_LEFT_FORK_UP)
		printf(YELLOW"%4ld: "RESET"%3d "GREEN"philo has taken a right fork\n" \
								RESET, time, i);
	else if (mas == WR_RIGHT_FORK_UP)
		printf(YELLOW"%4ld: "RESET"%3d "GREEN"philo has taken a left fork\n" \
								RESET, time, i);
	else if (mas == WR_EAT)
		printf(YELLOW"%4ld: "RESET"%3d "CYAN"philo eating\n", time, i);
	else if (mas == WR_SLEEP)
		printf(YELLOW"%4ld: "RESET"%3d "BLUE"philo sleeping\n", time, i);
	else if (mas == WR_THINK)
		 printf(YELLOW"%4ld: "RESET"%3d "MAGENTA"philo thinking\n", time, i);
	else if (mas == WR_DIE)
	{
		 printf(RED"%4ld: %3d PHILO IS DIE\n", time, i);
		 return ;
	}
	pthread_mutex_unlock(&g_m_massage);
}
