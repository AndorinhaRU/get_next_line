/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astolbov <astolbov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:45:17 by astolbov          #+#    #+#             */
/*   Updated: 2024/08/07 13:55:43 by astolbov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

char	*reader(int fd, char *backup)
{
	int		read_line;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_line = 1;
	while (!ft_strchr(backup, '\n') && read_line != 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_line] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	free(buf);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = reader(fd, backup);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_new_backup(backup);
	return (line);
}
