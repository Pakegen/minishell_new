/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:44:05 by qacjl             #+#    #+#             */
/*   Updated: 2025/02/13 16:16:26 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/history.h>

void	display_history()
{
	HIST_ENTRY	**history_list;
	int			i;

	history_list = history_get_history_state()->entries;
	i = 0;
	if (history_list)
	{
		while (history_list[i])
		{
			ft_printf("%d  %s\n", i + 1, history_list[i]->line); //history ne commence pas a 0
			i++;
		}
	}
}

void	verif_history(char *input)
{
	if (strcmp(input, "history") == 0)
	{
		display_history();
	}
	else
	{
		ft_printf("Exécution de la commande : %s\n", input);
	}
}

//ajout dans le main apres if (!input)
int main(void)
{
	char	*input;

	read_history("history.txt");
	using_history();
	if (*input)
	{
		add_history(input);
		verif_history(input);
	}
	write_history("history.txt");
	return (0);
}



#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define MAX_ARGS 64

void execute_command(char *cmd, int in_fd, int out_fd)
{
    pid_t pid;
    char *args[MAX_ARGS];
    int i;
    char *token;
    i = 0;
    token = strtok(cmd, " \t\n");
    while (token != NULL && i < (MAX_ARGS - 1)) { args[i] = token; i = i + 1; token = strtok(NULL, " \t\n"); }
    args[i] = NULL;
    pid = fork();
    if (pid == 0)
    {
        if (in_fd != STDIN_FILENO) { dup2(in_fd, STDIN_FILENO); close(in_fd); }
        if (out_fd != STDOUT_FILENO) { dup2(out_fd, STDOUT_FILENO); close(out_fd); }
        execvp(args[0], args); perror("execvp"); exit(EXIT_FAILURE);
    }
    else if (pid < 0) { perror("fork"); exit(EXIT_FAILURE); }
}

void execute_pipes(char *input)
{
    int num_cmds, i, fd[2], in_fd, out_fd;
    char *cmds[256], *token;
    num_cmds = 0; in_fd = STDIN_FILENO;
    token = strtok(input, "|");
    while (token != NULL) { cmds[num_cmds] = token; num_cmds = num_cmds + 1; token = strtok(NULL, "|"); }
    i = 0;
    while (i < num_cmds)
    {
        out_fd = STDOUT_FILENO;
        if ((i + 1) < num_cmds)
        {
            if (pipe(fd) == -1) { perror("pipe"); exit(EXIT_FAILURE); }
            out_fd = fd[1];
        }
        execute_command(cmds[i], in_fd, out_fd);
        if (out_fd != STDOUT_FILENO) close(out_fd);
        if ((i + 1) < num_cmds) in_fd = fd[0];
        i = i + 1;
    }
    i = 0; while (i < num_cmds) { wait(NULL); i = i + 1; }
}
