/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astolbov <astolbov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:45:17 by astolbov          #+#    #+#             */
/*   Updated: 2024/08/07 15:19:48 by astolbov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

char	*reader(int fd, char *backup)
{
	int		read_line;
	char	*buf;

	read_line = 1;
	while (!newline(backup) && read_line != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		read_line = (int)read(fd, buf, BUFFER_SIZE);
		if ((!backup && read_line == 0) || read_line == -1)
			return (free(buf), NULL);
		buf[read_line] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	return (backup);
}

char	*ft_get_line(char *backup)
{
	int		i;
	char	*str;

	if (!backup)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = -1;
	while (backup[++i] && backup[i] != '\n')
		str[i] = backup[i];
	if (backup[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_backup(char *backup, char *str)
{
	int		i;
	int		j;
	char	*new;

	i = ft_strlen(str);
	if (!backup[i])
		return (free(backup), NULL);
	j = 0;
	while (backup[i++])
		j++;
	new = malloc(sizeof(char) * (j + 1));
	if (!new)
		return (NULL);
	i = ft_strlen(str);
	j = 0;
	while (backup[i])
		new[j++] = backup[i++];
	new[j] = '\0';
	return (free(backup), new);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = reader(fd, backup);
	if (!temp)
	{
		if (backup)
			free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = temp;
	line = ft_get_line(backup);
	backup = ft_new_backup(backup, line);
	return (line);
}
