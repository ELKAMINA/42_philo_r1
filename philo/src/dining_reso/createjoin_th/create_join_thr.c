/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_join_thr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminaelk <aminaelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:48:02 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/24 11:15:23 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../philo.h"

void	manage_failure(t_philo *philo, int n)
{
	while (n != 0)
	{
		pthread_mutex_lock(&philo->glob_infos->is_alive);
		if (pthread_join(philo->th, NULL) != 0)
		{
			pthread_mutex_unlock(&philo->glob_infos->is_alive);
			return ;
		}
		philo = philo->next;
		n--;
	}
	pthread_mutex_unlock(&philo->glob_infos->is_alive);
}

void	creating_threads(t_philo *copy, t_glob_info *infos)
{
	create_th(copy, infos);
	join_th(copy, infos);
}

void	create_th(t_philo *copy, t_glob_info *infos)
{
	long		i;
	int			n;
	t_philo		*fail;

	i = 0;
	n = 0;
	fail = copy;
	copy->glob_infos->start_diner = convert_toms();
	while (i < infos->nb_philos)
	{
		if (pthread_create(&copy->th, NULL, (void *)func_living, copy) != 0)
		{
			manage_failure(fail, n);
			return ;
		}
		copy = copy->next;
		i ++;
		n++;
	}
}

void	join_th(t_philo *copy, t_glob_info *infos)
{
	long	i;

	i = 0;
	while (i < infos->nb_philos)
	{
		if (pthread_join(copy->th, NULL) != 0)
		{
			perror("Failed to join a thread\n");
			return ;
		}
		copy = copy->next;
		i++;
	}
}
