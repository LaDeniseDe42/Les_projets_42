/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:11:01 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/31 11:38:58 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void    write_message(char *message)
{
	int i = 0;

	while(message[i])
		write(2, &message[i++], 1);
}

int cd(char **argv, int i, int j)
{
    if (j != 2)
    {
        write_message("error: cd: bad arguments\n");
        return(1);
    }
    if (chdir(argv[i + 1]) == -1)
    {
        write_message("error: cd: cannot change directory to ");
        write_message(argv[i + 1]);
        write_message("\n");
        return(1);
    }
    return(0);
}

int exec(char **argv, int i, int j, char **env)
{
    if (strcmp(argv[i], ";") == 0)
        return (0);
    int status = 0;
    int pid;
    int pipes[2];
    int pipe_or_not = argv[i + j] && strcmp(argv[i + j], "|") == 0;

    if (pipe_or_not == 1 && pipe(pipes) == -1)
    {
        write_message("error: fatal\n");
        return(1);
    }
    pid = fork();
    if (pid == 0)
    {
        argv[i + j] = NULL;
        if (pipe_or_not == 1 &&(dup2(pipes[1], 1) == -1 || close(pipes[0]) == -1 || close(pipes[1]) == -1))
        {
            write_message("error: fatal\n");
            return(1);
        }
        execve(argv[i], argv + i, env);
        write_message("error: cannot execute ");
        write_message(argv[i]);
        write_message("\n");
        return(1);
    }
    waitpid(pid, &status, 0);
    if (pipe_or_not == 1 && (dup2(pipes[0], 0) == -1 || close(pipes[0]) == -1 || close(pipes[1]) == -1))
    {
        write_message("error: fatal\n");
        return(1);
    }
    return(WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char **argv, char **env)
{
    int j = 0;
    int i = 0;
    int status = 0;
 
    (void)argc;
    while(argv[i] && argv[++i])
    {
        i+=j;
        j=0;
        if (argv[i] == NULL)
            break ;
        while(argv[i + j] && strcmp(argv[i + j], ";") && strcmp(argv[i + j], "|"))
            j++;
        if (strcmp(argv[i], "cd") == 0)
            status = cd(argv, i, j);
        else
            status = exec(argv, i, j, env);
        if (argv[i + j] == NULL || argv[i] == NULL)
            break;
    }
    return(status);
}