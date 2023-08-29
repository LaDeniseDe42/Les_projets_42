/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ul_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:12:33 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/04 15:02:30 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ul_str(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
int main(int argc, char **argv)
{
	int i;

	i = 0;
	(void) argc;
	ul_str(*argv);
	return (0);
}
