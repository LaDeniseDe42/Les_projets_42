/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:57 by akastler          #+#    #+#             */
/*   Updated: 2023/08/14 09:23:51 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_space(char c)
{
	if (!c)
		return (0);
	if (c)
	{
		if ((c >= 9 && c <= 13) || c == 32)
			return (1);
	}
	return (0);
}

static void	end_of_read_file(t_cub *cub, t_read_f *r)
{
	free(r->str);
	cub->complete_read = ft_split(r->final, '\n');
	if (!cub->complete_read || count_tab(cub->complete_read) < 7)
		exit_flood_fill_error("cub3D: Error: Map is empty", cub);
	free(r->final);
}

void	read_file(t_cub *cub)
{
	t_read_f	r;

	r.str = get_next_line(cub->fd_file);
	r.final = NULL;
	while (r.str)
	{
		if (ft_strlen(r.str) == 1 && r.str[0] == '\n')
		{
			free(r.str);
			r.str = ft_strjoin(" \n", "");
		}
		if (r.final)
		{
			r.temp = r.final;
			r.final = ft_strjoin(r.final, r.str);
			free(r.temp);
		}
		else
			r.final = ft_strjoin("", r.str);
		free(r.str);
		r.str = get_next_line(cub->fd_file);
	}
	end_of_read_file(cub, &r);
}

static void	free_struct2(t_cub *cub)
{
	if (cub->d_o)
		mlx_delete_texture(cub->d_o);
	if (cub->n_tex)
		mlx_delete_texture(cub->n_tex);
	if (cub->s_tex)
		mlx_delete_texture(cub->s_tex);
	if (cub->w_tex)
		mlx_delete_texture(cub->w_tex);
	if (cub->e_tex)
		mlx_delete_texture(cub->e_tex);
}

int	free_struct(t_cub *cub)
{
	if (cub->ceilling_color)
		free(cub->ceilling_color);
	if (cub->floor_color)
		free(cub->floor_color);
	if (cub->ea_texture_path)
		free(cub->ea_texture_path);
	if (cub->no_texture_path)
		free(cub->no_texture_path);
	if (cub->so_texture_path)
		free(cub->so_texture_path);
	if (cub->we_texture_path)
		free(cub->we_texture_path);
	if (cub->complete_read)
		free_tab(cub->complete_read);
	if (cub->map)
		free_tab(cub->map);
	if (cub->d_c)
		mlx_delete_texture(cub->d_c);
	if (cub->d_co)
		mlx_delete_texture(cub->d_co);
	if (cub->d_oc)
		mlx_delete_texture(cub->d_oc);
	free_struct2(cub);
	init_cub(cub);
	return (0);
}
