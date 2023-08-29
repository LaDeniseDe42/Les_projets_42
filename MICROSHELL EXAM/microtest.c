/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:59:45 by qdenizar          #+#    #+#             */
/*   Updated: 2023/08/25 10:57:36 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	write_msg(char *msg)
{
	int	i = 0;

	while (msg[i])
		write(2, &msg[i++], 1);
}

int	cd(char **argv, int i, int j)
{
	if (j != 2)
	{
		write_msg("error:  \n");
		return (1);
	}
	if (chdir(argv[i + 1]) == -1)
	{
		write_msg("error: cannot move to \n");
		write_msg(argv[i +1]);
		write_msg("\n");
		return (1);
	}
	return (0);
}

int	exec(char **argv, int i, int j, char **env)
{
	if (strcmp(argv[i + j], ";") == 0)
		return (0);

	int	pid;
	int	status = 0;
	int	pipes[2];
	int	pipe_or_not = argv[i +j] && strcmp(argv[i +j], "|") == 0;

	if (pipe_or_not == 1 && pipe(pipes) == -1)
	{
		write_msg("error: fatal\n");
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		argv[i + j] = NULL;
		if (pipe_or_not == 1 && (dup2(pipes[1], 1) == -1) || close(pipes[1]) == -1 || close(pipes[0]) == -1)
		{
			write_msg("error: \n");
			return (1);
		}
		execve(argv[i], argv + i, env);
		write_msg("error: cannot execute ");
		write_msg(argv[i]);
		write_msg("\n");
		return (1);
	}
	waitpid(pid, &status, 0);
	if (pipe_or_not == 1 && (dup2(pipes[0], 0) == -1) || close(pipes[0]) == -1 || close(pipes[1]) == -1)
	{
		write_msg("error: fatal\n");
		return (1);
	}
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **env)
{
	int i = 0;
	int j = 0;
	int status = 0;

	(void)argc;
	while (argv[i] && argv[++i])
	{
		i += j;
		j = 0;
		if (argv[i] == NULL)
			break ;
		while(argv[i + j] && strcmp(argv[i + j], ";") && strcmp(argv[i +j], "|"))
			j++;
		if (strcmp(argv[i], "cd") == 0)
			status = cd(argv, i, j);
		else
			status = exec(argv, i, j, env);
		if (argv[i] == NULL || argv[i +j] == NULL)
			return ;
	}
	return (status);
}
