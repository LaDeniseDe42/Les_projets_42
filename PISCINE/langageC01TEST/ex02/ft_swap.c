/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:20:45 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/17 13:20:26 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void 	ft_swap(int *a, int *b);

int main()
{
	int x;
	int y;
	int *ptr_x;
	int *ptr_y;

	ptr_x = &x;
	ptr_y = &y;
	x = 5;
	y = 10;
	
	ft_swap(ptr_x, ptr_y);
	printf("%d\n", x);
	printf("%d", y);
	return (0);
}


void	ft_swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
	
}
