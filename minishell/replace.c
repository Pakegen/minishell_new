/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:19:21 by axbaudri          #+#    #+#             */
/*   Updated: 2025/02/04 12:19:21 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_occurrences2(const char *str, char *to_find)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strncmp(str + i, to_find, ft_strlen(to_find)) == 0)
			count++;
		i++;
	}
	return (count);
}

int	calculate_size_for_replace(const char *str, char *a, char *b)
{
	int		difference;
	int		length;

	difference = (ft_strlen(b) - ft_strlen(a)) * count_occurrences2(str, a);
	length = ft_strlen(str) + difference;
	return (length);
}

char	*replace(const char *str, char *a, char *b)
{
	int		i;
	int		size;
	int		total_size;
	char	*new_string;

	i = 0;
	total_size = calculate_size_for_replace(str, a, b);
	new_string = (char *)malloc(sizeof(char) * total_size + 1);
	if (!new_string)
		return (NULL);
	while (*str)
	{
		if (ft_strncmp(str, a, ft_strlen(a)) == 0)
		{
			size = 0;
			while (b[size])
				new_string[i++] = b[size++];
			str += ft_strlen(a);
		}
		else
			new_string[i++] = *str++;
	}
	new_string[i] = 0;
	return (new_string);
}
