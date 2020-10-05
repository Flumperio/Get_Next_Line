/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 12:57:21 by juasanto          #+#    #+#             */
/*   Updated: 2020/10/05 13:50:25 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *string);
char	*ft_strjoin(const char *string1, const char *string2);
char	*ft_strdup(const char *string1);
char	*ft_strchr(const char *string, int chr);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
