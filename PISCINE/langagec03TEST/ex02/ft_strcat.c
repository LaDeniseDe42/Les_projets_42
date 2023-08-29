/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:27:27 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/21 21:13:13 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <string.h>
#include <stdio.h>


char	*ft_strcat(char *dest, char *src);



int main()
{
	char	dest[100] = "Emma a une";
	char	src[100] = "moustache";
	printf("%s", ft_strcat(dest, src));
	
}


char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;
		
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}	
	dest[i] = '\0';
		return (dest);
}
