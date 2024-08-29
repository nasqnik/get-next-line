/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:07:12 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/31 13:10:38 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **tmp)
{
	if (tmp && *tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	return (NULL);
}

char	*reader(int fd, char *line)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&line));
	buffer[0] = '\0';
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			line = ft_strjoin(line, buffer);
		}
	}
	free(buffer);
	if (bytes < 0)
		return (ft_free(&line));
	return (line);
}

char	*current(char *line)
{
	char	*l;

	if (!ft_strchr(line, '\n'))
		l = copy_current(line, '\0');
	else
		l = copy_current(line, '\n');
	if (!l)
		return (NULL);
	return (l);
}

char	*next(char *line)
{
	char	*n;
	char	*l;
	int		len;

	n = ft_strchr(line, '\n');
	if (!n)
	{
		l = NULL;
		return (ft_free(&line));
	}
	else
		len = n - line + 1;
	if (!line[len])
		return (ft_free(&line));
	l = copy_next(line, '\n');
	ft_free(&line);
	if (l == NULL)
		return (NULL);
	return (l);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*l;

	if (fd < 0 || BUFFER_SIZE >= INT_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = reader(fd, line);
	if (!line)
		return (NULL);
	l = current(line);
	if (!l)
		return (ft_free(&line));
	line = next(line);
	return (l);
}
