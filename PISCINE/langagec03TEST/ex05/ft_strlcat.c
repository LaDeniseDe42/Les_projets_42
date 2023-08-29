/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:20:14 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/23 16:43:10 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h> 
#include <stdio.h>



unsigned int	ft_strlcat(char	*dest, char *src, unsigned int size);

int	main()
{
	char	dest[100] = " l'arbre de la foret";
	char	src[100] = " les arbres poussent dans la foret";
	unsigned int size = 35;
	printf("%d", strlcat(dest, src, size);



}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{



}



