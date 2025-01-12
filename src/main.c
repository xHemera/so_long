/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:37:46 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/12 13:18:50 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define X(x)	(x * 80)
#define Y(x)	(x * 80)
#define TILE_SIZE	80

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

int print_map(t_data data, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[i])
		{
			if (line[i] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprite.sprite_wall, (i * TILE_SIZE), (j * TILE_SIZE));
			else if (line[i] == '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprite.sprite_floor, (i * TILE_SIZE), (j * TILE_SIZE));
			else if (line[i] == 'p')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprite.sprite_player, (i * TILE_SIZE), (j * TILE_SIZE));
			i++;
		}
		i = 0;
		line = get_next_line(fd);
		j++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	else
	{
		t_data	data;
		int fd;

		fd = open(argv[1], O_RDONLY);
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (1);
		data.win_ptr = mlx_new_window(data.mlx_ptr, (X(8)), (Y(5)), "Test");
		if (!data.win_ptr)
			return (free(data.mlx_ptr), 1);
		set_sprite(&data);
		print_map(data, fd);
		mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &end, &data);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}

