/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:25:25 by vmuller           #+#    #+#             */
/*   Updated: 2022/05/12 08:25:28 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*str;
	int			flag;
	static int	size;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	size = BUFFER_SIZE / BUFFER_SIZE;
	buffer = ft_calloc((size + 1), sizeof(char));
	str = NULL;
	flag = read(fd, buffer, size);
	if (flag > 0)
		str = ft_calloc((size + 1), sizeof(char));
	while (flag > 0 && buffer[0] != '\n')
	{
		str = ft_strjoin(str, buffer);
		flag = read(fd, buffer, size);
	}
	if (buffer[0] == '\n')
		str = ft_strjoin(str, "\n");
	free(buffer);
	return (str);
}

/*
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
int	main(void)
{
	int	fd;
	
	fd = open("fichier", O_RDONLY);
	
	for (int i = 0; i < 10; i++)
		printf("%s", get_next_line(fd));
}
*/
