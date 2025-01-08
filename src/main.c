/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:37:46 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/08 15:11:45 by tobesnar         ###   ########.fr       */
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


char	*read_map(int fd)
{
	char	*line;
	char	*result;
	char	*temp;

	line = NULL;
	result = NULL;
	temp = NULL;
	if (fd == -1)
	{
		perror("Error opening file");
		return ("E");
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (result == NULL)
			result = line;
		else
		{
			temp = result;
			result = ft_strjoin(result, line);
			free(temp);
			free(line);
		}
		line = get_next_line(fd);
	}
	close(fd);
	if (result == NULL)
		return ("E");
	return (result);
}

int print_map(char *line, t_data data)
{
	int		i;
	int		j;

	j = 0;
	while (line)
	{
		i = 0;
		while (line[i] && (i < 10))
		{
			write(1, &line[i], 1);
			write(1, " ", 1);
			if (line[i] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprite.sprite_wall, (i * TILE_SIZE), (j * TILE_SIZE));
			else if (line[i] == '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprite.sprite_floor, (i * TILE_SIZE), (j * TILE_SIZE));
			else if (line[i] == 'p')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprite.sprite_player, (i * TILE_SIZE), (j * TILE_SIZE));
			i++;
		}
		j++;
	}
	return (0);
}

int	main(void)
{
	t_data	data;
	int fd;

	fd = open("maps/base.ber", O_RDONLY);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (X(10)), (Y(10)), "Test");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	set_sprite(&data);
	print_map(read_map(fd), data);

	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &end, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

