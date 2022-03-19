/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:46:59 by msahli            #+#    #+#             */
/*   Updated: 2021/08/20 17:47:00 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	is_need_eat(t_pthread_philo *philo)
{
	int	res;
	int	eat_stat;

	if (!philo)
		return (-1);
	eat_stat = philo->data->column_eat_for_die;
	if (eat_stat == -1)
		res = 1;
	else if (eat_stat != philo->col_eat)
		res = 2;
	else
		res = 0;
	return (res);
}

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	my_sleep(int sleep)
{
	long int	time;

	time = get_time();
	while (get_time() - time < sleep)
		usleep(100);
	return (1);
}

int	all_free(t_pthread_philo *philo)
{
	if (!philo)
		return (1);
	free(philo->left);
	free(philo->data);
	free(philo);
	return (1);
}

int	get_arg(char *str, int *flag)
{
	char	*test;
	int		i;
	int		res;

	test = NULL;
	res = ft_atoi(str, &test);
	i = 0;
	while (test && test[i] == ' ')
		i++;
	if (res <= 0 || (test && test[i] != '\0'))
		*flag = 1;
	return (res);
}
