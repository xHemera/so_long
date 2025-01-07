/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:11:20 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/22 14:11:21 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *str, char sep)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (count);
}

char	**ft_split(char const *str, char sep)
{
	char	**split;
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_countwords(str, sep) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == sep && *str)
			str++;
		len = 0;
		while (str[len] && str[len] != sep)
			len++;
		if (*str)
			split[i++] = ft_substr(str, 0, len);
		str += len;
	}
	split[i] = NULL;
	return (split);
}
