/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:43:22 by qacjl             #+#    #+#             */
/*   Updated: 2025/02/17 04:33:13 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_token_count(char **raw_cmds)
{
	int	count;

	count = 0;
	while (raw_cmds[count])
		count++;
	return (count);
}

static void	fill_pipeline(t_pipeline *pipeline, char **raw_cmds, int count)
{
	int			i;
	t_command	*cmd;

	i = 0;
	while (i < count)
	{
		cmd = parse_command(raw_cmds[i]);
		pipeline->commands[i] = *cmd;
		free(cmd);
		i++;
	}
}

static t_pipeline	*build_pipeline(char **raw_cmds)
{
	t_pipeline	*pipeline;
	int			count;

	count = get_token_count(raw_cmds);
	pipeline = malloc(sizeof(t_pipeline));
	if (pipeline == NULL)
		return (NULL);
	pipeline->count = count;
	pipeline->commands = malloc(sizeof(t_command) * count);
	if (pipeline->commands == NULL)
	{
		free(pipeline);
		return (NULL);
	}
	fill_pipeline(pipeline, raw_cmds, count);
	return (pipeline);
}

t_pipeline	*parse_input(const char *line)
{
	char		**raw_cmds;
	t_pipeline	*pipeline;

	raw_cmds = ft_split(line, '|');
	pipeline = build_pipeline(raw_cmds);
	free(raw_cmds);
	return (pipeline);
}

void	free_pipeline(t_pipeline *pipeline)
{
	int	i;
	int	j;

	if (pipeline == NULL)
		return ;
	i = 0;
	while (i < pipeline->count)
	{
		if (pipeline->commands[i].args)
		{
			j = 0;
			while (pipeline->commands[i].args[j])
			{
				free(pipeline->commands[i].args[j]);
				j++;
			}
			free(pipeline->commands[i].args);
		}
		if (pipeline->commands[i].heredoc_delim)
			free(pipeline->commands[i].heredoc_delim);
		i++;
	}
	free(pipeline->commands);
	free(pipeline);
}

