/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:15:18 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/10 12:55:50 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	fill(char **tab, t_pos cur, char to_fill)
{
	if (cur.y < 0 || cur.x < 0 || !tab
		|| cur.y >= count_tab(tab) || (tab[cur.y]
			&& cur.x > (int)ft_strlen(tab[cur.y])))
		return ;
	if ((tab[cur.y][cur.x] == '0' || tab[cur.y][cur.x] == 'N'
		|| tab[cur.y][cur.x] == 'W' || tab[cur.y][cur.x] == 'S'
		|| tab[cur.y][cur.x] == 'E' || tab[cur.y][cur.x] == ' '
		|| tab[cur.y][cur.x] == 'C' || tab[cur.y][cur.x] == 'O'
		|| tab[cur.y][cur.x] == 'Q'))
	{
		tab[cur.y][cur.x] = 'F';
		fill(tab, (t_pos){cur.y, cur.x + 1}, to_fill);
		fill(tab, (t_pos){cur.y, cur.x - 1}, to_fill);
		fill(tab, (t_pos){cur.y + 1, cur.x}, to_fill);
		fill(tab, (t_pos){cur.y - 1, cur.x}, to_fill);
	}
}

t_pos	find_pos(char **tab, char c)
{
	t_pos	pos;

	init_position(&pos);
	while (tab[pos.y])
	{
		while (tab[pos.y][pos.x])
		{
			if (tab[pos.y][pos.x] == c)
				return (pos);
			pos.x++;
		}
		if (tab[pos.y][pos.x] == c)
			return (pos);
		pos.x = 0;
		pos.y++;
	}
	return ((t_pos){-1, -1});
}

t_pos	find_pos_player(char **tab)
{
	t_pos	pos;

	init_position(&pos);
	pos = find_pos(tab, 'N');
	if (pos.x == -1)
	{
		pos = find_pos(tab, 'W');
		if (pos.x == -1)
		{
			pos = find_pos(tab, 'S');
			if (pos.x == -1)
				pos = find_pos(tab, 'E');
		}
	}
	return (pos);
}

int	flood_fill(char **tab, t_cub *cub)
{
	char	**cpy_tab;
	t_pos	begin;
	t_index	i;

	close(cub->fd_file);
	if (tab == NULL)
		return (-1);
	init_index(&i);
	cub->pos = find_pos_player(tab);
	init_position(&begin);
	if (cub->pos.x == -1)
		exit_flood_fill_error("Error: Need a start point !", cub);
	cpy_tab = ft_copy_tb(tab);
	fill(cpy_tab, cub->pos, '0');
	begin = find_pos(cpy_tab, '0');
	while (begin.x != -1)
	{
		fill(cpy_tab, begin, '0');
		begin = find_pos(cpy_tab, '0');
	}
	i.i = verif_fill(tab, cpy_tab);
	free_tab(cpy_tab);
	if (i.i == -1)
		return (-1);
	return (1);
}
