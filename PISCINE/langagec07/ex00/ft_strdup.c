/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:39:51 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/30 18:50:47 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int	j;
	char * dest;

	j = 0;
	if (!(dest =(char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int main()
{
	char *src = "bouge ton cul";
	char *test_ma_fonction = NULL;
	char *test_la_vrai_fonction = NULL;

	test_ma_fonction = ft_strdup(src);
	test_la_vrai_fonction = strdup(src);
	printf("%s\n:%s\n:", test_ma_fonction, test_la_vrai_fonction);

	return (0);
}
