/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:58:52 by qacjl             #+#    #+#             */
/*   Updated: 2025/02/17 04:33:31 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
//lier adv_tokeniser
#include "minishell.h"

char	*append_char(char *str, char c)
{
	size_t	len;
	char	*new_str;
	size_t	i;

	if (str)
		len = ft_strlen(str);
	else
		len = 0;
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	if (str)
		free(str);
	return (new_str);
}
*/
