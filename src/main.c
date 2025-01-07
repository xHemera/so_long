/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:37:46 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/07 19:37:57 by hemera           ###   ########.fr       */
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

int	read_map_and_display(char *file, t_data *data) {
	int fd;
	char *line;
	int x, y;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	y = 0;
	while (get_next_line(fd, &line) > 0) {
		x = 0;
		while (line[x] != '\0') {
            // Selon le caractère de la carte, afficher l'image correspondante
            if (line[x] == '1') {
				write(1, "Test", 4);
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.sprite_wall, (x * TILE_SIZE), (y * TILE_SIZE));
            } else if (line[x] == '0') {
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.sprite_floor, (x * TILE_SIZE), (y * TILE_SIZE));
            } else if (line[x] == 'p') {
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite.sprite_player, (x * TILE_SIZE), (y * TILE_SIZE));
        	}
			x++;
		}
		y++;
		free(line);
	}
	close(fd);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();

	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (X(7)), (Y(7)), "Test");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &end, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	set_sprite(&data);
	read_map_and_display("../maps/base.ber", &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
