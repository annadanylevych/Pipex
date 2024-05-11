/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:27:56 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/16 20:34:53 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*line_extraction(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_storage(char *storage, char *line)
{
	char	*tmp;

	if (storage[0] == '\0')
	{
		free(storage);
		return (NULL);
	}
	tmp = ft_substrg(storage, ft_strleng(line), ft_strleng(storage) \
			- ft_strleng(line));
	free(storage);
	return (tmp);
}

char	*ft_read(int fd, char *storage)
{
	char	*buffer;
	int		mbytesread;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(storage);
		return (NULL);
	}
	buffer[0] = '\0';
	mbytesread = 1;
	while (mbytesread > 0 && !ft_strchr(buffer, '\n'))
	{
		mbytesread = read(fd, buffer, BUFFER_SIZE);
		if (mbytesread == -1)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[mbytesread] = '\0';
		storage = ft_strjoing(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage || (storage && !ft_strchr(storage, '\n')))
		storage = ft_read(fd, storage);
	if (!storage)
		return (NULL);
	line = line_extraction(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	if (*line == '\0')
	{
		free(line);
		line = NULL;
	}
	storage = update_storage(storage, line);
	return (line);
}
/*
int	main(void)
{
	char *line;
	int fd = open("test.txt", O_RDWR);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	return (0);
}
*/