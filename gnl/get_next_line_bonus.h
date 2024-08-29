/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:05:36 by anikitin          #+#    #+#             */
/*   Updated: 2024/07/31 13:33:47 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# ifndef FD_MAX
#  define FD_MAX OPEN_MAX
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);
char	*copy_next(char *s, int c);
char	*copy_current(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_free(char **tmp);

#endif