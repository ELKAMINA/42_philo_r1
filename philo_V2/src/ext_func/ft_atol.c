/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:08:19 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/13 16:08:43 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	is_charset(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\n'
		|| c == '\r' || c == ' ')
		return (0);
	else if (c == '-' || c == '+')
		return (1);
	else
		return (-1);
}

int	err_handling(char str)
{
	if (is_charset(str) != -1)
		return (-200);
	return (0);
}

int	max_min_int(long nb)
{
	if (nb > 2147483647)
		return (-200);
	if (nb < -2147483648)
		return (-200);
	return (0);
}

long	ft_atol(const char	*str)
{
	long		i;
	int			nb;
	int			j;

	i = 0;
	nb = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		err_handling(str[i]);
		j = 0;
		while (++j < 10 && nb)
		{
			nb += (nb / j);
			if ((nb >> 31) & 1U)
				return (-200);
		}
		nb += str[i++] - '0';
		if ((((nb) >> 31) & 1U) && nb)
			return (-200);
	}
	return (nb);
}
