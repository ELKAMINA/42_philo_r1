/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:23:49 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/13 14:24:37 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	circularing(t_philo **a)
{
	t_philo	*copy;
	t_philo	*head;

	copy = *a;
	head = *a;
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = head;
	head->previous = copy;
}

void	decircularing(t_philo **a, int size)
{
	t_philo	*copy;
	int		i;

	i = 0;
	copy = *a;
	copy->previous = NULL;
	while (i < size - 1)
	{
		copy = copy->next;
		i++;
	}
	copy->next = NULL;
}

void	incr_id_fork(t_philo **philo_fi, t_glob_info *infos)
{
	t_philo	*copy;
	int		i;

	copy = *philo_fi;
	i = 0;
	while (i < infos->nb_philos)
	{
		copy->id = i + 1;
		copy = copy->next;
		i++;
	}
}

void	create_all_philos(t_philo *philo_fi, t_philo *philo_sec,
			t_glob_info *infos)
{
	int	i;

	i = 3;
	while (i <= infos->nb_philos)
	{
		philo_sec = ft_lstnew(infos);
		ft_exit(philo_sec);
		ft_lstadd_back(&philo_fi, philo_sec);
		i++;
	}
}

t_philo	*create_ll(t_glob_info *infos)
{
	t_philo	*philo_fi;
	t_philo	*philo_sec;

	if (infos->nb_philos >= 1)
	{
		philo_fi = ft_lstnew(infos);
		ft_exit(philo_fi);
		if (infos->nb_philos == 1)
			return (philo_fi);
		else
		{
			philo_sec = ft_lstnew(infos);
			ft_exit(philo_sec);
			philo_fi->next = philo_sec;
			philo_sec->previous = philo_fi;
			create_all_philos(philo_fi, philo_sec, infos);
		}
		return (philo_fi);
	}
	else
		return (NULL);
}
