/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:38:52 by axbaudri          #+#    #+#             */
/*   Updated: 2025/01/29 21:59:19 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	send_error(void)
{
	ft_printf("dup2");
	exit(-1);
}

/*void	exec_parent_process(t_shell *shell, char **envp)
{
	int	status;

	status = fork();
	if (status == 0)
	{

	}
}

void	pipex(t_shell *shell, char **envp)
{
	int	status;

	status = fork();
	if (status == -1)
		send_error();
	else if (status == 0)
	{

	}
	else
		exec_parent_process(shell, envp);
}*/
