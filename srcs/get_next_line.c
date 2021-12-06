/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 04:14:45 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/06 02:13:58 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * The read_next_line() function ...
 */
static char	*read_next_line(char *data)
{
	int		i;
	int		n;
	char	*line;

	line = NULL;
	i = 0;
	while (data[i] != '\0')
		i++;
	if (data[i] == '\n')
		i += 1;
	n = 0;
	if (!data)
		return (NULL);
	if (i > 0)
	{
		line = (char *)malloc((i + 1) * sizeof(char));
		while (n < i)
		{
			line[n] = data[n];
			n++;
		}
		line[i] = '\0';
	}
	return (line);
}

/*
 * The move_next_line() function ...
 */
static char	*move_next_line(char *data)
{
	char	*tmp;
	int		i;
	int		n;

	i = 0;
	while (data[i] != '\0')
		i++;
	if (data[i] == '\n')
		i += 1;
	n = 0;
	if (!data[i])
	{
		free(data);
		return (NULL);
	}
	tmp = (char *)malloc((ft_strlen(data) - i + 1) * sizeof(char));
	while (data[i + n])
	{
		tmp[n] = data[i + n];
		n++;
	}
	tmp[n] = '\0';
	free(data);
	return (tmp);
}

/*
 * The open_file() function ...
 */
static char	*open_file(int fd, char *data)
{
	char	*fdata;
	char	*tmp;
	int		flen;

	fdata = malloc((BUFFER_SIZE + 1) * sizeof(char));
	flen = 1;
	while (flen > 0 && !ft_strchr(data, '\n'))
	{
		flen = read(fd, fdata, BUFFER_SIZE);
		if (flen == -1)
		{
			free(fdata);
			return (NULL);
		}
		fdata[flen] = '\0';
		tmp = ft_strjoin(data, fdata);
		free(data);
		data = tmp;
	}
	free(fdata);
	return (data);
}

/*
 * The search_files() function ...
 */
static t_files	*search_files(int fd)
{
	static t_files	files;
	t_files			tmp_file;

	if (files.fd != fd)
	{
		files.fd = fd;
		files.data = "1";
		files.next = NULL;
	}
	else
	{
		tmp_file.fd = fd;
		tmp_file.data = "2";
		tmp_file.next = NULL;
		files.next = &tmp_file;
	}
	return (&files);
}

/*
 * The get_next_line() function reads untill the first occurrence of
 * the '\n' or '\0' and returns the next line found, if no line can be
 * found, or if a error has occurred, the function returns NULL
 */
char	*get_next_line(int fd)
{
	t_files		*file;
	static char	*data;
	char		*line;

	file = search_files(fd);
	printf("%s\n", file->data);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	data = open_file(fd, data);
	if (!data)
		return (NULL);
	line = read_next_line(data);
	data = move_next_line(data);
	if (!line)
		return (NULL);
	return (line);
}
