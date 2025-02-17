/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:55:41 by axbaudri          #+#    #+#             */
/*   Updated: 2025/02/06 18:05:31 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	sort_strings(char **envp, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(envp[i], envp[i + 1]) > 0)
		{
			tmp = envp[i];
			envp[i] = envp[i + 1];
			envp[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

char	*find_third_word(const char *cmd_line)
{
	int		i;
	int		count;
	char	*echo;

	i = 0;
	count = 0;
	if (cmd_line[0] != ' ')
	{
		i++;
		count++;
	}
	while (cmd_line[i] && count < 3)
	{
		if (cmd_line[i] == ' ' && cmd_line[i + 1] && cmd_line[i + 1] != ' ')
			count++;
		i++;
	}
	echo = ft_strdup(cmd_line + i);
	return (echo);
}
