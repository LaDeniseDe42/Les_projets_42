/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:42:03 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/31 15:08:14 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>


unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
unsigned int j;

j = 0;
while (src[j] && j < size)
{

	dest[j] = src[j];
	j++;	
}
if (size == 0)
	return (j);
while (j <= size)
{
	dest[j] = '\0';
	j++;
	if (j == size)
		return (j);
}
return (j);
}

int main()
{
	char dest[] = "Yo c'est moi je suis le ";
	char src[] = "testeeeeeeeeeeeeeeeeeeeeeeeee!!";
	unsigned int size = 10;

//	ft_strlcpy(dest, src, size);
//	strlcpy(dest, src, size);
	printf("%d", ft_strlcpy(dest, src, size));
}

