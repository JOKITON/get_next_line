/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:09:20 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/28 16:48:07 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*ft_cut_line(char *line)
{
	int		line_pos;
	int		pos_temp;
	char	*temp;

	line_pos = 0;
	while (line[line_pos] && line[line_pos] != '\n')
		line_pos++;
	if (!line[line_pos])
	{
		free(line);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(line) - line_pos + 1));
	if (!temp)
		return (NULL);
	line_pos++;
	pos_temp = 0;
	while (line[line_pos])
		temp[pos_temp++] = line[line_pos++];
	temp[pos_temp] = '\0';
	free(line);
	return (temp);
}

static	char	*ft_read(int fd, char *str, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

static	char	*ft_get_line(char *line)
{
	int		line_pos;
	char	*temp;

	line_pos = 0;
	if (!line[line_pos])
		return (NULL);
	while (line[line_pos] && line[line_pos] != '\n')
		line_pos++;
	temp = (char *)malloc(sizeof(char) * (line_pos + 2));
	if (!temp)
		return (NULL);
	line_pos = -1;
	while (line[++line_pos] && line[line_pos] != '\n')
		temp[line_pos] = line[line_pos];
	if (line[line_pos] == '\n')
	{
		temp[line_pos] = line[line_pos];
		line_pos++;
	}
	temp[line_pos] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char			*line_save[4096];
	char				*line;
	char				*buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line_save[fd] = ft_read(fd, line_save[fd], buffer);
	if (!line_save[fd])
		return (NULL);
	line = ft_get_line(line_save[fd]);
	line_save[fd] = ft_cut_line(line_save[fd]);
	free(buffer);
	return (line);
}
