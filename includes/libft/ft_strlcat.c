/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 03:08:19 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/20 14:56:29 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	destlen;
	unsigned int	srclen;
	unsigned int	i;
	unsigned int	j;

	destlen = 0;
	srclen = 0;
	while (dest[destlen] && destlen < size)
		destlen++;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	if (size <= destlen)
		return (srclen + size);
	i = 0;
	j = destlen;
	while (src[i] && i < size - destlen - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (destlen + srclen);
}
