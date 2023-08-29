/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:06:44 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/22 14:30:28 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main()
{
	char dest[100] = "Le duc de bordeaux, ressemble a son pere";
	char src[100] = "son pere a son frere et son frere a mon c**";
	unsigned int nb = 40;

	printf("%s", strncat(dest, src, nb));
}



char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(dest[i])
		i++;
 	while(src[j] && nb > 0)
	{
		dest[i] = src[j];
		i++;
		j++;
		nb--;
	}
	dest[i] = '\0';
	return (dest);
}
