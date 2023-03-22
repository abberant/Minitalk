/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:43:15 by aanouari          #+#    #+#             */
/*   Updated: 2022/11/06 14:23:43 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*find;

	i = 0;
	find = (unsigned char *)s;
	while (i < n)
	{
		if (find[i] == (unsigned char)c)
			return (find + i);
		i++;
	}
	return (NULL);
}
