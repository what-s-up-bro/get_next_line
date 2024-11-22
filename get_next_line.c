/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:37:47 by yaait-am          #+#    #+#             */
/*   Updated: 2024/11/22 11:12:42 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	int	i;
	char	readed[BUFFER_SIZE + 1];
	static char	*save;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while ((i = read(fd, readed, BUFFER_SIZE)) > 0)
	{
		readed[i] = '\0';
		save = ft_strjoin(save, readed);
		if (ft_strchar(readed, '\n'))
			break ;
 	}
	if (i < 0 || (!save && i == 0))
		return (NULL);
	return(ft_line(&save));
}
