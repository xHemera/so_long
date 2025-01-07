/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:27:16 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/17 14:32:47 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*result;

	len = ft_strlen(src);
	result = malloc(len + 1);
	if (result)
		ft_strlcpy(result, src, len + 1);
	return (result);
}
