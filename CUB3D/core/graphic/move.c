/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:23:10 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/09 15:03:47 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_handler(void *param)
{
	t_cub	*cub;

	cub = param;
	if (mlx_is_key_down(cub->id, MLX_KEY_W))
		press_w(cub);
	else if (mlx_is_key_down(cub->id, MLX_KEY_A))
		press_a(cub);
	else if (mlx_is_key_down(cub->id, MLX_KEY_D))
		press_d(cub);
	else if (mlx_is_key_down(cub->id, MLX_KEY_S))
		press_s(cub);
	if (mlx_is_key_down(cub->id, MLX_KEY_RIGHT))
		press_right(cub);
	if (mlx_is_key_down(cub->id, MLX_KEY_LEFT))
		press_left(cub);
	else if (mlx_is_key_down(cub->id, MLX_KEY_ESCAPE))
	{
		free_struct(cub);
		exit(0);
	}
}

void	press_right(t_cub *cub)
{
	cub->player.pa += 0.1;
	if (cub->player.pa > 2 * PI)
			cub->player.pa -= 2 * PI;
	cub->player.delta_x = cosf(cub->player.pa) * cub->player.speed;
	cub->player.delta_y = sinf(cub->player.pa) * cub->player.speed;
}

void	press_left(t_cub *cub)
{
	cub->player.pa -= 0.1;
	if (cub->player.pa < 0)
			cub->player.pa += 2 * PI;
	cub->player.delta_x = cosf(cub->player.pa) * cub->player.speed;
	cub->player.delta_y = sinf(cub->player.pa) * cub->player.speed;
}
