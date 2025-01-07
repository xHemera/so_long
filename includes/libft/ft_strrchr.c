/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:39:50 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/16 11:57:15 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*find;

	find = NULL;
	while (*s)
	{
		if (*s == (char)c)
			find = (char *)s;
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (find);
}
