/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:19:09 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/15 13:42:47 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_sprite(t_data *data)
{
	data->sprite.height = 80;
	data->sprite.width = 80;
	data->sprite.floor = "./assets/floor.xpm";
	data->sprite.wall = "./assets/wall.xpm";
	data->sprite.player = "./assets/mage.xpm";
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprite.img_player, (x * 80), (y * 80));
	return (0);
}

int	init_tab(t_data *data, int fd)
{
	int			i;
	char		*line;
	static int	count = 0;
	char		**old_map;

	data->map_content = NULL;
	old_map = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		if (data->map_content)
			old_map = data->map_content;
		data->map_content = ft_calloc(count + 1, sizeof(char *));
		if (old_map)
		{
			i = -1;
			while (old_map[++i])
			{
				data->map_content[i] = old_map[i];
			}
		}
		data->map_content[i] = line;
	}
	data->height = count;
	data->width = ft_strlen(data->map_content[0]);
	i = -1;
	while (data->map_content[++i])
	{
		ft_putstr_fd(data->map_content[i], 0);
	}
	return (0);
}

// while (line)
	// {
	// 	while (line[i])
	// 	{
	// 		data->map_content[count - 1][i] = line[i];
	// 		i++;
	// 	}
	// 	i = 0;
	// 	line = get_next_line(fd);
	// 	count++;
	// }
