/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_s_w_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:39:11 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/17 14:21:46 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	god_color(mlx_texture_t *img, t_god *god)
{
	god->color = ft_pixel(img->pixels[god->value],
			img->pixels[god->value + 1],
			img->pixels[god->value + 2],
			img->pixels[god->value + 3]);
}

void	build_south(t_god *god, t_cub *cub, t_rayx *ray)
{
	if (ray->pos_a_x < 0 || ray->pos_a_y < 0
		|| ray->pos_a_x > cub->largeur - 1 || ray->pos_a_y > cub->hauteur - 1)
		return ;
	if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'C')
		god_color(cub->d_c, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'Q')
		god_color(cub->pf[cub->what_pf], god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'O')
		god_color(cub->d_o, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == '+')
		god_color(cub->d_co, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == '-')
		god_color(cub->d_oc, god);
	else
		god_color(cub->s_tex, god);
}

void	build_west(t_god *god, t_cub *cub, t_rayx *ray)
{
	if (ray->pos_a_x < 0 || ray->pos_a_y < 0
		|| ray->pos_a_x > cub->largeur - 1 || ray->pos_a_y > cub->hauteur - 1)
		return ;
	if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'C')
		god_color(cub->d_c, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'Q')
		god_color(cub->pf[cub->what_pf], god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'O')
		god_color(cub->d_o, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == '+')
		god_color(cub->d_co, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == '-')
		god_color(cub->d_oc, god);
	else
		god_color(cub->w_tex, god);
}

void	build_north(t_god *god, t_cub *cub, t_rayx *ray)
{
	if (ray->pos_a_x < 0 || ray->pos_a_y < 0
		|| ray->pos_a_x > cub->largeur - 1 || ray->pos_a_y > cub->hauteur - 1)
		return ;
	if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'C')
		god_color(cub->d_c, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'Q')
		god_color(cub->pf[cub->what_pf], god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'O')
		god_color(cub->d_o, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == '+')
		god_color(cub->d_co, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == '-')
		god_color(cub->d_oc, god);
	else
		god_color(cub->n_tex, god);
}

void	build_est(t_god *god, t_cub *cub, t_rayx *ray)
{
	if (ray->pos_a_x < 0 || ray->pos_a_y < 0
		|| ray->pos_a_x > cub->largeur - 1 || ray->pos_a_y > cub->hauteur - 1)
		return ;
	if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'C')
		god_color(cub->d_c, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'Q')
		god_color(cub->pf[cub->what_pf], god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == 'O')
		god_color(cub->d_o, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == '+')
		god_color(cub->d_co, god);
	else if (cub->map[ray->pos_a_y][ray->pos_a_x] == '-')
		god_color(cub->d_oc, god);
	else
		god_color(cub->e_tex, god);
}
