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

	new = ft_calloc(1, (sizeof(t_philo)));
	new->id = 1;
	new->last_meal = convert_toms();
	new->glob_infos = infos;
	pthread_mutex_init(&new->p_fork, NULL);
	return (new);
}
