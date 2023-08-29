/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:30:43 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/19 15:59:26 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


void	ft_sort_int_tab(int *tab, int size);


int main()
{
	int	tab[5] = {1, 45, -33, 0, 898};
	int size = 5;


	ft_sort_int_tab(tab, size);
	printf("%d %d %d %d %d", tab[0], tab[1], tab[2], tab[3], tab[4]);
	return (0);
}


void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int eureka;
	int	stock;

	i = 0;
	while(tab[i])
	{
		eureka = i +1;
		if (tab[i] > tab[eureka])
		{
			stock = tab[eureka];
			tab[eureka] = tab[i];
			tab[i] = stock;
			i = 0;
		}
			else 
				i++;
	}
}
