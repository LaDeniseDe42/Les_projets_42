/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:58:54 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/10 10:43:25 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	count_char_verif(char **tab)
{
	t_index	i;

	init_index(&i);
	while (tab[i.i])
	{
		i.j = 0;
		while (tab[i.i][i.j])
		{
			if (tab[i.i][i.j] == 'N' || tab[i.i][i.j] == 'S'
			|| tab[i.i][i.j] == 'E' || tab[i.i][i.j] == 'W')
				i.k++;
			else
			{
				if (tab[i.i][i.j] != '0' && tab[i.i][i.j] != '1'
					&& tab[i.i][i.j] != ' ')
					i.l = -1;
			}
			i.j++;
		}
		i.i++;
	}
	if (i.k > 1 || i.l == -1)
		return (-1);
	return (0);
}

int	verif_fill2(char **tab)
{
	t_index	i;

	init_index(&i);
	while (tab[i.i])
	{
		i.j = 0;
		while (tab[i.i][i.j])
		{
			if (tab[i.i][i.j] == 'F')
			{
				if (i.i == 0 || i.i == count_tab(tab) - 1 || i.j == 0
					|| i.j == (int)ft_strlen(tab[i.i]) - 1
					|| i.j > (int)ft_strlen(tab[i.i - 1]) - 1
					|| i.j > (int)ft_strlen(tab[i.i + 1]) - 1
					|| tab[i.i][i.j - 1] == ' '
					|| tab[i.i][i.j + 1] == ' '
					|| tab[i.i - 1][i.j] == ' '
					|| tab[i.i + 1][i.j] == ' ')
					return (-1);
			}
			i.j++;
		}
		i.i++;
	}
	return (0);
}

int	verif_fill(char **origin, char **filled)
{
	t_index	i;

	init_index(&i);
	while (origin[i.i])
	{
		i.j = 0;
		while (origin[i.i][i.j])
		{
			if (origin[i.i][i.j] == ' ')
			{
				if (filled[i.i][i.j] != ' ')
					return (-1);
			}
			i.j++;
		}
		i.i++;
	}
	if (verif_fill2(filled) == 0 && count_char_verif(origin) == 0)
		return (0);
	return (-1);
}
