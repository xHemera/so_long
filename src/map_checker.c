/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:11:48 by tobesnar          #+#    #+#             */
/*   Updated: 2025/03/03 12:26:03 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_data(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->map_content = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->mp = 0;
	data->score = 0;
}

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
		error_handler("Le nombre de sortie n'est pas bon.", data);
	if (data->count.p != 1)
		error_handler("Il ne doit y avoir qu'un joueur.", data);
	return (1);
}
