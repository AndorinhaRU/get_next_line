/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astolbov <astolbov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:17:23 by astolbov          #+#    #+#             */
/*   Updated: 2024/08/07 15:18:45 by astolbov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *backup, char *buf)
{
	int		i;
	int		j;
	char	*temp;

	if (!backup && !buf)
		return (NULL);
	if (!backup)
		backup = ft_calloc(1, sizeof(char));
	temp = malloc(sizeof(char) * (ft_strlen(backup) + ft_strlen(buf) + 1));
	if (!temp)
		return (NULL);
	i = -1;
	while (backup[++i])
		temp[i] = backup[i];
	j = -1;
	while (buf[++j])
		temp[i++] = buf[j];
	temp[i] = '\0';
	return (free(backup), free(buf), temp);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*p;

	i = 0;
	if (count && size > SIZE_MAX / count)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (i < count)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}
