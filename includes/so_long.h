/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:39:55 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/15 16:17:58 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1234
# endif

# define X(x)	(x * 80)
# define Y(x)	(x * 80)
# define TILE_SIZE	80

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct pos_s
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_sprite
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;

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
	t_sprite	sprite;
	t_pos		pos;
	int			width;
	int			height;
	char		**map_content;
}	t_data;

void	set_sprite(t_data *data);
int		on_keypress(int keycode, t_data *data);
int		end(t_data *data);
void		player_move(t_data *data, char dir);
int		print_player(t_data *data);
int		main(int argc, char *argv[]);
int		init_player(t_data *data, int x, int y);
int		print_map(t_data *data);
int		init_tab(t_data *data, int fd);
int movement_is_possible(t_data *data, char dir);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);

size_t	ft_strlen(const char *theString);

char	*ft_free(char *buffer, char *buf);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*read_file(int fd, char *res);
char	*get_next_line(int fd);

#endif
