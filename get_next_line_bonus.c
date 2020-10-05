/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:44:19 by juasanto          #+#    #+#             */
/*   Updated: 2020/10/05 14:12:58 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strdel(char **string)
{
	if (string != NULL && *string != NULL)
	{
		free(*string);
		*string = NULL;
	}
}

int		ft_add(char **read_fd, int fd, char **line)
{
	int		count;
	char	*tmp1;

	count = 0;
	while (read_fd[fd][count] != '\n')
		count++;
	*line = ft_substr(read_fd[fd], 0, count);
	tmp1 = ft_strdup(&read_fd[fd][count + 1]);
	free(read_fd[fd]);
	read_fd[fd] = tmp1;
	return (1);
}

int		fn_return(char **line, int fd, char **read_fd, ssize_t bytes_read)
{
	if (bytes_read < 0)
		return (-1);
	else if (bytes_read == 0 && (read_fd[fd] == NULL || read_fd[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		ft_strdel(&read_fd[fd]);
		return (0);
	}
	else if (ft_strchr(read_fd[fd], '\n'))
		return (ft_add(read_fd, fd, line));
	else
	{
		*line = ft_strdup(read_fd[fd]);
		ft_strdel(&read_fd[fd]);
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	ssize_t		bytes_read;
	static char	*read_fd[4096];
	char		*tmp;

	bytes_read = 0;
	if (fd < 0 || line == 0 || BUFFER_SIZE < 1 || \
		(!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (read_fd[fd] == NULL)
			read_fd[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(read_fd[fd], buffer);
			free(read_fd[fd]);
			read_fd[fd] = tmp;
		}
		if (ft_strchr(read_fd[fd], '\n') != 0)
			break ;
	}
	free(buffer);
	return (fn_return(line, fd, read_fd, bytes_read));
}
