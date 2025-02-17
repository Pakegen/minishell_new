/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:05:39 by axbaudri          #+#    #+#             */
/*   Updated: 2025/02/07 12:46:54 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*char	**parse_echo(t_prompt *prompt)
{
	char	**strs;
	int		i;

	i = 0;
	while (prompt->echo[i] && prompt->echo[i] != '\'' && prompt->echo[i] != '"')
		i++;
	if (prompt->echo[i] == '\'')
		strs = ft_split(prompt->echo, '\'');
	else
		strs = ft_split(prompt->echo, '"');
	return (strs);
}*/

void	check_each_string(char *echo, char **strs, int quote)
{
	char	**splitted_str;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (echo[i])
	{
		if (echo[i] == quote)
			count++;
		if (ft_strcmp(echo + i, strs[j]) == 0)
		{
			if (count % 2 == 0)
			{
				splitted_str = ft_split(strs[j], ' ');
				free(strs[j]);
				strs[j] = ft_strjoin2(count_words(strs[j]), splitted_str, " ");
				free_2d_array(splitted_str);
			}
			j++;
		}
		i++;
	}
}

char	**parse_echo(t_prompt *prompt)
{
	char	**strs;
	int		i;
	int		j;
	int		number_of_quotes;
	int		quote;

	i = 0;
	j = 0;
	number_of_quotes = count_quotes(prompt->echo);
	while (prompt->echo[i] && prompt->echo[i] != '\'' && prompt->echo[i] != '"')
		i++;
	if (prompt->echo[i] == '\'')
		quote = prompt->echo[i];
	else
		quote = '"';
	strs = ft_split(prompt->echo, quote);
	check_each_string(prompt->echo, strs, quote);
	return (strs);
}

char	*exec_echo(char *cmd_line, char **strs)
{
	int		i;
	char	*echo;

	i = 0;
	if (!count_quotes(cmd_line))
		echo = ft_strjoin2(count_words(cmd_line) - 2, strs + 2, " ");
	else if (count_quotes(cmd_line) % 2 == 1)
		echo = ft_strdup("Error");
	else
		echo = find_third_word(cmd_line);
	return (echo);
}

char	*join_strings(char **strs)
{
	char	*joined_str;

	joined_str = ft_strjoin2(count_strings(strs), strs, "");
	return (joined_str);
}
