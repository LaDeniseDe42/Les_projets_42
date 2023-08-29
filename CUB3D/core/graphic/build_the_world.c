/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_the_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:35:43 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/09 09:56:56 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_value_of_god_building(t_god *god, t_cub *cub,
			t_rayx *ray, float dist)
{
	god->i_pixel_y = 0;
	god->fish_eyes = cub->player.pa - ray->angle;
	if (god->fish_eyes > 2 * PI)
		god->fish_eyes -= 2 * PI;
	else if (god->fish_eyes < 0)
		god->fish_eyes += 2 * PI;
	dist = dist * cosf(god->fish_eyes);
	god->hauteur = (SCREEN_SIZE_Y * 64) / (dist);
	god->ciel = (SCREEN_SIZE_Y - god->hauteur) / 2;
	god->sol = (SCREEN_SIZE_Y + god->hauteur) / 2;
	god->color = 0;
	god->step = 64.0f / (float)(god->hauteur);
	god->current_step = 0.0f;
	god->wall = (SCREEN_SIZE_Y + god->hauteur) / 2;
	if (god->wall > SCREEN_SIZE_Y)
	{
		god->current_step = (god->hauteur - SCREEN_SIZE_Y) / 2.0;
		god->wall = SCREEN_SIZE_Y;
	}
	god->current_step *= god->step;
}

void	build_south_and_west(t_god *god, t_cub *cub,
			t_rayx *ray, int id)
{
	if (id == 1 && ray->direction == 3)
	{
		god->value = (((int)(ray->a_x) % 64)
				+ ((int)god->current_step * 64)) * 4;
		build_south(god, cub, ray);
	}
	else
	{
		god->value = (((int)(ray->a_y) % 64)
				+ ((int)god->current_step * 64)) * 4;
		build_west(god, cub, ray);
	}
}

void	draw_my_wall_like_a_french_girl(t_god *god, t_cub *cub,
			t_rayx *ray, int id)
{
	if (id == 1 && ray->direction == 1)
	{
		god->value = ((((int)(ray->a_x) % 64)
					+ ((int)god->current_step) * 64)) * 4;
		build_north(god, cub, ray);
	}
	else if (id == 0 && ray->direction == 2)
	{
		god->value = (((int)(ray->a_y) % 64)
				+ ((int)god->current_step * 64)) * 4;
		build_est(god, cub, ray);
	}
	else
		build_south_and_west(god, cub, ray, id);
}

void	draw_nathan_face(float dist, t_cub *cub, t_rayx *ray, int id)
{
	t_god	god;

	set_value_of_god_building(&god, cub, ray, dist);
	if (id == 0 && ray->direction == 2)
		ray->a_y = 63 - ((int)ray->a_y % 64);
	else if (id == 1 && ray->direction == 3)
		ray->a_x = 63 - ((int)ray->a_x % 64);
	while (god.i_pixel_y < SCREEN_SIZE_Y)
	{
		if (god.i_pixel_y < god.ciel)
			mlx_put_pixel(cub->d_3, ray->ray_nbr, god.i_pixel_y,
				ft_pixel(cub->ceilling[0], cub->ceilling[1],
					cub->ceilling[2], 255));
		else if (god.i_pixel_y < god.wall)
		{
			draw_my_wall_like_a_french_girl(&god, cub, ray, id);
			mlx_put_pixel(cub->d_3, ray->ray_nbr, god.i_pixel_y, god.color);
			god.current_step += god.step;
		}
		else
			mlx_put_pixel(cub->d_3, ray->ray_nbr, god.i_pixel_y,
				ft_pixel(cub->floor[0], cub->floor[1], cub->floor[2], 255));
		god.i_pixel_y++;
	}
}
