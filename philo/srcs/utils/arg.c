/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:47:14 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/25 20:51:04 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	set_eat_arg(char *arg, int *flag)
{
	int	res;

	if (arg)
		res = get_arg(arg, flag);
	else
		res = -1;
	return (res);
}
