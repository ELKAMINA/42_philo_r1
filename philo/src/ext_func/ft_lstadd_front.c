/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:05:42 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/13 16:05:53 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	ft_lstadd_front(t_philo **alst, t_philo *new)
{
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (!new)
		return ;
	new->next = *alst;
	new->previous = NULL;
	*alst = new;
}
