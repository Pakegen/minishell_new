/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:43:09 by axbaudri          #+#    #+#             */
/*   Updated: 2025/02/07 12:37:12 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*save_text(int fd)
{
	char	*temp;
	char	*content;

	temp = " ";
	while (temp)
	{
		temp = get_next_line(fd);
		if (temp)
			content = join_and_free(content, temp);
		free(temp);
	}
	return (content);
}

int	count_strings(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char	**get_lines(char **envp)
{
	int		i;
	int		size;
	char	**lines;

	i = 0;
	size = count_strings(envp);
	lines = (char **)malloc(sizeof(char *) * (size + 1));
	if (!lines)
		return (NULL);
	while (i < size)
	{
		lines[i] = ft_strdup(envp[i]);
		i++;
	}
	lines[i] = NULL;
	return (lines);
}

char	**get_var_names(char **envp)
{
	int		i;
	int		j;
	int		size;
	char	**var_names;

	i = 0;
	size = count_strings(envp);
	var_names = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		var_names[i] = ft_strndup(envp[i], j);
		i++;
	}
	var_names[i] = NULL;
	return (var_names);
}
