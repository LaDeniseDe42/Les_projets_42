/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microtest2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:03:34 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/30 14:19:22 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


void    write_msg(char *str)
{
    int i = 0;
    
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
}

int cd(char **argv, int i, int j)
{
    if (j != 2)
    {
        write_msg("error: cd: bad arguments\n");
        return (1);
    }
    if (chdir(argv[i + 1]) == -1)
    {
        write_msg("error: cd: cannot change directory to ");
        write_msg(argv[i +1]);
        write_msg("\n");
        return (1);
    }
    return (0);
}

int main(int argc, char **argv, char **env)
{
    int i = 0;
    int j = 0;
    int status = 0;

    (void)argc;
    while (argv[i] && argv[++i])
    {
        i+=j;
        j = 0;
        if (argv[i] == NULL)
            break;
        while (argv[i] && strcmp(argv[i +j], "|" && strcmp(argv[i + j], ";")))
            j++;
        if (strcmp(argv[i], "cd") == 0)
            status = cd(argv, i, j);
        else
            status = exec_this(argv, i, j, env);
        if (argv[i] == NULL || argv[i +j] == NULL)
            break;
    }
    return (status);
}