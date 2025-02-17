/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:43:52 by axbaudri          #+#    #+#             */
/*   Updated: 2025/02/17 03:41:10 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_echo(t_prompt *prompt)
{
	char	**strs;

	prompt->echo = exec_echo(prompt->cmd_line, prompt->strs);
	{
		strs = parse_echo(prompt);
		ft_printf("join strings = %s\n", join_strings(strs));
		ft_printf("%s", prompt->echo);
	}
	free(prompt->echo);
}

void	execute_command(t_shell *shell, t_prompt *prompt)
{
	if (!ft_strlen(prompt->cmd_line))
		ft_printf("");
	else if (ft_strcmp(prompt->strs[0], "echo") == 0
		&& ft_strcmp(prompt->strs[1], "-n") == 0)
		display_echo(prompt);
	else if (ft_strcmp(prompt->strs[0], "export") == 0
		&& count_words(prompt->cmd_line) == 1)
		write_env(shell->export, prompt);
	else if (ft_strcmp(prompt->strs[0], "env") == 0
		&& count_words(prompt->cmd_line) == 1)
		write_env(shell->env, prompt);
	else if (ft_strcmp(prompt->strs[0], "cd") == 0
		&& count_strings(prompt->strs) == 2)
		exec_cd(shell, prompt);
	else if (ft_strcmp(prompt->strs[0], "pwd") == 0
		&& count_words(prompt->cmd_line) == 1)
		ft_printf("%s\n", shell->pwd);
	else if (ft_strcmp(prompt->strs[0], "unset") == 0
		&& count_words(prompt->cmd_line) > 1)
		exec_unset(shell, prompt);
	else if (ft_strcmp(prompt->strs[0], "exit") == 0
		&& count_words(prompt->cmd_line) == 1)
		exit(1);
	else
		ft_printf("command not found: %s\n", prompt->strs[0]);
}

int	main(int argc, char **argv, char **env)
{
	char		*line;
	t_pipeline	*pipeline;

	(void)argc;
	(void)argv;
	setup_signal();
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (line[0] != '\0')
			add_history(line);
		pipeline = parse_input(line);
		if (pipeline)
		{
			execute_pipeline(pipeline, env);
			free_pipeline(pipeline);
		}
		free(line);
	}
	return (0);
}


/*int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	int i = 0;

	(void)argv;
	if (argc == 1)
	{
		shell = init_shell(envp);
		while (shell->var_names[i])
			ft_printf("%s\n", shell->var_names[i++]);
		free_terminal(shell);
	}
	return (0);
}*/
