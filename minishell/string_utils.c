/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:41:53 by axbaudri          #+#    #+#             */
/*   Updated: 2025/02/07 12:12:48 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	count_occurrences(const char *cmd_line, int to_find)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == to_find)
			count++;
		i++;
	}
	return (count);
}

int	count_words(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] != 0 && str[0] != ' ')
	{
		i++;
		count++;
	}
	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] != 0 && str[i + 1] != ' '))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
