/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_destr_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminaelk <aminaelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:09:55 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/26 09:17:18 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

char	check_errors(t_glob_info *infos)
{
	if (infos->nb_philos == 0 || infos->nb_philos == -200
		||infos->time_to_die == -200
		|| infos->nb_of_meals == -200)
		return ('a');
	if (infos->time_to_sleep == -200 || infos->time_to_eat == -200)
		return ('a');
	return ('b');
}

void	ft_errarg(void)
{
	write(1, "Error \n", 8);
}

void	ft_exit(t_philo *list)
{
	if (!list)
	{
		write(1, "Error \n", 8);
		return ;
	}
}

void	freeing_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->glob_infos->nb_philos)
	{
		free(philo);
		i++;
		philo = philo->next;
	}
}

void	destroy_mutexes(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo->glob_infos->is_alive);
	pthread_mutex_destroy(&philo->glob_infos->msg);
	while (i < philo->glob_infos->nb_philos)
	{
		pthread_mutex_destroy(&philo->p_fork);
		i++;
		philo = philo->next;
	}
}
