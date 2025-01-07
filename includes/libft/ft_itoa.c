/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:46:28 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/20 15:50:43 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	char	*result;

	len = num_len(n);
	result = malloc(len + 1);
	if (result)
	{
		i = 0;
		if (n < 0)
		{
			i = 1;
			result[0] = '-';
			n = -n;
		}
		result[len] = 0;
		while (i < len--)
		{
			result[len] = '0' + (unsigned int)n % 10;
			n = (unsigned int)n / 10;
		}
	}
	return (result);
}
