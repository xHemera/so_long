/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_elt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:59:45 by tobesnar          #+#    #+#             */
/*   Updated: 2025/04/10 16:58:45 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_message(t_game *game, int player_count,
			int exit_count, int collectible_count)
{
	if (player_count != 1)
	{
		perror("Error\nnombre de joueurs incorrect.\n");
		exit_map(game);
		exit(0);
	}
	if (exit_count != 1)
	{
		perror("Error\npas de sortie.\n");
		exit_map(game);
		exit(0);
	}
	if (collectible_count < 1)
	{
		perror("Error\npas de collectible.\n");
		exit_map(game);
		exit(0);
	}
}

void	count_map_elements(t_game *game,
	int *player_count, int *exit_count, int *collectible_count)
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
			if (tile == 'P')
				(*player_count)++;
			else if (tile == 'E')
				(*exit_count)++;
			else if (tile == 'C')
				(*collectible_count)++;
			x++;
		}
		y++;
	}
}

void	validate_map(t_game *game)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	count_map_elements(game, &player_count, &exit_count, &collectible_count);
	error_message(game, player_count, exit_count, collectible_count);
}

void	check_reachability(t_game *game)
{
	game->clone = clone_map(game);
	flood_fill(game, game->player_x,
		game->player_y);
	check_unreachable_collectibles(game, game->map,
		game->rows, game->cols);
	check_unreachable_exit(game, game->map,
		game->rows, game->cols);
	free_clone(game, game->rows);
}

void	validate_playable_map(t_game *game)
{
	validate_walls_and_rectangle(game);
	validate_map(game);
	check_reachability(game);
}
