/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:02:19 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/09 15:07:26 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	load_pf(t_cub *cub)
{
	cub->pf[0] = mlx_load_png("./textures/pf.png");
	cub->pf[1] = mlx_load_png("./textures/pf2.png");
	cub->pf[2] = mlx_load_png("./textures/pf3.png");
	cub->pf[3] = mlx_load_png("./textures/pf4.png");
	cub->pf[4] = mlx_load_png("./textures/pf5.png");
	cub->pf[5] = mlx_load_png("./textures/pf6.png");
	cub->pf[6] = mlx_load_png("./textures/pf7.png");
	cub->pf[7] = mlx_load_png("./textures/pf8.png");
	cub->pf[8] = mlx_load_png("./textures/pf9.png");
	if (!cub->pf[0] || !cub->pf[1] || !cub->pf[2]
		|| !cub->pf[3] || !cub->pf[4] || !cub->pf[5] || !cub->pf[6]
		|| !cub->pf[7]
		|| !cub->pf[8])
	{
		printf("Cub3D: Error: Failed to load one or more the images\n");
		free_struct(cub);
		exit(1);
	}
}

void	image_manager(t_cub *cub)
{
	cub->d_3 = mlx_new_image(cub->id, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	cub->minimap = mlx_new_image(cub->id, (SCREEN_SIZE_Y / 3),
			(SCREEN_SIZE_Y / 3));
	cub->n_tex = mlx_load_png(cub->no_texture_path);
	cub->s_tex = mlx_load_png(cub->so_texture_path);
	cub->e_tex = mlx_load_png(cub->we_texture_path);
	cub->w_tex = mlx_load_png(cub->ea_texture_path);
	cub->d_c = mlx_load_png("./textures/door.png");
	cub->d_co = mlx_load_png("./textures/door2.png");
	cub->d_oc = mlx_load_png("./textures/door3.png");
	cub->d_o = mlx_load_png("./textures/door4.png");
	if (!cub->n_tex || !cub->s_tex || !cub->e_tex
		|| !cub->w_tex || !cub->d_c || !cub->d_o || !cub->d_oc || !cub->d_co)
	{
		printf("Cub3D: Error: Failed to load one or more the images\n");
		free_struct(cub);
		exit(1);
	}
	mlx_image_to_window(cub->id, cub->d_3, 0, 0);
	mlx_image_to_window(cub->id, cub->minimap, 0,
		SCREEN_SIZE_Y - ((SCREEN_SIZE_Y / 3) / MINIMAP_SIZE) * MINIMAP_SIZE);
}
