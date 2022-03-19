/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:47:17 by msahli            #+#    #+#             */
/*   Updated: 2021/08/20 17:47:18 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_pthread_philo	*philo;

	philo = NULL;
	if (argc != 5 && argc != 6)
		return (error("Error: argument error\n"));
	if (init(&(argv[1]), &philo))
		return (all_free(philo));
	if (go_treads(philo))
		return (all_free(philo));
	return (0);
}
