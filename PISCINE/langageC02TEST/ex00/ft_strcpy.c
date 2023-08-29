/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:18:13 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/22 12:57:37 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

char	*ft_str(char *dest, char *src);

int main()
{
	char dest[] = "Yo c'est moi je suis le ";
	char src[] = "testeeeeeeeeeeeeeeeeeeeeeeeee!!";
	 	

	ft_str(dest, src);
		
	printf("%s", dest);
}

char	*ft_str(char *dest, char *src)
{
int j;

j = 0;
while (src[j])
{

	dest[j] = src[j];
	j++;
	
	}
dest[j] = '\0';
return (dest);
}
