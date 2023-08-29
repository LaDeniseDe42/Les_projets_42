/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:37:02 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/22 12:45:10 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);


int main()
{
	char dest[] = " yo, c'est de nouveau moi aui vais te faire travailler le cerveau";
	char src[] = "je suis la phrase que tu veux voir s'afficher. bien joue!";
	unsigned int n = 0;

	ft_strncpy(dest, src, n);

	printf("%s\n", dest);
		


}



char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
