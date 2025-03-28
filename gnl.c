/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:06:55 by camerico          #+#    #+#             */
/*   Updated: 2025/03/28 17:40:26 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdarg.h"
#include "unistd.h"
#include "stdlib.h"
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char *ft_strdup(char *src)
{
    int i;
    char *dest;
    i = 0;

    while(src[i])
        i++;
    dest = (char*)malloc(sizeof(char) * (i +1));
    i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}


char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos;
	static int buffer_read;
	char line[70000];
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break;  
	}
	if (i == 0)
		return(NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}

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

