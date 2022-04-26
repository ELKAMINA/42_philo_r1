/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:06:05 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/13 16:06:12 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*last;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	last = ft_lstlast(*alst);
	last -> next = new;
	new->previous = last;
	new->next = NULL;
}
