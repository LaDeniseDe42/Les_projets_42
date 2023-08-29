/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:08:12 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/04 12:43:44 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


char	*rot_13(char *rot)
{
	int i;

	i = 0;
	while (rot[i])
	{
		if (rot[i] >= 'a' && rot[i] <= 'n')
	  		rot[i] = rot[i] + 13;
		else if (rot[i] > 'n' && rot[i] <= 'z')
			rot[i] = rot[i] - 13;
		else if (rot[i] >= 'A' && rot[i] <= 'N')
			rot[i] = rot[i] + 13;
		else if (rot[i] > 'N' && rot[i] <= 'Z')
			rot[i] = rot[i] -13;
		i++;
	}

	return (rot);
}

int	main()
{
	char rot[100] = "Ali a b c d e f g h i j z w q";
	printf("%s", rot_13(rot));
}
