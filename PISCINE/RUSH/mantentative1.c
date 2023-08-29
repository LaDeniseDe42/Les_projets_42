/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mantentative1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:45:12 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/16 13:15:04 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>


int rush(int x, int y);


int main()
{
	rush(5, 5);
	return (0);
}


int rush(int x, int y)
{
	int i = 0;
	while ( i < x)
	{
		if(i == 1)
			write(1, "o", 1);
		while(i > 1 && i < x)
		{
			i++;
			write(1, "-", 1);
		}
		if(i == x)
			write(1, "o", 1);
	
	}
	while ( i < y)
	{
		if(i == 1)
			write(1, "|", 1);
		while(i < y)
		{
			write(1, " ", 1);
		}
		
	}
	return (0);
}


