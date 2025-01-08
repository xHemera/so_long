/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:39:55 by tobesnar          #+#    #+#             */
/*   Updated: 2025/01/08 14:26:17 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1234
# endif

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
