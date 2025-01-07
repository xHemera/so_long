/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:23:25 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/20 17:19:35 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_whichmin(size_t a, size_t b)
{
	if (b > a)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	srclen;

	srclen = ft_strlen(s);
	start = ft_whichmin(srclen, start);
	len = ft_whichmin(srclen - start, len);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}
