/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:13:51 by tobesnar          #+#    #+#             */
/*   Updated: 2025/04/10 16:58:35 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_tile(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x
		* TILE_SIZE, y * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			tile = game->map[y][x];
			draw_tile(game, x, y, game->floor_img);
			if (tile == '1')
				draw_tile(game, x, y, game->wall_img);
			else if (tile == 'P')
				draw_tile(game, x, y, game->player_img);
			else if (tile == 'C')
				draw_tile(game, x, y, game->collectible_img);
			else if (tile == 'E')
				draw_tile(game, x, y, game->exit_img);
			x++;
		}
		y++;
	}
}
