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
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->glob_infos->is_alive);
	philo->glob_infos->is_dead = 1;
	pthread_mutex_unlock(&philo->glob_infos->is_alive);
	while (i < n && philo->id <= n)
	{
		if (pthread_join(philo->th, NULL) != 0)
			return ;
		philo = philo->next;
		i++;
	}
}

void	creating_threads(t_philo *copy, t_glob_info *infos)
{
	if	(create_th(copy, infos) == 1)
		return ;
	join_th(copy, infos);
}

int	create_th(t_philo *copy, t_glob_info *infos)
{
	long		i;
	t_philo		*fail;

	i = 0;
	fail = copy;
	pthread_mutex_lock(&copy->glob_infos->timest);
	copy->glob_infos->start_diner = convert_toms();
	copy->glob_infos->timestamp = convert_toms();
	pthread_mutex_unlock(&copy->glob_infos->timest);
	while (i < infos->nb_philos)
	{

		if (pthread_create(&copy->th, NULL, (void *)func_living, copy) != 0)
		{
			manage_failure(fail, i);
			return (1);
		}
		copy = copy->next;
		i ++;
	}
	return (0);
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
