/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminaelk <aminaelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:06:46 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/19 17:03:59 by aminaelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_philo	*ft_lstnew(t_glob_info *infos)
{
	t_philo	*new;

	new = malloc(sizeof (t_philo));
	if (new == NULL)
		return (NULL);
	new -> next = NULL;
	new -> previous = NULL;
	new->id = 1;
	new->nb_fork = 1;
	new->meals_eaten = 0;
	new->start_eating = 0;
	new->finish_eating = 0;
	new->is_sleeping = 0;
	new->is_thinking = 0;
	new->died = 0;
	new->last_meal = convert_toms();
	new->got_fork = 0;
	new->glob_infos = infos;
	pthread_mutex_init(&new->p_fork, NULL);
	return (new);
}
