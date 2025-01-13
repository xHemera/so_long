/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:04:40 by hemera            #+#    #+#             */
/*   Updated: 2025/01/13 11:51:29 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
    	end(data);
	}
    if (keycode == XK_w)
		player_move(data, 'w');
    if (keycode == XK_a)
		player_move(data, 'a');
	if (keycode == XK_s)
		player_move(data, 's');
	if (keycode == XK_d)
		player_move(data, 'd');
	return (0);
}

int player_move(t_data *data, char dir)
{
	if (dir == 'w')
	{
		data->position.y = (data->position.y + 1);
		data->position.x = (data->position.x);
		printf("Joueur se dirige vers le haut, nouvelle position :\nX = %i, et Y = %i\n", data->position.x, data->position.y);
	}
	else if (dir == 'a')
	{
		data->position.x--;
		printf("Joueur se dirige vers la gauche, nouvelle position :\nX = %i, et Y = %i\n", data->position.x, data->position.y);
	}
	else if (dir == 's')
	{
		data->position.y--;
		printf("Joueur se dirige vers le bas, nouvelle position :\nX = %i, et Y = %i\n", data->position.x, data->position.y);
	}
	else if (dir == 'd')
	{
		data->position.x++;
		printf("Joueur se dirige vers la droite, nouvelle position :\nX = %i, et Y = %i\n", data->position.x, data->position.y);
	}
	return (0);
}
