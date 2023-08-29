/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:03:36 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/18 21:06:10 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);


int main()
{
	int tab[5] = {1, 2, 3, 4, 5};
	int combien;
	
	combien = 5;
		
	ft_rev_int_tab(tab, combien);
	printf("%d  %d %d %d %d ", tab[0], tab[1], tab[2], tab[3], tab[4]);
	return (0);

}

void ft_rev_int_tab(int *tab, int size)
{
	int i;
	int change_the_order;
	
	i = 0;
	
	while(i < (size / 2))
	{
		change_the_order = tab[i];
		tab[i] = tab[size -1 -i];
		tab[size -1 -i] = change_the_order;
		i++;

	}

}
