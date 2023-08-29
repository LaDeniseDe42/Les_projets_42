/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:31:48 by akastler          #+#    #+#             */
/*   Updated: 2023/08/14 09:06:24 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	str_start_with_str(char *str, char *starting)
{
	int	i;

	i = 0;
	if (ft_strlen(str) < ft_strlen(starting))
		return (0);
	while (starting[i])
	{
		if (starting[i] != str[i])
		{
			if (i < (int)ft_strlen(starting))
				return (0);
		}
		i++;
	}
	return (1);
}

char	*add_char(char add_this, char *to_this)
{
	char	*added;
	int		i;

	i = 0;
	added = ft_calloc(ft_strlen(to_this) + 2, sizeof(char));
	while (to_this[i])
	{
		added[i] = to_this[i];
		i++;
	}
	added[i] = add_this;
	free(to_this);
	return (added);
}

int	line_sp(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_ints(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9' || j >= 3)
				return (0);
			j++;
		}
		i++;
	}
	if (i > 3)
	{
		return (0);
	}
	return (1);
}
