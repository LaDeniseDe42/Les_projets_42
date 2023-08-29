/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:41:25 by akastler          #+#    #+#             */
/*   Updated: 2023/08/14 09:01:09 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_colors_in_tab(t_cub *cub)
{
	char	**tab_int;

	tab_int = ft_split(cub->ceilling_color, ',');
	if (check_ints(tab_int) == 0)
		put_colors_in_tab_error(cub);
	cub->ceilling[0] = ft_atoi(tab_int[0]);
	cub->ceilling[1] = ft_atoi(tab_int[1]);
	cub->ceilling[2] = ft_atoi(tab_int[2]);
	free_tab(tab_int);
	tab_int = ft_split(cub->floor_color, ',');
	if (check_ints(tab_int) == 0)
		put_colors_in_tab_error(cub);
	cub->floor[0] = ft_atoi(tab_int[0]);
	cub->floor[1] = ft_atoi(tab_int[1]);
	cub->floor[2] = ft_atoi(tab_int[2]);
	free_tab(tab_int);
	if (!(cub->ceilling[0] >= 0 && cub->ceilling[0] <= 255
			&& cub->ceilling[1] >= 0 && cub->ceilling[1] <= 255
			&& cub->ceilling[2] >= 0 && cub->ceilling[2] <= 255
			&& cub->floor[0] >= 0 && cub->floor[0] <= 255 && cub->floor[1] >= 0
			&& cub->floor[1] <= 255 && cub->floor[2] >= 0
			&& cub->floor[2] <= 255))
		put_colors_in_tab_error(cub);
}

void	second_while_parse_color(t_cub *cub)
{
	t_index	i;

	init_index(&i);
	while (cub->floor_color[i.j])
	{
		if (cub->floor_color[i.j] == ','
			|| is_space(cub->floor_color[i.j]) == 1)
		{
			if (!(is_space(cub->floor_color[i.j]) == 0
					|| (cub->floor_color[i.j + 1]
						&& cub->floor_color[i.j + 1] >= '0'
						&& cub->floor_color[i.j + 1] <= '9')))
			{
				free_struct(cub);
				exit(printf("cub3D: Error: floor color invalid") - 32);
			}
		}
		i.j++;
	}
}

void	parse_colors(t_cub *cub)
{
	t_index	i;

	init_index(&i);
	if (cub->ceilling_color == NULL || cub->floor_color == NULL)
		exit_flood_fill_error("cub3D: Error: No colors", cub);
	while (cub->ceilling_color[i.i])
	{
		if (cub->ceilling_color[i.i] == ','
			|| is_space(cub->ceilling_color[i.i]) == 1)
		{
			if (!(is_space(cub->ceilling_color[i.i]) == 0
					|| (cub->ceilling_color[i.i + 1]
						&& cub->ceilling_color[i.i + 1] >= '0'
						&& cub->ceilling_color[i.i + 1] <= '9')))
			{
				free_struct(cub);
				exit(printf("cub3D: Error: ceilling color invalid") - 35);
			}
		}
		i.i++;
	}
	second_while_parse_color(cub);
	put_colors_in_tab(cub);
}

void	parse_read(t_cub *cub)
{
	t_index	i;

	init_index(&i);
	while (cub->complete_read[i.i])
	{
		while (cub->complete_read[i.i] && line_sp(cub->complete_read[i.i]) == 1)
			i.i++;
		i.k = fill_struct(&cub->complete_read[i.i][
				find_first_chara(cub->complete_read[i.i])], cub);
		if (i.k == 1)
		{
			i.j = i.i;
			while (cub->complete_read[i.i])
				i.i++;
			cub->hauteur = i.i - i.j;
			cub->map = fill_map(cub, i.j);
			break ;
		}
		else if (i.k == -1)
			break ;
		i.i++;
	}
	if (flood_fill(cub->map, cub) == -1)
		exit_flood_fill_error("Error: Problem with the map", cub);
	parse_colors(cub);
}

int	check_file(char *file, t_cub *cub)
{
	int	lof;

	lof = ft_strlen(file);
	if (lof < 5)
		return (printf("cub3D: Error: Invalid name of file\n"));
	(void)cub;
	if (file[lof - 1] == 'b' && file[lof - 2] == 'u'
		&& file[lof - 3] == 'c' && file[lof - 4] == '.')
	{
		cub->fd_file = open(file, O_RDONLY);
		if (cub->fd_file == -1)
			return (printf("cub3D: Error: Problem with file: %s\n", file));
	}
	else
		return (printf("cub3D: Error: Invalid extension of file\n"));
	return (0);
}
