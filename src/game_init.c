/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:19:09 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/26 14:33:11 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_sprite(t_data *data)
{
	data->sprite.height = 80;
	data->sprite.width = 80;
	data->sprite.floor = "./assets/floor.xpm";
	data->sprite.collect = "./assets/collect.xpm";
	data->sprite.exit = "./assets/closed-chest.xpm";
	data->sprite.wall = "./assets/wall.xpm";
	data->sprite.player = "./assets/mage.xpm";
	data->sprite.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.collect, &(data->sprite.width),
			&(data->sprite.height));
	data->sprite.img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.exit, &(data->sprite.width), &(data->sprite.height));
	data->sprite.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.wall, &(data->sprite.width), &(data->sprite.height));
	data->sprite.img_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.floor, &(data->sprite.width), &(data->sprite.height));
	data->sprite.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sprite.player, &(data->sprite.width), &(data->sprite.height));
}

int	init_player(t_data *data, int x, int y)
{
	data->pos.x = x;
	data->pos.y = y;
	data->score = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprite.img_player, (x * 80), (y * 80));
	return (0);
}

static char	**add_line_to_map(char **old_map, char *line, int count)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(count + 1, sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	if (old_map)
	{
		while (old_map[i])
		{
			new_map[i] = old_map[i];
			i++;
		}
		free(old_map);
	}
	new_map[i] = line;
	return (new_map);
}

int	init_tab(t_data *data, int fd)
{
	int		count;
	char	*line;
	int		i;

	data->map_content = NULL;
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		data->map_content = add_line_to_map(data->map_content, line, count);
		if (!data->map_content)
			return (-1);
	}
	i = 0;
	while (data->map_content[i])
	{
		ft_putstr_fd(data->map_content[i], 0);
		i++;
	}
	data->height = count;
	data->width = ft_strlen(data->map_content[0]);
	return (0);
}
