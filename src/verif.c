/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:26:13 by tobesnar          #+#    #+#             */
/*   Updated: 2025/03/04 17:27:44 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_checker(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->height)
		free(data->checker->checked[i]);
	free(data->checker->checked);
	free(data->checker);
}

void	initialise_map_checker(t_data *data)
{
	int	i;
	int	j;

	data->checker = malloc(sizeof(t_check));
	data->checker->checked = ft_calloc(data->height, sizeof(int *));
	data->checker->item = 0;
	data->checker->exit = 0;
	i = -1;
	while (++i < data->height)
		data->checker->checked[i] = ft_calloc(data->width - 1, sizeof(int));
	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width - 1)
			data->checker->checked[i][j] = 0;
	}
}

int	is_checked(t_data *data, int y, int x)
{
	return (data->checker->checked[y][x] == 1);
}

void	count_element(t_data *data, int y, int x)
{
	if (data->map_content[y][x] == 'C')
		data->checker->item += 1;
	if (data->map_content[y][x] == 'E')
		data->checker->exit += 1;
	data->checker->checked[y][x] = 1;
}

int	check_is_possible(t_data *data, int y, int x)
{
	int	result[4];

	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	count_element(data, y, x);
	if (data->checker->exit >= 1 && data->checker->item == data->count.c)
		return (1);
	if (x < 0 || x > data->width || y < 0
		|| y > data->height || data->map_content[y][x] == '1')
		return (0);
	if (data->map_content[y][x + 1] != '1' && !is_checked(data, y, x + 1))
		result[0] = check_is_possible(data, y, x + 1);
	if (data->map_content[y][x - 1] != '1' && !is_checked(data, y, x - 1))
		result[1] = check_is_possible(data, y, x - 1);
	if (data->map_content[y + 1][x] != '1' && !is_checked(data, y + 1, x))
		result[2] = check_is_possible(data, y + 1, x);
	if (data->map_content[y - 1][x] != '1' && !is_checked(data, y - 1, x))
		result[3] = check_is_possible(data, y - 1, x);
	return (result[0] || result[1] || result[2] || result[3]);
}
