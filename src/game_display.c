/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:52:56 by hemera            #+#    #+#             */
/*   Updated: 2025/01/26 15:09:11 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_img(t_data *data, int x, int y, char z)
{
	void	*img;

	if (z == '1')
		img = data->sprite.img_wall;
	else if (z == '0')
		img = data->sprite.img_floor;
	else if (z == 'C')
		img = data->sprite.img_collect;
	else if (z == 'E')
		img = data->sprite.img_exit;
	else
		return (0);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, img, (x * 80), (y * 80));
	return (0);
}

int	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_content[j])
	{
		i = 0;
		while (data->map_content[j][i])
		{
			if (data->map_content[j][i] == 'P')
				init_player(data, i, j);
			if (data->map_content[j][i] == 'C')
			{
				data->collectible_amount += 1;
				print_img(data, i, j, data->map_content[j][i]);
			}
			else
				print_img(data, i, j, data->map_content[j][i]);
			i++;
		}
		j++;
	}
	return (0);
}

int	print_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprite.img_player, (data->pos.x * 80), (data->pos.y * 80));
	return (0);
}

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
