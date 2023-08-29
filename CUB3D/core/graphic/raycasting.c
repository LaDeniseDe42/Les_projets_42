/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:03:26 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/04 14:05:24 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	set_horizontal_ray_value(t_ray *r, t_cub *cub, float tang)
{
	int	i;

	i = 0;
	if (r->angle > PI)
	{
		r->ray.direction = 1;
		r->ray.y_a = -64;
		r->ray.a_y = ((int)(cub->player.py / 64) * 64) - 0.0002;
	}
	else if (r->angle < PI)
	{
		r->ray.direction = 3;
		r->ray.y_a = 64;
		r->ray.a_y = ((int)(cub->player.py / 64) * 64) + 64;
	}
	r->ray.a_x = (cub->player.py - r->ray.a_y) * tang + cub->player.px;
	r->ray.x_a = -r->ray.y_a * tang;
	r->ray.pos_a_y = (int)r->ray.a_y / 64;
	r->ray.pos_a_x = (int)r->ray.a_x / 64;
	if (r->ray.pos_a_x < 0 || r->ray.pos_a_y < 0
		|| r->ray.pos_a_x > cub->largeur - 1
		|| r->ray.pos_a_y > cub->hauteur - 1)
		i = 1;
	return (i);
}

void	init_ray(t_ray *r, t_cub *cub, float tang)
{
	tang = -1.0f / tanf(r->angle);
	if (set_horizontal_ray_value(r, cub, tang) == 1)
		return ;
	if (cub->map[r->ray.pos_a_y][r->ray.pos_a_x] != '1')
	{
		while (cub->map[r->ray.pos_a_y][r->ray.pos_a_x] != '1'
		&& cub->map[r->ray.pos_a_y][r->ray.pos_a_x] != 'C'
		&& cub->map[r->ray.pos_a_y][r->ray.pos_a_x] != 'Q'
		&& cub->map[r->ray.pos_a_y][r->ray.pos_a_x] != 'O'
		&& cub->map[r->ray.pos_a_y][r->ray.pos_a_x] != '+'
		&& cub->map[r->ray.pos_a_y][r->ray.pos_a_x] != '-')
		{
			r->ray.a_y += r->ray.y_a;
			r->ray.a_x += r->ray.x_a;
			r->ray.pos_a_y = (int)r->ray.a_y / 64;
			r->ray.pos_a_x = (int)r->ray.a_x / 64;
			if (r->ray.pos_a_x < 0 || r->ray.pos_a_y < 0
				|| r->ray.pos_a_x > cub->largeur - 1
				|| r->ray.pos_a_y > cub->hauteur - 1)
				break ;
		}
	}
	else
		return ;
}

int	set_vertical_ray_value(t_ray *r, t_cub *cub, float tang)
{
	int	i;

	i = 0;
	if (r->angle > (PI / 2) && r->angle < (3 * PI / 2))
	{
		r->ray_v.direction = 2;
		r->ray_v.a_x = ((int)(cub->player.px / 64) * 64) - 0.0002;
		r->ray_v.x_a = -64;
	}
	else
	{
		r->ray_v.direction = 4;
		r->ray_v.a_x = ((int)(cub->player.px / 64) * 64) + 64;
		r->ray_v.x_a = 64;
	}
	r->ray_v.a_y = (cub->player.px - r->ray_v.a_x) * tang + cub->player.py;
	r->ray_v.y_a = -r->ray_v.x_a * tang;
	r->ray_v.pos_a_y = (int)r->ray_v.a_y / 64;
	r->ray_v.pos_a_x = (int)r->ray_v.a_x / 64;
	if (r->ray_v.pos_a_x < 0 || r->ray_v.pos_a_y < 0
		|| r->ray_v.pos_a_x > cub->largeur - 1
		|| r->ray_v.pos_a_y > cub->hauteur - 1)
		i = 1;
	return (i);
}

void	init_ray2(t_ray *r, t_cub *cub, float tang)
{
	tang = -tanf(r->angle);
	if (set_vertical_ray_value(r, cub, tang) == 1)
		return ;
	if (cub->map[r->ray_v.pos_a_y][r->ray_v.pos_a_x] != '1')
	{
		while (cub->map[r->ray_v.pos_a_y][r->ray_v.pos_a_x] != '1'
		&& cub->map[r->ray_v.pos_a_y][r->ray_v.pos_a_x] != 'C'
		&& cub->map[r->ray_v.pos_a_y][r->ray_v.pos_a_x] != 'Q'
		&& cub->map[r->ray_v.pos_a_y][r->ray_v.pos_a_x] != 'O'
		&& cub->map[r->ray_v.pos_a_y][r->ray_v.pos_a_x] != '+'
		&& cub->map[r->ray_v.pos_a_y][r->ray_v.pos_a_x] != '-')
		{
			r->ray_v.a_y += r->ray_v.y_a;
			r->ray_v.a_x += r->ray_v.x_a;
			r->ray_v.pos_a_y = (int)r->ray_v.a_y / 64;
			r->ray_v.pos_a_x = (int)r->ray_v.a_x / 64;
			if (r->ray_v.pos_a_x < 0 || r->ray_v.pos_a_y < 0
				|| r->ray_v.pos_a_x > cub->largeur - 1
				|| r->ray_v.pos_a_y > cub->hauteur - 1)
				break ;
		}
	}
}
