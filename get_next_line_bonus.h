/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:33:03 by yaait-am          #+#    #+#             */
/*   Updated: 2024/11/25 14:34:35 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# if BUFFER_SIZE > 2147483645
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0

# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *s);
char	*ft_after_new_line(char *s);
char	*ft_return(char *s);

#endif
