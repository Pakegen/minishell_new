/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_terminal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:09:19 by axbaudri          #+#    #+#             */
/*   Updated: 2025/02/07 12:48:34 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*init_shell(char **envp)
{
	t_shell	*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->path = find_path_line(envp);
	shell->old_pwd = get_pwd(envp);
	shell->pwd = get_pwd(envp);
	shell->splitted_path = ft_split(shell->path, ':');
	shell->env = get_lines(envp);
	shell->export = get_lines(envp);
	sort_strings(shell->export, count_strings(envp));
	shell->var_names = get_var_names(envp);
	return (shell);
}

t_prompt	*parse_prompt(const char *buffer)
{
	t_prompt	*prompt;

	prompt = (t_prompt *)malloc(sizeof(t_prompt));
	if (!prompt)
		return (NULL);
	prompt->cmd_line = ft_strdup(buffer);
	prompt->strs = ft_split(buffer, ' ');
	return (prompt);
}

char	*find_path_line(char **envp)
{
	int		i;
	char	*path_line;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path_line = ft_strdup(envp[i] + 5);
	return (path_line);
}

char	*get_pwd(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (ft_strncmp(envp[i], "PWD=", 4) != 0)
		i++;
	path = ft_strdup(envp[i] + 4);
	return (path);
}
