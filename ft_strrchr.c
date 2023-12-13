/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:39:11 by akoutate          #+#    #+#             */
/*   Updated: 2023/11/30 18:56:11 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			x;

	i = ft_strlen(s);
	x = (char)c;
	while (i > 0)
	{
		if (s[i] == x)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == x)
		return ((char *)&s[i]);
	return (NULL);
}
