/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:16:49 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/09 14:54:21 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	calcul_len_max(t_cub *cub)
{
	t_index	i;

	init_index(&i);
	while (cub->map[i.i])
	{
		if ((int)ft_strlen(cub->map[i.i]) > i.j)
			i.j = (int)ft_strlen(cub->map[i.i]);
		i.i++;
	}
	cub->largeur = i.j;
	cub->hauteur = i.i;
}

void	set_lines(t_cub *cub)
{
	t_index	i;

	init_index(&i);
	while (cub->map[i.i])
	{
		if ((int)ft_strlen(cub->map[i.i]) < cub->largeur)
		{
			while ((int)ft_strlen(cub->map[i.i]) < cub->largeur)
				cub->map[i.i] = add_char(' ', cub->map[i.i]);
		}
		i.i++;
	}
}
