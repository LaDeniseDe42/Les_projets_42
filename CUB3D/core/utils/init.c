/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:38:12 by akastler          #+#    #+#             */
/*   Updated: 2023/08/09 16:04:33 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_index(t_index *index)
{
	index->i = 0;
	index->j = 0;
	index->k = 0;
	index->l = 0;
	index->n = 0;
	index->w = 0;
	index->e = 0;
	index->s = 0;
	index->flag = 0;
	index->flag2 = 0;
}

void	init_position(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
}

void	init_player(t_cub *cub)
{
	cub->player.fov = 60;
	if (cub->map[cub->pos.y][cub->pos.x] == 'N')
		cub->player.pa = 3 * PI / 2;
	else if (cub->map[cub->pos.y][cub->pos.x] == 'S')
		cub->player.pa = PI / 2;
	else if (cub->map[cub->pos.y][cub->pos.x] == 'W')
		cub->player.pa = PI;
	else if (cub->map[cub->pos.y][cub->pos.x] == 'E')
		cub->player.pa = 2 * PI;
	cub->player.speed = PLAYER_SPEED;
	cub->player.delta_x = cosf(cub->player.pa) * cub->player.speed;
	cub->player.delta_y = sinf(cub->player.pa) * cub->player.speed;
	cub->player.px = cub->pos.x * 64 + 32;
	cub->player.py = cub->pos.y * 64 + 32;
}

void	init_the_loop_ray(t_ray *r, t_cub *cub)
{
	r->angle = cub->player.pa - ((cub->player.fov / 2) * PI / 180);
	r->hori_dist = 0;
	r->ray_nbr = 0;
	r->vert_dist = 0;
}
