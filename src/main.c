/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:37:46 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/06 17:02:38 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
    	end(data);
		printf("\033[35mThis is magenta text.\033[0m\n");
	}
    if (keycode == XK_w)
		write(1, "w ", 2);
    if (keycode == XK_a)
		write(1, "a ", 2);
	if (keycode == XK_s)
		write(1, "s ", 2);
	if (keycode == XK_d)
		write(1, "d ", 2);
	return (0);
}
// void	set_sprite(t_data *data)
// {
// 	data->sprite.height = 80;
// 	data->sprite.width = 80;
// 	data->sprite.floor = "./assets/floor.xpm";
// 	data->sprite.wall = "./assets/wall.xpm";
// 	// data->sprite.collect = "./rsrc/collect.xpm";
// 	data->sprite.player = "./assets/mage.xpm";
// 	// data->sprite.exit = "./rsrc/exit_texture.xpm";
// 	data->sprite.sprite_wall = mlx_xpm_file_to_image(data->mlx_ptr,
// 			data->sprite.wall, &(data->sprite.width), &(data->sprite.height));
// 	data->sprite.sprite_floor = mlx_xpm_file_to_image(data->mlx_ptr,
// 			data->sprite.floor, &(data->sprite.width), &(data->sprite.height));
// 	data->sprite.sprite_player = mlx_xpm_file_to_image(data->mlx_ptr,
// 			data->sprite.player, &(data->sprite.width), &(data->sprite.height));
// }

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();

	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "Test");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &end, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	set_sprite(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.sprite.sprite_player, 1, 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.sprite.sprite_floor, 81, 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.sprite.sprite_floor, 1, 81);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.sprite.sprite_floor, 81, 81);
	mlx_loop(data.mlx_ptr);
	return (0);
}
