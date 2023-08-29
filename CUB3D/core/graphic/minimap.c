/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:52:46 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/07 14:01:31 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_minimap_cube(t_cub *cub, t_index *k, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (SCREEN_SIZE_Y / 3) / MINIMAP_SIZE)
	{
		j = 0;
		while (j < (SCREEN_SIZE_Y / 3) / MINIMAP_SIZE)
		{
			mlx_put_pixel(cub->minimap, i
				+ (((SCREEN_SIZE_Y / 3) / MINIMAP_SIZE) * k->j),
				j + (((SCREEN_SIZE_Y / 3) / MINIMAP_SIZE) * k->i), color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ((SCREEN_SIZE_Y / 3) / MINIMAP_SIZE) / 2)
	{
		j = 0;
		while (j < ((SCREEN_SIZE_Y / 3) / MINIMAP_SIZE) / 2)
		{
			mlx_put_pixel(cub->minimap, i + (cub->minimap->height / 2
					- (((SCREEN_SIZE_Y / 3) / MINIMAP_SIZE) / 2)
					+ ((SCREEN_SIZE_Y / 3) / MINIMAP_SIZE) / 5),
				j + (cub->minimap->height / 2
					- ((SCREEN_SIZE_Y / 3) / MINIMAP_SIZE) / 2)
				+ (((SCREEN_SIZE_Y / 3) / MINIMAP_SIZE))
				/ 5, ft_pixel(255, 0, 0, 255));
			j++;
		}
		i++;
	}
}

void	draw_this_if(t_cub *cub, t_index i, t_pos pos)
{
	if (pos.x >= 0 && pos.y >= 0 && pos.y < cub->hauteur && pos.x
		< cub->largeur && cub->map[pos.y][pos.x]
			&& cub->map[pos.y][pos.x] == '0')
		draw_minimap_cube(cub, &i, ft_pixel(255, 255, 255, 255));
	else if (pos.x >= 0 && pos.y >= 0 && pos.y < cub->hauteur
		&& pos.x < cub->largeur && cub->map[pos.y][pos.x]
		&& (cub->map[pos.y][pos.x] == 'O' ||
			cub->map[pos.y][pos.x] == '+' || cub->map[pos.y][pos.x] == '-'))
		draw_minimap_cube(cub, &i, ft_pixel(0, 255, 0, 255));
	else if (pos.x >= 0 && pos.y >= 0 && pos.y < cub->hauteur
		&& pos.x < cub->largeur && cub->map[pos.y][pos.x]
		&& (cub->map[pos.y][pos.x] == 'C'))
		draw_minimap_cube(cub, &i, ft_pixel(200, 0, 0, 255));
	else if (pos.x >= 0 && pos.y >= 0 && pos.y < cub->hauteur
		&& pos.x < cub->largeur && cub->map[pos.y][pos.x]
			&& (cub->map[pos.y][pos.x] == 'Q'))
		draw_minimap_cube(cub, &i, ft_pixel(254, 195, 172, 255));
	else if (pos.x >= 0 && pos.y >= 0 && pos.y < cub->hauteur
		&& pos.x < cub->largeur && cub->map[pos.y][pos.x]
		&& (cub->map[pos.y][pos.x] == 'N' || cub->map[pos.y][pos.x] == 'S'
		|| cub->map[pos.y][pos.x] == 'E' || (cub->map[pos.y][pos.x] == 'W')))
		draw_minimap_cube(cub, &i, ft_pixel(200, 200, 200, 255));
	else
		draw_minimap_cube(cub, &i, ft_pixel(0, 0, 0, 255));
}

void	minimap_handler(void *param)
{
	t_cub	*cub;
	t_index	i;
	t_pos	pos;

	cub = param;
	pos.x = (int)cub->player.px / 64 - (MINIMAP_SIZE / 2);
	pos.y = ((int)cub->player.py / 64) - (MINIMAP_SIZE / 2);
	init_index(&i);
	while (i.i < MINIMAP_SIZE)
	{
		pos.x = (int)cub->player.px / 64 - (MINIMAP_SIZE / 2);
		i.j = 0;
		while (i.j < MINIMAP_SIZE)
		{
			draw_this_if(cub, i, pos);
			pos.x++;
			i.j++;
		}
		pos.y++;
		i.i++;
	}
	draw_player(cub);
}
