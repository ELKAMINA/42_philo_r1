/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:15:29 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/15 11:25:24 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	settle_forks(t_philo **philo_head, t_glob_info *global_info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = *philo_head;
	while (i < global_info->nb_philos)
	{
		if (philo->id % 2 != 0)
		{
			philo->first = &philo->p_fork;
			philo->second = &philo->next->p_fork;
		}
		else
		{
			philo->first = &philo->next->p_fork;
			philo->second = &philo->p_fork;
		}
		philo = philo->next;
		i++;
	}
}

void	dining_philosopher(t_philo *philo, t_glob_info *global_info)
{
	circularing(&philo);
	incr_id_fork(&philo, global_info);
	settle_forks(&philo, global_info);
	dining_philos(&philo, global_info);
	destroy_mutexes(philo);
	decircularing(&philo, global_info->nb_philos);
}

int	main(int argc, char *argv[])
{
	t_glob_info	*global_info;
	t_philo		*philo;

	if (argc > 6 || (argc < 6 && argc != 5) || check_char(argv) == 0)
	{
		ft_errarg();
		return (0);
	}
	else
	{
		global_info = get_info_args(argc, argv);
		if (check_errors(global_info) == 'a')
		{
			ft_errarg();
			free(global_info);
			return (0);
		}
		philo = create_ll(global_info);
		dining_philosopher(philo, global_info);
		ft_lstclear(&philo);
		free(global_info);
		return (0);
	}
}
