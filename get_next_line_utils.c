/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 09:24:04 by juasanto          #+#    #+#             */
/*   Updated: 2020/10/07 12:02:14 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *string)
{
	int cnt;

	cnt = 0;
	while (*string != '\0')
	{
		string++;
		cnt++;
	}
	return (cnt);
}

char	*ft_strjoin(const char *string1, const char *string2)
{
	char	*str_join;
	int		count;

	count = 0;
	if (string1 == NULL || string2 == NULL)
		return (NULL);
	str_join = (char *)malloc(sizeof(char) *
		(ft_strlen(string1) + ft_strlen(string2)) + 1);
	if (str_join == NULL)
		return (NULL);
	while (*string1 != '\0')
	{
		str_join[count] = *string1;
		count++;
		string1++;
	}
	while (*string2 != '\0')
	{
		str_join[count] = *string2;
		count++;
		string2++;
	}
	str_join[count] = '\0';
	return (str_join);
}

char	*ft_strdup(const char *string1)
{
	char	*str_dup;
	int		count;

	count = 0;
	str_dup = (char *)malloc(sizeof(char) * (ft_strlen(string1)) + 1);
	if (str_dup == NULL)
		return (NULL);
	while (string1[count] != '\0')
	{
		str_dup[count] = string1[count];
		count++;
	}
	str_dup[count] = '\0';
	return (str_dup);
}

char	*ft_strchr(const char *string, int chr)
{
	while (*string != 0)
	{
		if (*string == (char)chr)
			return ((char *)string);
		string++;
	}
	if ((char)chr == '\0')
		return ((char *)string);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	size_t			count;
	unsigned int	ft_len;

	count = 0;
	if (s == NULL)
		return (NULL);
	if ((string = (char *)malloc(sizeof(*s) * (len + 1))) == 0)
		return (NULL);
	ft_len = (unsigned int)(ft_strlen(s));
	while (count < len && start < ft_len)
	{
		string[count] = s[count + start];
		count++;
	}
	string[count] = '\0';
	return (string);
}
