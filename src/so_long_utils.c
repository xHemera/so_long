/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:04:40 by hemera            #+#    #+#             */
/*   Updated: 2025/01/26 15:33:11 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_direction(char dir, int *dx, int *dy)
{
	*dx = 0;
	*dy = 0;
	if (dir == 'w')
		*dy = -1;
	else if (dir == 'a')
		*dx = -1;
	else if (dir == 's')
		*dy = 1;
	else if (dir == 'd')
		*dx = 1;
}

void	add_score(t_data *data, char dir)
{
	int	dx;
	int	dy;
	int	new_x;
	int	new_y;


	get_direction(dir, &dx, &dy);
	new_x = data->pos.x + dx;
	new_y = data->pos.y + dy;
	if (data->map_content[new_y][new_x] == 'C')
	{
		data->score += 1;
		data->map_content[new_y][new_x] = '0';
	}
}

void	player_move(t_data *data, char dir)
{
	int	dx;
	int	dy;


	get_direction(dir, &dx, &dy);
	mlx_put_image_to_window(
		data->mlx_ptr, data->win_ptr, data->sprite.img_floor,
		(data->pos.x * 80), (data->pos.y * 80));
	if (possible_move(data, dir))
	{
		add_score(data, dir);
		data->pos.x += dx;
		data->pos.y += dy;
	}
}

int	possible_move(t_data *data, char dir)
{
	int	dx;
	int	dy;
	int	new_x;
	int	new_y;

	get_direction(dir, &dx, &dy);
	new_x = data->pos.x + dx;
	new_y = data->pos.y + dy;
	if (new_x < 0 || new_y < 0 || new_x >= data->width || new_y >= data->height)
		return (0);
	if (data->map_content[new_y][new_x] == '1')
		return (0);
	if (data->map_content[new_y][new_x] == 'E')
	{
		if (chest_locked(data))
			return (0);
		else
			return (1);
	}
	return (1);
}

int	chest_locked(t_data *data)
{
	return (!(data->score == data->collectible_amount));
}
