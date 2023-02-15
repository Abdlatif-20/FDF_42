/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:04:03 by aben-nei          #+#    #+#             */
/*   Updated: 2023/02/15 02:06:00 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

/* ------------------- Prototype Function -------------------*/

char	*get_next_line(int fd);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strchr1(char *s, char c);
size_t	ft_strlen1(char *str, char c);
char	*ft_strdup1(char *s);
char	*ft_substr1(char *s, unsigned int start, size_t len);
#endif
