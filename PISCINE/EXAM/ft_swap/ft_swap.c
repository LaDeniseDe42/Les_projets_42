/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:34:39 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/03 14:54:21 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int	*emma_le_rat, int *adrien_le_lemurien)
{
	int kevin_le_crabe;

	kevin_le_crabe = *emma_le_rat;
	*emma_le_rat = *adrien_le_lemurien;
	*adrien_le_lemurien = kevin_le_crabe;

}

int	main()
{
	int a;
	int b;
	int *c;
	int *d;
	long double  nathan_ne_sert_a_rien_mais_il_est_present = 10.3;

	a = 10;
	b = 20;
	c = &a;
	d = &b;
	ft_swap(c, d);
	printf("%d\n%d\n", a, b);
	printf("\n=======>%Lf<=========\n", nathan_ne_sert_a_rien_mais_il_est_present);
	return (0);
}
