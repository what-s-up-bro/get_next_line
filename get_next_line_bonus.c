/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:31:12 by yaait-am          #+#    #+#             */
/*   Updated: 2024/11/27 10:16:06 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
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
	if (!s || !s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new_ret = malloc(i + 1);
	if (!new_ret)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_ret[j] = s[j];
		j++;
	}
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
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (free(s), NULL);
	save = malloc(ft_strlen(s) - i);
	if (!save)
		return (free(s), s = NULL, NULL);
	i++;
	while (s[i])
		save[j++] = s[i++];
	save[j] = '\0';
	free(s);
	return (save);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*readed;
	static char	*save[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	readed = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!readed)
		return (free(save[fd]), save[fd] = NULL, NULL);
	i = 1;
	while (!(ft_strchr(save[fd], '\n')) && i > 0)
	{
		i = read(fd, readed, BUFFER_SIZE);
		if (i < 0)
			return (free(readed), free(save[fd]), save[fd] = NULL, NULL);
		readed[i] = '\0';
		save[fd] = ft_strjoin(save[fd], readed);
	}
	free(readed);
	line = ft_return(save[fd]);
	save[fd] = ft_after_new_line(save[fd]);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
// 	int fd = open("test", O_RDONLY);
// 	int fd1 = open("txt", O_RDONLY);
// 	char *line;
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	char *line1;
// 	line1 = get_next_line(fd1);
// 	printf("%s", line1);
// 		line = get_next_line(fd);
// 	printf("%s", line);
// 	line1 = get_next_line(fd1);
// 	printf("%s", line1);
// 		line = get_next_line(fd);
// 	printf("%s", line);
// 	line1 = get_next_line(fd1);
// 	printf("%s", line1);
// 		line = get_next_line(fd);
// 	printf("%s", line);
// 	line1 = get_next_line(fd1);
// 	printf("%s", line1);
// 		line = get_next_line(fd);
// 	printf("%s", line);
// 	return (0);
// }
