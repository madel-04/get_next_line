/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:33:45 by madel-va          #+#    #+#             */
/*   Updated: 2024/09/25 12:20:52 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (*s1)
		dest[i++] = *s1++;
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// Busca el carácter de nueva línea
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// Si no hay nueva línea, liberar el buffer
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// Crea un nuevo buffer que contenga lo que queda después de la nueva línea
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i));
	if (!new_buffer)
		return (NULL);
	// Copia el contenido del buffer después de la nueva línea
	i++; // Moverse al siguiente carácter después de '\n'
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	// Libera el buffer viejo
	free(buffer);
	return (new_buffer);
}
