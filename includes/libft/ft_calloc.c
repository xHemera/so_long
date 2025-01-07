/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:25:55 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/19 18:20:18 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*ptr;

	ptr = malloc(elementCount * elementSize);
	if (ptr)
		ft_bzero(ptr, (elementCount * elementSize));
	return (ptr);
}
