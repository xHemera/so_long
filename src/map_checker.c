/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:11:48 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/26 17:38:44 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	check_all(t_data *data)
// {
// }

void	error_handler(char *err, t_data *data)
{
	printf("Erreur! %s\n", err);
	end(data);
}

int	check_map_params(t_data *data)
{
	if (data->count.c <= 0)
		error_handler("Pas assez de collectible.", data);
	if (data->count.e != 1)
		error_handler("Une seule sortie doit etre possible.", data);
	if (data->count.p != 1)
		error_handler("Il ne peut y avoir qu'un joueur.", data);
	return (1);
}
