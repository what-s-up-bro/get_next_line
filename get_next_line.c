/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:37:47 by yaait-am          #+#    #+#             */
/*   Updated: 2024/11/22 19:56:01 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    ft_strlen(const char *s)
{
    int    i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_line(char **save)
{
    static char    new_save[2048];
    char    make[1024];
    char    *find_line;
    int        i;

    if (!save || !*save || **save == '\0')
        return ;
    i = 0;
    if (new_save[0] != '\0')
    {
        ft_strcat(new_save, *save);
        ft_strcpy(*save, new_save);
        new_save[0] = '\0';
    }
    find_line = ft_strchr(*save, '\n');
    if (find_line)
    {
        while ((*save)[i] && (*save)[i] != '\n')
        {
            make[i] = (*save)[i];
            i++;
        }
        make[i] = '\n';
        make[i++] = '\0';
        ft_strcpy(new_save, find_line + 1);
        ft_strcpy(*save, make);
    }
    else
    {
        ft_strcpy(make, *save);
        make[ft_strlen(*save)] = '\0';
        new_save[0] = '\0';
        ft_strcpy(*save, make);
    }
}

char    *get_next_line(int fd)
{
    int    i;
    char    readed[BUFFER_SIZE + 1];
    static char    *save;

    i = 0;
    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    while ((i = read(fd, readed, BUFFER_SIZE)) > 0)
    {
        readed[i] = '\0';
        save = ft_strjoin(save, readed);
        if (ft_strchr(readed, '\n'))
            break ;
     }
    if (i < 0 || (!save && i == 0))
        return (NULL);
    ft_line(&save);
    return(save);
}
