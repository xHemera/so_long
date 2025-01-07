/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:04:34 by tobesnar          #+#    #+#             */
/*   Updated: 2024/10/20 17:14:13 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;
	int	div;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		mod = n % 10;
		div = n / 10;
		ft_putnbr_fd(div, fd);
	}
	if (n > 9)
		ft_putchar_fd(mod + '0', fd);
	else
		ft_putchar_fd(n + '0', fd);
}
