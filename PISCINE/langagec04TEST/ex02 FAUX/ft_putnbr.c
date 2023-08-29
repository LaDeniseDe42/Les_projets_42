/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:10:56 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/24 19:07:18 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_putnbr(int nb);


int	main()
{
	int nb = -2183648;
	ft_putnbr(nb);

}


void	ft_putnbr(int nb)
{
	int	i;
	char resultat;

	i = 0;
	if (nb == -2147483648)
	{
		write (1, "-", 1);
		write (1, "2", 1);
		write (1, "147483364", 8);
		nb = 8;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1); // nb multiplier par -1 permet de passer en possitif.
	}
	if (nb > 9) // condition pour quitter la recursivite
	{
		ft_putnbr(nb / 10); // j'utilise la recursivite pour que mon nombre se transforme en chiffre
	}
	resultat = (nb % 10) +'0'; /* le modulo va me recuperer chaque chiffre composant mom nombre, le +0 convertis en ascii*/
	 write (1, &resultat, 1); // va afficher chaque chiffre un par un(enregistre dans le stack)

		
}


