/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:07:10 by axbaudri          #+#    #+#             */
/*   Updated: 2025/02/06 14:30:58 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cd(t_shell *shell, t_prompt *prompt)
{
	char	buffer[PATH_MAX];

	if (chdir(prompt->strs[1]) != 0)
		ft_putstr_fd("cd command failed\n", 2);
	else
	{
		if (ft_strcmp(shell->old_pwd, shell->pwd) != 0)
		{
			free(shell->old_pwd);
			shell->old_pwd = ft_strdup(shell->pwd);
		}
		getcwd(buffer, PATH_MAX);
		free(shell->pwd);
		shell->pwd = ft_strdup(buffer);
	}
	update_paths(shell, shell->env);
	update_paths(shell, shell->export);
}

void	update_paths(t_shell *shell, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
		{
			free(envp[i]);
			envp[i] = ft_strjoin("OLDPWD=", shell->old_pwd);
		}
		else if (ft_strncmp(envp[i], "PWD=", 4) == 0)
		{
			free(envp[i]);
			envp[i] = ft_strjoin("PWD=", shell->pwd);
		}
		i++;
	}
}

/*void exec_cd(t_shell *shell, t_prompt *prompt)
{
	char buffer[PATH_MAX];

	if (chdir(prompt->strs[1]) == 0) {
		getcwd(buffer, sizeof(buffer));
		shell->pwd = ft_strdup(buffer);
	} else {
		perror("cd");
	}
}*/
