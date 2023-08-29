/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:21:52 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/16 17:32:45 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_ft(int *nbr);


int main()
{

	int nbr;
	int *ptr;

	nbr = 5;
	ptr = &nbr;
	ft_ft(ptr);
	printf("%d", nbr);
	return (0);
}

void	ft_ft(int *nbr)
{
	*nbr = 42;

}





