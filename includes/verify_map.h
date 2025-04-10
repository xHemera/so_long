/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobesnar <tobesnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:55:12 by tobesnar          #+#    #+#             */
/*   Updated: 2025/04/10 15:59:20 by tobesnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIFY_MAP_H
# define VERIFY_MAP_H

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

int     verify_map(char **map);
char    **copy_map(char **map);
void    floodfill(char **map, int x, int y);
int     is_path_valid(char **map);
void    free_map_copy(char **map);

#endif
