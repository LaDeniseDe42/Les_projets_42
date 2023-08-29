/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:56:01 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/01 16:50:15 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_ray_value(t_ray *r, t_cub *cub)
{
	if (r->angle > 2 * PI)
		r->angle -= 2 * PI;
	else if (r->angle < 0)
		r->angle += 2 * PI;
	init_ray(r, cub, 0);
	init_ray2(r, cub, 0);
	r->ray.angle = r->angle;
	r->ray_v.angle = r->angle;
	r->ray.ray_nbr = r->ray_nbr;
	r->ray_v.ray_nbr = r->ray_nbr;
	r->vert_dist = sqrt(pow(cub->player.px - r->ray_v.a_x, 2)
			+ pow(cub->player.py - r->ray_v.a_y, 2));
	r->hori_dist = sqrt(pow(cub->player.px - r->ray.a_x, 2)
			+ pow(cub->player.py - r->ray.a_y, 2));
}

void	loop_handler(void *param)
{
	t_ray	r;
	t_cub	*cub;

	cub = param;
	init_the_loop_ray(&r, cub);
	while (r.ray_nbr < SCREEN_SIZE_X)
	{
		set_ray_value(&r, cub);
		if (r.hori_dist < r.vert_dist)
		{
			r.ray.hit_h = 1;
			draw_nathan_face(r.hori_dist, cub, &r.ray, r.ray.hit_h);
		}
		else
		{
			r.ray_v.hit_v = 0;
			draw_nathan_face(r.vert_dist, cub, &r.ray_v, r.ray_v.hit_v);
		}
		r.angle += (cub->player.fov / SCREEN_SIZE_X * PI / 180);
		r.ray_nbr++;
	}
}
