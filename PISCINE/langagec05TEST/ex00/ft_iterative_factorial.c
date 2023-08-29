/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:54:33 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/26 11:57:13 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb);

int main()
{
printf("%d", ft_iterative_factorial(0));
}


int	ft_iterative_factorial(int nb)
{
	int resultat;
	int i;

	resultat = 1; // car 0!=1
	i = resultat + 1;
	if (nb < 0)
		return (0);
	if ( nb == 1 || nb == 0)
		return (resultat);
	
	while (i <= nb)
	{
		resultat = resultat * i;
		i++;
	}
	return (resultat);
}
