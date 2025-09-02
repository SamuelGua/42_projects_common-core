/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:49:44 by scely             #+#    #+#             */
/*   Updated: 2023/12/07 08:53:12 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s)
{
	int			i;

	i = 0;
	if (!s)
		return (1);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] != '\n')
		return (1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return ((char *)new);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*d;
	size_t	i;
	size_t	j;

	if (count == 0 || size == 0)
		j = 1;
	else if (count > 65535 || size > 65535 || count * size > 65535)
		return (NULL);
	else
		j = count * size;
	i = 0;
	d = malloc(j);
	if (d == 0)
		return (0);
	while (j > 0)
	{
		d[i] = '\0';
		j--;
		i++;
	}
	return ((void *)d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (!s)
		return (0);
	i = 0;
	if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (0);
	while (len > 0 && s[start])
	{
		new[i] = s[start];
		i++;
		start++;
		len--;
	}
	new[i] = '\0';
	return (new);
}
