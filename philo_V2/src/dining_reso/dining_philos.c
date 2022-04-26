/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminaelk <aminaelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:28:09 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/24 17:59:22 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	message_tosend(char *str, time_t *timestamp, t_philo *philo)
{
	pthread_mutex_lock(&philo->glob_infos->is_alive);
	if (philo->glob_infos->is_dead == 0)
	{
		pthread_mutex_lock(&philo->glob_infos->msg);
		pthread_mutex_lock(&philo->glob_infos->timest);
		printf(str, *timestamp, philo->id);
		pthread_mutex_unlock(&philo->glob_infos->timest);
		pthread_mutex_unlock(&philo->glob_infos->msg);
	}
	pthread_mutex_unlock(&philo->glob_infos->is_alive);
}

void	dying_philo(t_philo *philo)
{
	timing(philo);
	pthread_mutex_lock(&philo->glob_infos->msg);
	pthread_mutex_lock(&philo->glob_infos->timest);
	printf("%ld %d died\n", philo->glob_infos->timestamp, philo->id);
	pthread_mutex_unlock(&philo->glob_infos->timest);
	pthread_mutex_unlock(&philo->glob_infos->msg);
	return ;
}

int	check_dead(t_philo *philo, time_t last_meal, time_t time_to_die)
{
	pthread_mutex_lock(&philo->glob_infos->is_alive);
	if (philo->glob_infos->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->glob_infos->is_alive);
		return (1);
	}
	if (countdown_death(last_meal) >= time_to_die)
	{
		philo->glob_infos->is_dead = 1;
		dying_philo(philo);
		pthread_mutex_unlock(&philo->glob_infos->is_alive);
		return (1);
	}
	pthread_mutex_unlock(&philo->glob_infos->is_alive);
	return (0);
}

void	func_living(t_philo *copy)
{
	if (copy->id % 2 == 0)
		my_usleep(copy, (copy->glob_infos->time_to_eat) / 3, 0);
	while (copy->glob_infos->nb_of_meals != copy->meals_eaten)
	{
		if (take_fork_one(copy) == 1)
			break ;
		if (take_fork_two(copy) == 1)
			break ;
		think_sleep(copy);
		if (check_dead(copy, copy->last_meal,
				copy->glob_infos->time_to_die) == 1)
			break ;
		my_usleep(copy,
			(copy->glob_infos->time_to_die
				- (convert_toms() - copy->last_meal) - 10), 0);
	}
	return ;
}

void	dining_philos(t_philo **philo_fi, t_glob_info *infos)
{
	t_philo	*copy;

	copy = *philo_fi;
	creating_threads(copy, infos);
}
