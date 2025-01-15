/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:04:40 by hemera            #+#    #+#             */
/*   Updated: 2025/01/15 16:20:07 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		end(data);
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

void	player_move(t_data *data, char dir)
{
	mlx_put_image_to_window(
		data->mlx_ptr, data->win_ptr, data->sprite.img_floor,
		(data->pos.x * 80), (data->pos.y * 80));
	if (dir == 'w' && movement_is_possible(data, dir))
		data->pos.y--;
	else if (dir == 'a' && movement_is_possible(data, dir))
		data->pos.x--;
	else if (dir == 's' && movement_is_possible(data, dir))
		data->pos.y++;
	else if (dir == 'd' && movement_is_possible(data, dir))
		data->pos.x++;
}

int movement_is_possible(t_data *data, char dir)
{
	if (dir == 'w')
		return (data->map_content[data->pos.y - 1][data->pos.x] == '0');
	else if (dir == 's')
		return (data->map_content[data->pos.y + 1][data->pos.x] == '0');
	else if (dir == 'a')
		return (data->map_content[data->pos.y][data->pos.x - 1] == '0');
	else if (dir == 'd')
		return (data->map_content[data->pos.y][data->pos.x + 1] == '0');
	return (0);
}
