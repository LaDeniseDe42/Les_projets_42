/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 08:26:50 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/17 10:52:09 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_ultimate_ft(int  *********nbr);

int main()
{
	
	int p;
	int *p8;
	int **p7;
	int ***p6;
	int ****p5;
	int *****p4;
	int ******p3;
	int *******p2;
	int ********p1;
	int *********nbr;

	p = 42;

	p8 = &p;
	p7 = &p8;
	p6 = &p7;
	p5 = &p6;
	p4 = &p5;
	p3 = &p4;
	p2 = &p3;
	p1 = &p2;
	nbr = &p1;

	ft_ultimate_ft(nbr);
	printf("%d", p);
	return (0);
}

void	ft_ultimate_ft(int	*********nbr)
{
	*********nbr = 42 ;
}


