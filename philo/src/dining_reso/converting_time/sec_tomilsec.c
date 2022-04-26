/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_tomilsec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminaelk <aminaelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:25:46 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/24 11:13:49 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../philo.h"

time_t	convert_toms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	my_usleep(t_philo *copy, time_t t, int fork_use)
{
	time_t	start;

	start = convert_toms();
	while (1)
	{
		if (check_dead(copy, copy->last_meal,
				copy->glob_infos->time_to_die) == 1)
		{
			if (fork_use == 1)
			{
				pthread_mutex_unlock(copy->second);
				pthread_mutex_unlock(copy->first);
			}
			break ;
		}
		if (convert_toms() - start >= t)
			break ;
		usleep(400);
	}
}

time_t	countdown(time_t time, t_philo *copy)
{
	time_t	discard;

	pthread_mutex_lock(&copy->glob_infos->time);
	discard = time - copy->glob_infos->start_diner;
	pthread_mutex_unlock(&copy->glob_infos->time);
	return (discard);
}

time_t	countdown_death(time_t time)
{
	return (convert_toms() - time);
}
