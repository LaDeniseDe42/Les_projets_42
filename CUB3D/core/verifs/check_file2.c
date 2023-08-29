/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:15:26 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/14 09:01:09 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	fill_struct2(char *str, t_cub *cub)
{
	if (str_start_with_str(str, "EA ") == 1)
	{
		if (cub->ea_texture_path == NULL)
			cub->ea_texture_path = subjoin(str + 3);
		else
			return (free_struct(cub) - 1);
	}
	else if (str_start_with_str(str, "F ") == 1)
	{
		if (cub->floor_color == NULL)
			cub->floor_color = subjoin(str + 2);
		else
			return (free_struct(cub) - 1);
	}
	else if (str_start_with_str(str, "C ") == 1)
	{
		if (cub->ceilling_color == NULL)
			cub->ceilling_color = subjoin(str + 2);
		else
			return (free_struct(cub) - 1);
	}
	else
		return (1);
	return (0);
}

int	fill_struct(char *str, t_cub *cub)
{
	if (str_start_with_str(str, "NO ") == 1)
	{
		if (cub->no_texture_path == NULL)
			cub->no_texture_path = subjoin(str + 3);
		else
			return (free_struct(cub) - 1);
	}
	else if (str_start_with_str(str, "SO ") == 1)
	{
		if (cub->so_texture_path == NULL)
			cub->so_texture_path = subjoin(str + 3);
		else
			return (free_struct(cub) - 1);
	}
	else if (str_start_with_str(str, "WE ") == 1)
	{
		if (cub->we_texture_path == NULL)
			cub->we_texture_path = subjoin(str + 3);
		else
			return (free_struct(cub) - 1);
	}
	else
		return (fill_struct2(str, cub));
	return (0);
}

char	*subjoin(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
	{
		i++;
	}
	return (ft_strjoin(str + i, ""));
}

char	**fill_map(t_cub *cub, int j)
{
	char	**buf;
	int		i;

	buf = ft_copy_tb(cub->complete_read + j);
	i = 0;
	while (buf[i])
	{
		if (line_sp(buf[i]) == 1)
		{
			free_tab(buf);
			return (NULL);
		}
		i++;
	}
	return (buf);
}

int	find_first_chara(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	return (i);
}
