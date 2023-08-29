/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_and_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:09:13 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/09 10:09:04 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	reduce_door_handler(t_cub *cub, t_pos pos)
{
	while (pos.x != -1)
	{
		cub->map[pos.y][pos.x] = '-';
		pos = find_pos(cub->map, '+');
	}
	cub->time = mlx_get_time();
	return (0);
}

void	door_handler(void *param)
{
	t_cub	*cub;
	t_pos	pos;

	cub = param;
	if (cub->time == 0)
		cub->time = mlx_get_time();
	if (cub->time + 0.5 < mlx_get_time())
	{
		pos = find_pos(cub->map, '+');
		if (pos.x != -1 && reduce_door_handler(cub, pos) == 0)
			return ;
		pos = find_pos(cub->map, '-');
		if (pos.x != -1)
		{
			while (pos.x != -1)
			{
				cub->map[pos.y][pos.x] = 'O';
				pos = find_pos(cub->map, '-');
			}
			cub->time = mlx_get_time();
			return ;
		}
	}
}

void	press_e(t_cub *cub)
{
	float	y;
	float	x;
	double	time;

	y = cub->player.py + cub->player.delta_y;
	x = cub->player.px + cub->player.delta_x;
	if ((int)cub->player.py / 64 == (int)y / 64
		&& (int)cub->player.px / 64 == (int)x / 64)
	{
		while ((int)cub->player.py / 64 == (int)y / 64
			&& (int)cub->player.px / 64 == (int)x / 64)
		{
			y += cub->player.delta_y;
			x += cub->player.delta_x;
		}
	}
	time = mlx_get_time();
	if (cub->map[(int)y / 64][(int)x / 64] == 'C')
	{
		cub->map[(int)y / 64][(int)x / 64] = '+';
	}
	else if (cub->map[(int)y / 64][(int)x / 64] == 'O')
	{
		cub->map[(int)y / 64][(int)x / 64] = 'C';
	}
}

void	cursor_hook(double x, double y, void *param)
{
	t_cub	*cub;

	cub = param;
	(void)y;
	if (cub->cursor_stuck == false)
		return ;
	if (cub->origin_curseur_x == 0 && cub->origin_curseur_y == 0)
	{
		cub->origin_curseur_x = cub->modified_x / 2;
		cub->origin_curseur_y = cub->modified_y / 2;
	}
	cub->player.pa += (x - cub->origin_curseur_x) / 100;
	if (cub->player.pa > 2 * PI)
		cub->player.pa -= 2 * PI;
	if (cub->player.pa < 0)
		cub->player.pa += 2 * PI;
	cub->player.delta_x = cosf(cub->player.pa) * cub->player.speed;
	cub->player.delta_y = sinf(cub->player.pa) * cub->player.speed;
	mlx_set_mouse_pos(cub->id, cub->origin_curseur_x, cub->origin_curseur_y);
}

void	action_handler(struct mlx_key_data keydata, void *param)
{
	t_cub	*cub;

	cub = param;
	(void)keydata;
	if (mlx_is_key_down(cub->id, MLX_KEY_E))
		press_e(cub);
	if (mlx_is_key_down(cub->id, MLX_KEY_M))
	{
		if (cub->cursor_stuck == false)
		{
			mlx_set_cursor_mode(cub->id, MLX_MOUSE_HIDDEN);
			cub->cursor_stuck = true;
		}
		else if (cub->cursor_stuck == true)
		{
			mlx_set_cursor_mode(cub->id, MLX_MOUSE_NORMAL);
			cub->cursor_stuck = false;
		}
	}
}
