/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:17:06 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/26 19:17:09 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../philo.h"

int	take_fork(t_philo *copy, pthread_mutex_t *fork, int	*b_fork,
	pthread_mutex_t *b_myfork)
{
	pthread_mutex_lock(b_myfork);
	while (*b_fork != 0)
	{
		pthread_mutex_unlock(b_myfork);
		if (check_dead(copy, copy->last_meal,
				copy->glob_infos->time_to_die) == 1)
			return (1);
		usleep(20);
		pthread_mutex_lock(b_myfork);
	}
	pthread_mutex_unlock(b_myfork);
	pthread_mutex_lock(fork);
	pthread_mutex_lock(b_myfork);
	*b_fork = 1;
	pthread_mutex_unlock(b_myfork);
	return (0);
}

int	drop_fork(pthread_mutex_t *fork, int	*b_fork, pthread_mutex_t *b_myfork)
{
	pthread_mutex_unlock(fork);
	pthread_mutex_lock(b_myfork);
	*b_fork = 0;
	pthread_mutex_unlock(b_myfork);
	return (0);
}
