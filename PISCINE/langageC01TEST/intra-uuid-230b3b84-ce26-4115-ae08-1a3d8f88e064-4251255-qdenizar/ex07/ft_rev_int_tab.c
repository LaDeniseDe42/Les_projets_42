/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:03:36 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/19 14:25:00 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	change_the_order;

	i = 0;
	while (i < (size / 2))
	{
		change_the_order = tab[i];
		tab[i] = tab[size -1 - i];
		tab[size -1 - i] = change_the_order;
		i++;
	}
}
