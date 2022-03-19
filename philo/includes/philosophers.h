/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:47:34 by msahli            #+#    #+#             */
/*   Updated: 2021/08/20 17:47:39 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

# define WR_LEFT_FORK_UP 1
# define WR_RIGHT_FORK_UP 2
# define WR_EAT 5
# define WR_SLEEP 6
# define WR_THINK 7
# define WR_DIE 13

pthread_mutex_t			g_m_massage;

typedef struct s_settings
{
	int						number;
	int						is_die;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						column_eat_for_die;
	long int				start_time;
	pthread_mutex_t			m_die;
}							t_settings;
typedef struct s_pthread_philo
{
	int						i;
	int						col_eat;
	long int				limit;
	pthread_t				p_check_die;
	pthread_t				pd;
	struct s_settings		*data;
	pthread_mutex_t			*left;
	pthread_mutex_t			*right;
}							t_pthread_philo;
/*--------------------------------Init----------------------------------------*/
int				init(char **argv, t_pthread_philo **p_philo);
t_settings		*init_settings(char **argv);
pthread_mutex_t	*init_mutex(int number);
t_pthread_philo	*init_philo(t_settings *settings, pthread_mutex_t *mutex);
/*--------------------------------Treads--------------------------------------*/
void			eating(t_pthread_philo *philo);
void			sleeping(t_pthread_philo *philo);
void			thinking(t_pthread_philo *philo);
void			*life(void	*arg);
int				go_treads(t_pthread_philo *philo);
/*--------------------------------Check_die-----------------------------------*/
void			*check_die(void *arg);
/*--------------------------------Utils---------------------------------------*/
/*-------Base_Utils---------*/
int				error(char *str);
int				ft_strlen(char *str);
int				ft_atoi(char *str, char **flag);
/*-------Philo_Utils--------*/
int				is_need_eat(t_pthread_philo *philo);
long int		get_time(void);
int				my_sleep(int sleep);
int				all_free(t_pthread_philo *philo);
int				get_arg(char *str, int *flag);
/*-------Wait_tread---------*/
void			wait_eat(pthread_t *pd, int number);
void			wait_die(pthread_t *pd, t_pthread_philo *philo);
/*-------Massages-----------*/
void			left_fork_up(t_pthread_philo *philo);
void			right_fork_up(t_pthread_philo *philo);
void			massage(int mas, long int time, int i);
/*-------arg----------*/
int				set_eat_arg(char *arg, int *flag);

#endif
