/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:28:46 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/01 06:51:07 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*extract_before_bl(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (buf[++i] && buf[i] != '\n')
		line[i] = buf[i];
	if (buf[i] && buf[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*extract_after_bl(char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (free(buf), NULL);
	if (buf[i] == '\n')
		i++;
	line = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	if (!line)
		return (free(buf), NULL);
	j = 0;
	while (buf[i])
		line[j++] = buf[i++];
	free(buf);
	return (line);
}

char	*read_buffer(int fd, char *later)
{
	char	*buf;
	int		bytes_read;
	int		flag;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (free(later), NULL);
	flag = 1;
	while (flag)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buf), free(later), NULL);
		buf[bytes_read] = '\0';
		if (bytes_read != 0)
			later = ft_free(later, buf);
		if (ft_strchr(buf, '\n') || bytes_read == 0 || !later)
			flag = 0;
	}
	return (free(buf), later);
}

char	*get_next_line(int fd)
{
	static char	*later;
	char		*line;

	if (!later)
		later = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || !later)
	{
		if (!later)
			return (NULL);
		return (free(later), later = NULL, NULL);
	}
	later = read_buffer(fd, later);
	if (later)
	{
		line = extract_before_bl(later);
		later = extract_after_bl(later);
		if (line)
			return (line);
		return (free(later), later = NULL, line);
	}
	return (free(later), later = NULL, NULL);
}
