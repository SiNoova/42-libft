/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:53:28 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/05 05:40:11 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strtoint(const char *str, int i, int sign)
{
	unsigned long long	nb;
	int					c;

	nb = 0;
	c = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		c++;
		if (c == 20)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (nb > LONG_MAX)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (nb * sign);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	return (strtoint(str, i, sign));
}
