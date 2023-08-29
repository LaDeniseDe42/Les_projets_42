/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:47:13 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/09 15:05:40 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_victory_string(t_cub *cub)
{
	if (cub->nb_try == 0)
	{
		mlx_put_string(cub->id, "DIALOG_BOX :", 0, 0);
		mlx_put_string(cub->id, "BRAVO TU AS GAGNE ...\
 LE DROIT DE RECOMMENCER A L'INFINI", 0, 16);
	}
	else if (cub->nb_try == 1)
		mlx_put_string(cub->id, "Ne Cherche pas, c'est un nouveau retour\
 a la case depart qui t'attend", 0, 32);
	else if (cub->nb_try == 2)
		mlx_put_string(cub->id, "Tu es encore la ? Va falloir penser\
 a aller faire tes propres projet", 0, 48);
	else if (cub->nb_try == 3)
		mlx_put_string(cub->id, "OK ok ok... la prochaine fois,\
 je vais t'aider a aller bosser!", 0, 64);
	else if (cub->nb_try == 4)
	{
		free_struct(cub);
		exit(0);
	}
	cub->nb_try++;
	init_player(cub);
}

void	press_w(t_cub *cub)
{
	if (dont_cross_wall_or_door_w(cub) == 1)
		return ;
	if ((cub->map[(int)(floorf(cub->player.py + cub->player.delta_y)
				/ 64)][(int)(floorf(cub->player.px + cub->player.delta_x)
		/ 64)] == 'Q' && cub->pf[cub->what_pf] == cub->pf[8])
		|| ((cub->map[(int)(floorf(cub->player.py)
				/ 64)][(int)(floorf(cub->player.px + cub->player.delta_x)
				/ 64)] == 'Q' && cub->pf[cub->what_pf] == cub->pf[8])
				&& (cub->map[(int)(floorf(cub->player.py
					+ cub->player.delta_y) / 64)][(int)(floorf(cub->player.px)
				/ 64)] == 'Q') && cub->pf[cub->what_pf] == cub->pf[8]))
		put_victory_string(cub);
	else if (try_again(cub) == 1)
		return ;
	cub->player.py += cub->player.delta_y;
	cub->player.px += cub->player.delta_x;
}

void	press_a(t_cub *cub)
{
	if (dont_cross_wall_or_door_a(cub) == 1
		|| cub->map[(int)floor(cub->player.py
				+ (int)(sinf(cub->player.pa - (PI
						/ 2)) * (PLAYER_SPEED))) / 64][(int)floor(cub->player.px
			+ (int)(cosf(cub->player.pa - (PI / 2)) * PLAYER_SPEED))
		/ 64] == 'Q' || (cub->map[(int)floor(cub->player.py
				+ (int)(sinf(cub->player.pa - (PI / 2)) * (PLAYER_SPEED)))
			/ 64][(int)floor(cub->player.px) / 64] == 'Q'
			&& cub->map[(int)floor(cub->player.py)
			/ 64][(int)floor(cub->player.px + (int)(cosf(cub->player.pa - (PI
							/ 2)) * PLAYER_SPEED)) / 64] == 'Q'))
		return ;
	cub->player.px += (cosf(cub->player.pa - (PI / 2)) * cub->player.speed);
	cub->player.py += (sinf(cub->player.pa - (PI / 2)) * cub->player.speed);
}

void	press_d(t_cub *cub)
{
	if (dont_cross_wall_or_door_d(cub) == 1
		|| cub->map[(int)floor(cub->player.py
				- (int)(sinf(cub->player.pa - (PI / 2))
				* (PLAYER_SPEED))) / 64][(int)floor(cub->player.px
			- (int)(cosf(cub->player.pa - (PI / 2)) * PLAYER_SPEED))
		/ 64] == 'Q' || (cub->map[(int)floor(cub->player.py
				- (int)(sinf(cub->player.pa - (PI / 2)) * (PLAYER_SPEED)))
			/ 64][(int)floor(cub->player.px) / 64] == 'Q'
			&& cub->map[(int)floor(cub->player.py)
			/ 64][(int)floor(cub->player.px - (int)(cosf(cub->player.pa - (PI
							/ 2)) * PLAYER_SPEED)) / 64] == 'Q'))
		return ;
	cub->player.px -= (cosf(cub->player.pa - (PI / 2)) * cub->player.speed);
	cub->player.py -= (sinf(cub->player.pa - (PI / 2)) * cub->player.speed);
}

void	press_s(t_cub *cub)
{
	if (dont_cross_wall_or_door_s(cub) == 1
		|| cub->map[(int)(floorf(cub->player.py - cub->player.delta_y)
			/ 64)][(int)(floorf(cub->player.px - cub->player.delta_x)
			/ 64)] == 'Q' || (cub->map[(int)(floorf(cub->player.py)
				/ 64)][(int)(floorf(cub->player.px - cub->player.delta_x)
				/ 64)] == 'Q' && cub->map[(int)(floorf(cub->player.py
					- cub->player.delta_y) / 64)][(int)(floorf(cub->player.px)
				/ 64)] == 'Q'))
		return ;
	cub->player.py -= cub->player.delta_y;
	cub->player.px -= cub->player.delta_x;
}
