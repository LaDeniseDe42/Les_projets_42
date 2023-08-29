/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:22:21 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/10 12:55:43 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	resize_handler(int width, int height, void *param)
{
	t_cub	*cub;

	cub = param;
	cub->modified_x = width;
	cub->modified_y = height;
}

void	pf_handler(void *param)
{
	t_cub	*cub;

	cub = param;
	if (cub->time_pf == 0)
		cub->time_pf = mlx_get_time();
	if (cub->time_pf + 0.7 < mlx_get_time())
	{
		cub->what_pf++;
		if (cub->what_pf == 9)
			cub->what_pf = 0;
		cub->time_pf = mlx_get_time();
		return ;
	}
}

void	do_all_the_job(t_cub *cub)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	cub->id = mlx_init(SCREEN_SIZE_X, SCREEN_SIZE_Y,
			"DO YOU LIKE MY  BIG CUBE ?", true);
	image_manager(cub);
	load_pf(cub);
	cub->cursor_stuck = true;
	init_player(cub);
	mlx_key_hook(cub->id, action_handler, cub);
	mlx_loop_hook(cub->id, move_handler, cub);
	mlx_loop_hook(cub->id, loop_handler, cub);
	mlx_loop_hook(cub->id, door_handler, cub);
	mlx_loop_hook(cub->id, pf_handler, cub);
	mlx_loop(cub->id);
}

void	graphic(t_cub *cub)
{
	t_index		i;

	init_index(&i);
	calcul_len_max(cub);
	set_lines(cub);
	cub->time = 0;
	cub->origin_curseur_x = 0;
	cub->origin_curseur_y = 0;
	cub->what_pf = 0;
	cub->nb_try = 0;
	do_all_the_job(cub);
	mlx_terminate(cub->id);
	free_struct(cub);
}
