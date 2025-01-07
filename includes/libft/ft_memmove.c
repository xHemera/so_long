/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:10:38 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/20 14:56:17 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((t_byte *)dest)[i] = ((t_byte *)src)[i];
			i++;
		}
	}
	else if (src < dest)
	{
		while (n--)
			((t_byte *)dest)[n] = ((t_byte *)src)[n];
	}
	return (dest);
}
