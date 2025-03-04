/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:37:46 by tobesnar          #+#    #+#             */
/*   Updated: 2025/03/04 17:25:00 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end(t_data *data)
{
	int	i;

	i = 0;
	destroy_images(data);
	while (data->map_content[i])
	{
		free(data->map_content[i]);
		i++;
	}
	free(data->map_content);
	if (data->mlx_ptr != NULL)
	{
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	exit(0);
	return (0);
}

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprite.img_collect);
	mlx_destroy_image(data->mlx_ptr, data->sprite.img_exit);
	mlx_destroy_image(data->mlx_ptr, data->sprite.img_player);
	mlx_destroy_image(data->mlx_ptr, data->sprite.img_wall);
	mlx_destroy_image(data->mlx_ptr, data->sprite.img_floor);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		fd;

	if (argc != 2)
		return (0);
	else
	{
		fd = open(argv[1], O_RDONLY);
		init_data(&data);
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (1);
		set_sprite(&data);
		init_tab(&data, fd);
		check_map_params(&data);
		data.win_ptr = mlx_new_window(data.mlx_ptr,
				(data.width * 80), (data.height * 80), "so_long");
		if (!data.win_ptr)
			return (free(data.mlx_ptr), 1);
		initialise_map_checker(&data);
		check_is_possible(&data, data.pos.y, data.pos.x);
		print_map(&data);
		mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &end, &data);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
		mlx_loop_hook(data.mlx_ptr, &print_player, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
