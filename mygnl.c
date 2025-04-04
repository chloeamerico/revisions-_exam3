/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mygnl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeamerico <chloeamerico@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:22:55 by camerico          #+#    #+#             */
/*   Updated: 2025/04/03 14:08:12 by chloeameric      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char	*ft_strdup(char *src)
{
	char *dest;
	int	i = 0;

	if (!src)
		return(NULL);
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int	buffer_pos = 0;
	static int	buffer_read = 0;
	char	line[70000];
	int	i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while(1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break;
		}
		line[i] = buffer[buffer_pos++];
		if (line[i++] == '\n')
			break;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return(ft_strdup(line));
}









// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE];
// 	static int	buffer_pos;
// 	static int	buffer_read;
// 	char	line[70000];
// 	int	i = 0;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (1)
// 	{
// 		if (buffer_pos >= buffer_read)
// 		{
// 			buffer_read = read(fd, buffer, BUFFER_SIZE);
// 			buffer_pos = 0;
// 			if (buffer_read <= 0)
// 				break;
// 		}
// 		line[i++] = buffer[buffer_pos++];
// 		if (line[i - 1] == '\n')
// 			break;
// 	}
// 	if (i == 0)
// 		return (NULL);
// 	line[i] = '\0';
// 	return (ft_strdup(line));
// }

int main(void)
{
    int fd;
    char *str;

    fd = open("test.txt", O_RDWR);
    str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
	str = get_next_line(fd);
    printf("%s", str);
    str = get_next_line(fd);
    printf("%s", str);
	return (0);
}