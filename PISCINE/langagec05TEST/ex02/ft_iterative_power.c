/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:31:08 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/28 20:36:27 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power);

int	main()
{
printf("%d", ft_iterative_power(8, 10));

}


int	ft_iterative_power(int nb, int power)
{
	int resultat;

	resultat = 1;
	if (nb == 0)
		return (0);
	if (nb < 0)
		return (0);
	while (power > 0) //permet de calculer un nb de fois suffisant
	{
		resultat = resultat * nb;
		power--;
	}
	return (resultat);
}

