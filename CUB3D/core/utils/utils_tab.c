/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:07:32 by akastler          #+#    #+#             */
/*   Updated: 2023/08/09 15:34:15 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

void	free_tab(char **paths)
{
	int	line;

	line = 0;
	while (paths[line])
	{
		if (paths[line])
			free(paths[line]);
		line++;
	}
	free(paths);
}

char	**ft_copy_tb(char **tb)
{
	char	**cpy_tb;
	int		nb_line;
	int		i;

	nb_line = 0;
	i = 0;
	cpy_tb = NULL;
	while (tb[nb_line])
		nb_line++;
	cpy_tb = ft_calloc(nb_line + 1, sizeof(char *));
	nb_line = 0;
	while (tb[nb_line])
	{
		i = 0;
		cpy_tb[nb_line] = ft_calloc(ft_strlen(tb[nb_line]) + 1, sizeof(char));
		while (tb[nb_line][i])
		{
			cpy_tb[nb_line][i] = tb[nb_line][i];
			i++;
		}
		nb_line++;
	}
	return (cpy_tb);
}
