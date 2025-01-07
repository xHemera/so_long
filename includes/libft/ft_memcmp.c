/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:04:51 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/17 17:08:16 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (!n)
		return (0);
	while (((t_byte *)s1)[i] == ((t_byte *)s2)[i] && i + 1 < n)
		i++;
	return (((t_byte *)s1)[i] - ((t_byte *)s2)[i]);
}
