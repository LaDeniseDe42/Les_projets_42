/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:19:38 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/08 10:56:23 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	dont_cross_wall_or_door_w(t_cub *cub)
{
	if (cub->map[(int)(floorf(cub->player.py + cub->player.delta_y)
			/ 64)][(int)(floorf(cub->player.px + cub->player.delta_x)
			/ 64)] == '1' || (cub->map[(int)(floorf(cub->player.py)
				/ 64)][(int)(floorf(cub->player.px + cub->player.delta_x)
				/ 64)] == '1' && cub->map[(int)(floorf(cub->player.py
					+ cub->player.delta_y) / 64)][(int)(floorf(cub->player.px)
				/ 64)] == '1')
			|| cub->map[(int)(floorf(cub->player.py + cub->player.delta_y)
			/ 64)][(int)(floorf(cub->player.px + cub->player.delta_x)
			/ 64)] == 'C' || (cub->map[(int)(floorf(cub->player.py)
				/ 64)][(int)(floorf(cub->player.px + cub->player.delta_x)
				/ 64)] == 'C' && cub->map[(int)(floorf(cub->player.py
					+ cub->player.delta_y) / 64)][(int)(floorf(cub->player.px)
				/ 64)] == 'C'))
		return (1);
	else
		return (0);
}

int	dont_cross_wall_or_door_a(t_cub *cub)
{
	if (cub->map[(int)floor(cub->player.py + (int)(sinf(cub->player.pa - (PI
						/ 2)) * (PLAYER_SPEED))) / 64][(int)floor(cub->player.px
			+ (int)(cosf(cub->player.pa - (PI / 2)) * PLAYER_SPEED))
		/ 64] == '1' || (cub->map[(int)floor(cub->player.py
				+ (int)(sinf(cub->player.pa - (PI / 2)) * (PLAYER_SPEED)))
			/ 64][(int)floor(cub->player.px) / 64] == '1'
			&& cub->map[(int)floor(cub->player.py)
			/ 64][(int)floor(cub->player.px + (int)(cosf(cub->player.pa - (PI
							/ 2)) * PLAYER_SPEED)) / 64] == '1')
			|| cub->map[(int)floor(cub->player.py
				+ (int)(sinf(cub->player.pa - (PI
						/ 2)) * (PLAYER_SPEED))) / 64][(int)floor(cub->player.px
			+ (int)(cosf(cub->player.pa - (PI / 2)) * PLAYER_SPEED))
		/ 64] == 'C' || (cub->map[(int)floor(cub->player.py
				+ (int)(sinf(cub->player.pa - (PI / 2)) * (PLAYER_SPEED)))
			/ 64][(int)floor(cub->player.px) / 64] == 'C'
			&& cub->map[(int)floor(cub->player.py)
			/ 64][(int)floor(cub->player.px + (int)(cosf(cub->player.pa - (PI
							/ 2)) * PLAYER_SPEED)) / 64] == 'C'))
		return (1);
	else
		return (0);
}

int	dont_cross_wall_or_door_d(t_cub *cub)
{
	if (cub->map[(int)floor(cub->player.py - (int)(sinf(cub->player.pa - (PI
						/ 2)) * (PLAYER_SPEED))) / 64][(int)floor(cub->player.px
			- (int)(cosf(cub->player.pa - (PI / 2)) * PLAYER_SPEED))
		/ 64] == '1' || (cub->map[(int)floor(cub->player.py
				- (int)(sinf(cub->player.pa - (PI / 2)) * (PLAYER_SPEED)))
			/ 64][(int)floor(cub->player.px) / 64] == '1'
			&& cub->map[(int)floor(cub->player.py)
			/ 64][(int)floor(cub->player.px - (int)(cosf(cub->player.pa - (PI
							/ 2)) * PLAYER_SPEED)) / 64] == '1')
		|| cub->map[(int)floor(cub->player.py
			- (int)(sinf(cub->player.pa - (PI / 2))
			* (PLAYER_SPEED))) / 64][(int)floor(cub->player.px
			- (int)(cosf(cub->player.pa - (PI / 2)) * PLAYER_SPEED))
		/ 64] == 'C' || (cub->map[(int)floor(cub->player.py
				- (int)(sinf(cub->player.pa - (PI / 2)) * (PLAYER_SPEED)))
			/ 64][(int)floor(cub->player.px) / 64] == 'C'
			&& cub->map[(int)floor(cub->player.py)
			/ 64][(int)floor(cub->player.px - (int)(cosf(cub->player.pa - (PI
							/ 2)) * PLAYER_SPEED)) / 64] == 'C'))
		return (1);
	else
		return (0);
}

int	dont_cross_wall_or_door_s(t_cub *cub)
{
	if (cub->map[(int)(floorf(cub->player.py - cub->player.delta_y)
			/ 64)][(int)(floorf(cub->player.px - cub->player.delta_x)
			/ 64)] == '1' || (cub->map[(int)(floorf(cub->player.py)
				/ 64)][(int)(floorf(cub->player.px - cub->player.delta_x)
				/ 64)] == '1' && cub->map[(int)(floorf(cub->player.py
					- cub->player.delta_y) / 64)][(int)(floorf(cub->player.px)
				/ 64)] == '1')
			|| cub->map[(int)(floorf(cub->player.py - cub->player.delta_y)
			/ 64)][(int)(floorf(cub->player.px - cub->player.delta_x)
			/ 64)] == 'C' || (cub->map[(int)(floorf(cub->player.py)
				/ 64)][(int)(floorf(cub->player.px - cub->player.delta_x)
				/ 64)] == 'C' && cub->map[(int)(floorf(cub->player.py
					- cub->player.delta_y) / 64)][(int)(floorf(cub->player.px)
				/ 64)] == 'C'))
		return (1);
	else
		return (0);
}

int	try_again(t_cub *cub)
{
	if (((cub->map[(int)(floorf(cub->player.py + cub->player.delta_y)
					/ 64)][(int)(floorf(cub->player.px + cub->player.delta_x)
			/ 64)] == 'Q' && !(cub->pf[cub->what_pf] == cub->pf[8])))
			|| ((cub->map[(int)(floorf(cub->player.py)
				/ 64)][(int)(floorf(cub->player.px + cub->player.delta_x)
				/ 64)] == 'Q' && !(cub->pf[cub->what_pf] == cub->pf[8]))
				&& (cub->map[(int)(floorf(cub->player.py
					+ cub->player.delta_y) / 64)]
					[(int)(floorf(cub->player.px) / 64)] == 'Q'
					&& !(cub->pf[cub->what_pf] == cub->pf[8]))))
	{
		init_player(cub);
		return (1);
	}
	else
		return (0);
}
