/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:54:43 by akastler          #+#    #+#             */
/*   Updated: 2023/07/26 16:40:30 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc > 1)
	{
		init_cub(&cub);
		if (argc == 2)
		{
			if (check_file(argv[1], &cub) == 0)
			{
				read_file(&cub);
				if (cub.fd_file >= 0)
				{
					parse_read(&cub);
					graphic(&cub);
				}
			}
			else
				return (1);
		}
		else
			return (printf("cub3D: Error: Too many args\n") - 28);
	}
	else
		return (printf("cub3D: Error: Too few args\n") - 27);
	return (0);
}
