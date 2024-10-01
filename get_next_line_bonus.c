/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi_streber <luigi_streber@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:24:00 by luigi_streb       #+#    #+#             */
/*   Updated: 2024/10/01 15:00:25 by luigi_streb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*newline_exist(char *str)
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

//We read content from fd (up to BUFFER_SIZE) and store in stash.
//Leemos contendido del fd(hasta el tamaño BUFFER_SIZE) y almacenamos en stash.
static char	*read_file(int fd, char *stash)
{
	char	*buff;
	int		bytes_read;

	bytes_read = 1;
	while (!newline_exist(stash) && bytes_read != 0)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if ((bytes_read == 0 && !stash) || bytes_read == -1)
			return (free(buff), NULL);
		buff[bytes_read] = '\0';
		stash = ft_strjoin(stash, buff);
		free(buff);
	}
	return (stash);
}

//We extract the line from stash and return it.
//After reading the file, we need to extract the first line (\n).
//Extraemos la linea de stash y la retornamos.
//Despues de leer el rchivo, necesitamos  extraer la primera linea (\n).
static char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

//Stash the remainder after extracting the line.
//Data not yet processed.
//Guarda lo sobrante en el stash despues de extraer la linea.
//Datos aun no procesados.
static char	*save_remainder(char *stash)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	remainder = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!remainder)
	{
		free(stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		remainder[j++] = stash[i++];
	remainder[j] = '\0';
	free(stash);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_OPEN_FILE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = save_remainder(stash[fd]);
	return (line);
}
