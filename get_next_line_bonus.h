/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luigi_streber <luigi_streber@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:22:13 by luigi_streb       #+#    #+#             */
/*   Updated: 2024/09/25 22:33:43 by luigi_streb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# define MAX_OPEN_FILE 1024
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stddef.h>
# include <sys/types.h>

//compilable 
//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42
//main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

size_t	ft_strlen(const char *s);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
