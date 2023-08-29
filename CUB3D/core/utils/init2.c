/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:23:10 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/09 16:25:36 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	init_cub2(t_cub *cub)
{
	cub->d_oc = NULL;
	cub->d_o = NULL;
	cub->hauteur = 0;
	cub->largeur = 0;
	init_position(&cub->pos);
}

void	init_cub(t_cub *cub)
{
	cub->fd_file = 0;
	cub->complete_read = NULL;
	cub->no_texture_path = NULL;
	cub->so_texture_path = NULL;
	cub->we_texture_path = NULL;
	cub->ea_texture_path = NULL;
	cub->floor_color = NULL;
	cub->ceilling_color = NULL;
	cub->map = NULL;
	cub->n_tex = NULL;
	cub->s_tex = NULL;
	cub->w_tex = NULL;
	cub->e_tex = NULL;
	cub->pf[0] = NULL;
	cub->pf[1] = NULL;
	cub->pf[2] = NULL;
	cub->pf[3] = NULL;
	cub->pf[4] = NULL;
	cub->pf[5] = NULL;
	cub->pf[6] = NULL;
	cub->pf[7] = NULL;
	cub->pf[8] = NULL;
	cub->d_c = NULL;
	cub->d_co = NULL;
	init_cub2(cub);
}

void	put_colors_in_tab_error(t_cub *cub)
{
	free_struct(cub);
	exit(printf("cub3D: Error: code RGB is invalid\n") - 33);
}

void	exit_flood_fill_error(char *str, t_cub *cub)
{
	free_struct(cub);
	exit(printf("%s\n", str) - (ft_strlen(str) - 1));
}
