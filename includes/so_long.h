/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:39:55 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/06 17:02:47 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_content
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}	t_content;

typedef struct pos_s
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_sprite
{
	void	*sprite_floor;
	void	*sprite_player;
	void	*sprite_exit;
	void	*sprite_wall;
	void	*sprite_collect;

	int		height;
	int		width;

	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}	t_sprite;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			count;
	t_sprite	sprite;
	t_pos		position;
	int			width;
	int			height;
	t_content	content;
	char		**map;
}	t_data;

void	set_sprite(t_data *data);
int		on_keypress(int keycode, t_data *data);
int		end(t_data *data);
void	set_content(t_content *content);
int		main(void);

#endif
