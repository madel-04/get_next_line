/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/10/09 20:45:09 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 10:27:40 by marvin           ###   ########.fr       */
=======
/*   Created: 2024/09/25 11:34:06 by madel-va          #+#    #+#             */
/*   Updated: 2024/09/30 11:52:59 by madel-va         ###   ########.fr       */
>>>>>>> 020313595f3e95a8cd68d8d50673dcf93e24eafd
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_trim_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(ft_strlen(buffer) - i);
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}
<<<<<<< HEAD

static char	*ft_join_and_free(char *buffer, char *temp)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(buffer, temp);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (new_buffer);
}

static char	*ft_trybuffer(char *buffer)
{
=======
/*Buffer nuevo sin la linea*/
// Inicializar buffer vacío si es NULL

static char	*ft_trybuffer(char *buffer)
{
>>>>>>> 020313595f3e95a8cd68d8d50673dcf93e24eafd
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	return (buffer);
}

static char	*ft_read_to_buffer(int fd, char *buffer)
{
<<<<<<< HEAD
	char	*temp;
	int		bytes_read;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
=======
	char	temp[BUFFER_SIZE + 1];
	int		bytes_read;

>>>>>>> 020313595f3e95a8cd68d8d50673dcf93e24eafd
	buffer = ft_trybuffer(buffer);
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp), free(buffer), NULL);
		if (bytes_read == 0)
<<<<<<< HEAD
			return (free(temp), buffer);
=======
			return (NULL);
>>>>>>> 020313595f3e95a8cd68d8d50673dcf93e24eafd
		temp[bytes_read] = '\0';
		buffer = ft_join_and_free(buffer, temp);
		if (!buffer)
			return (free(temp), NULL);
	}
	return (free(temp), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_to_buffer(fd, buffer);
	if (!buffer || *buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_extract_line(buffer);
	buffer = ft_trim_buffer(buffer);
	return (line);
}
