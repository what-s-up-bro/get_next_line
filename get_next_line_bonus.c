/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:00:59 by yaait-am          #+#    #+#             */
/*   Updated: 2024/11/23 18:01:09 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_return(char *s)
{
	int		i;
	int		j;
	char	*new_ret;

	i = 0;
	j = 0;
	if (!s || s[i] == '\0')
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	new_ret = malloc(i + 2);
	if (!new_ret)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		new_ret[j++] = s[i++];
	if (s[i] == '\n')
		new_ret[j++] = '\n';
	new_ret[j] = '\0';
	return (new_ret);
}

char	*ft_after_new_line(char *s)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (free (s), NULL);
	save = malloc(ft_strlen(s) - i);
	if (!save)
		return (NULL);
	i++;
	while (s[i])
		save[j++] = s[i++];
	save[j] = '\0';
	free(s);
	return (save);
}

char	*get_next_line(int fd)
{
	int				i;
	char			*readed;
	static char		*save;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	readed = malloc(BUFFER_SIZE + 1);
	if (!readed)
		return (NULL);
	i = 1;
	while (!(ft_strchr(save, '\n')) && i > 0)
	{
		i = read(fd, readed, BUFFER_SIZE);
		if (i < 0)
			return (free (readed), NULL);
		readed[i] = '\0';
		save = ft_strjoin(save, readed);
	}
	free (readed);
	line = ft_return(save);
	save = ft_after_new_line(save);
	return (line);
}
