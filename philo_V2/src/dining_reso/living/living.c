/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminaelk <aminaelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:02:49 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/24 11:14:32 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../philo.h"

void timing(t_philo *copy)
{
	pthread_mutex_lock(&copy->glob_infos->timest);
	copy->glob_infos->timestamp = convert_toms() - copy->glob_infos->start_diner;
	pthread_mutex_unlock(&copy->glob_infos->timest);
}

int	take_fork_one(t_philo *copy)
{
	if (check_dead(copy, copy->last_meal, copy->glob_infos->time_to_die) == 1)
		return (1);
	pthread_mutex_lock(copy->first);
	timing(copy);
	//printf("1 ----- timestamp take fork one == %ld\n", copy->glob_infos->timestamp);

	message_tosend("\n%ld %d has taken a fork\n",
		&copy->glob_infos->timestamp, copy);
	if (copy->glob_infos->nb_philos == 1)
	{
		printf("0 1 has taken a fork\n");
		pthread_mutex_unlock(copy->first);
		usleep(copy->glob_infos->time_to_die * 1000);
		if (check_dead(copy, copy->last_meal, copy->glob_infos->time_to_die))
			return (1);
	}
	if (check_dead(copy, copy->last_meal, copy->glob_infos->time_to_die) == 1)
	{
		pthread_mutex_unlock(copy->first);
		return (1);
	}
	return (0);
}

int	take_fork_two(t_philo *copy)
{
	pthread_mutex_lock(copy->second);
	timing(copy);
	//printf("2 ---- timestamp take fork two == %ld\n", copy->glob_infos->timestamp);
	message_tosend("\n%ld %d has taken a fork\n",
		&copy->glob_infos->timestamp, copy);
	if (check_dead(copy, copy->last_meal, copy->glob_infos->time_to_die) == 1)
	{
		pthread_mutex_unlock(copy->second);
		pthread_mutex_unlock(copy->first);
		return (1);
	}
	message_tosend("\n%ld %d is eating\n",
		&copy->glob_infos->timestamp, copy);
	if (copy->glob_infos->nb_of_meals != -1)
		copy->meals_eaten++;
	copy->last_meal = convert_toms();
	if (my_usleep(copy, copy->glob_infos->time_to_eat, 1))
		return (1);
	pthread_mutex_unlock(copy->second);
	pthread_mutex_unlock(copy->first);
	return (0);
}

void	think_sleep(t_philo *copy)
{
	usleep(100);
	timing(copy);
	//printf("3 ---- timestamp sleep\think == %ld\n", copy->glob_infos->timestamp);
	message_tosend("\n%ld %d is sleeping\n",
		&copy->glob_infos->timestamp, copy);
	my_usleep(copy, copy->glob_infos->time_to_sleep, 0);
	timing(copy);
	//printf("4 --- timestamp think-sleep == %ld\n", copy->glob_infos->timestamp);
	message_tosend("\n%ld %d is thinking\n",
		&copy->glob_infos->timestamp, copy);
	usleep(10);
}
