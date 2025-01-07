/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:07:46 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/19 19:35:54 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	i = ft_strlen(s);
	result = malloc(i + 1);
	if (result)
	{
		result[i] = 0;
		while (i--)
			result[i] = (*f)(i, s[i]);
	}
	return (result);
}
