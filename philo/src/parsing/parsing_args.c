/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:09:12 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/24 11:11:35 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	check_char(char *argv[])
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		if (*argv[i] == '\0')
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

t_glob_info	*get_info_args(int argc, char *argv[])
{
	t_glob_info	*init_info;

	init_info = malloc(sizeof(t_glob_info));
	if (!init_info)
		return (NULL);
	init_info->nb_philos = ft_atol(argv[1]);
	init_info->all_forks = ft_atol(argv[1]);
	init_info->time_to_die = ft_atol(argv[2]);
	init_info->time_to_eat = ft_atol(argv[3]);
	init_info->time_to_sleep = ft_atol(argv[4]);
	init_info->is_dead = 0;
	pthread_mutex_init(&init_info->is_alive, NULL);
	pthread_mutex_init(&init_info->msg, NULL);
	pthread_mutex_init(&init_info->start, NULL);
	pthread_mutex_init(&init_info->time, NULL);
	if (argc == 6)
		init_info->nb_of_meals = ft_atol(argv[5]);
	else
		init_info->nb_of_meals = -1;
	init_info->start_diner = 0;
	return (init_info);
}
