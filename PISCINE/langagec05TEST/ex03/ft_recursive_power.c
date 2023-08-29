/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:30:57 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/26 18:00:46 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power);

int	main()
{
	printf("%d", ft_recursive_power(2, 8));
}


int	ft_recursive_power(int nb, int power)
{
	int resultat;

	resultat = 1;
	if (power <= 1)
		return (1);
	if (power <= 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}
