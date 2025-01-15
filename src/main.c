/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:37:46 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/15 15:14:39 by tobesnar         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_data	data;
	int		fd;
	int		fd2;

	if (argc != 2)
		return (0);
	else
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[1], O_RDONLY);
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (1);
		data.win_ptr = mlx_new_window(data.mlx_ptr, (data.height * 10), (data.width  * 10), "Test");
		if (!data.win_ptr)
			return (free(data.mlx_ptr), 1);
		set_sprite(&data);
		init_tab(&data, fd);
		print_map(&data);
		mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &end, &data);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
		mlx_loop_hook(data.mlx_ptr, &print_player, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}

