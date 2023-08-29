/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:17:13 by qdenizar          #+#    #+#             */
/*   Updated: 2022/11/09 14:49:59 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "string.h"
//#include "ft_strlcpy.c"
//#include "ft_strlen.c"

/*static size_t	ft_nbc(char const *s, char c)
{
	size_t	nbc;
	size_t	i;
	size_t	len;

	nbc = 0;
	i = 0;
	len = ft_strlen(s);
	while (s[i] != '\0')
	{
		if (s[i] && s[i] == c && s[i + 1] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			nbc++;
		}
		else if (s[i] && s[i] == c)
			nbc++;
		i++;
	}
	if (s[i] == c)
		nbc = nbc -1;
	if (s[len -1] == c)
		return (nbc);
	return (nbc + 1);
	i = 0;
	return (nbc);
}*/

static size_t	ft_nbc(char const *s, char c)
{
	int	nbc;
	int	i;
	int	j;

	i = 0;
	j = 0;
	nbc = 0;
	while (s[j])
	{
		if (s[j] != c && i == 0)
		{
			i = 1;
			nbc++;
		}
		else if (s[j] == c)
			i = 0;
		j++;
	}
	return (nbc);
}

static char	*ft_workforme(char const *s, char c, int i)
{
	int		j;
	char	*tab;
	int		k;

	j = i;
	k = 0;
	while (s[j] && s[j] != c)
		j++;
	tab = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!tab)
		return (0);
	//printf("strmalloc: %lu\n", (sizeof(char) * (j - i + 1)));
	while (s[i] && i < j)
		tab[k++] = s[i++];
	tab[k] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		nbc;
	char		**tab;
	size_t		k;

	if (s == NULL)
		return (NULL);
	i = 0;
	nbc = ft_nbc(s, c);
	k = 0;
	tab = (char **)malloc(sizeof(char *) * ((nbc) + 1));
	if (!tab)
		return (0);
	//printf("tabmalloc: %lu\n", (((nbc))));
	tab[0] = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (k < nbc)
			tab[k] = ft_workforme(s, c, i);
		//printf("tab = %s\n", tab[k]);
		while (s[i] && s[i] != c)
			i++;
		k++;
	}
	return (tab);
}

/*int	main(void)
{
	char	**ptr;
	char 	*string = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	int		i;

	i = -1;
	ptr = ft_split(string, ' ');
	while (ptr[++i])
		printf("tab[%d] = %s\n", i, ptr[i]);
}*/

/*
int	ft_nbc(char const *s, char c)
{
	int		nbc;
	int		i;
	size_t	len;

	nbc = 0;
	i = 0;
	len = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] == c)
		{
			while (s[i] == c)
				i++;
			nbc++;
		}
		if (s[i] == c)
			nbc++;
		i++;
	}
	i = 0;
	if (s[i] == c)
		nbc = nbc -1;
	if (s[len -1] == c)
		return (nbc);
	return (nbc + 1);
}

static char	*ft_workforme(char const *s, char c, int i)
{
	int		j;
	char	*tab;
	int		k;

	j = i;
	k = 0;
	while (s[j] && s[j] != c)
		j++;
	tab = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!tab)
		return (0);
	printf("strmalloc: %lu\n", (sizeof(char) * (j - i + 1)));
	while (s[i] && i < j)
		tab[k++] = s[i++];
	tab[k] = '\0';
	//ft_strlcpy(tab, (s + i), (j - i +1));
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nbc;
	char	**tab;
	int		k;

	i = 0;
	nbc = ft_nbc(s, c);
	k = 0;
	tab = (char **)malloc((sizeof(char *) * (nbc)) + 1);
	tab[0] = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		tab[k] = ft_workforme(s, c, i);
		while (s[i] != c)
			i++;
		k++;
	}
	tab[k] = 0;
	return (tab);
}*/
