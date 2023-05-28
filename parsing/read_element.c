/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:58:45 by vmuller           #+#    #+#             */
/*   Updated: 2023/05/28 19:59:08 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static void	set_type(char **type)
{
	type[EA] = "EA";
	type[WE] = "WE";
	type[SO] = "SO";
	type[NO] = "NO";
	type[C] = "C";
	type[F] = "F";
}

static int	ft_read(int fd, char *buf, size_t len)
{
	int	ret;

	ret = read(fd, buf, len);
	if (ret <= 0)
		ft_error("element is wrong");
	return (len);
}

static char	*ft_gnl(int fd)
{
	char	*line;
	char	*tmp;
	int		i;

	line = (char *)malloc(sizeof(char) * 1000000);
	if (!line)
		ft_error("element is wrong");
	i = 0;
	while (ft_read(fd, line + i, 1) && line[i] != '\n')
		i++;
	line[i] = 0;
	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	tmp = ft_strdup(line + i);
	free(line);
	if (!tmp)
		ft_error("element is wrong");
	return (tmp);
}

static int	read_type(int fd, char **type)
{
	char	id[3];
	int		i;
	int		type_num;

	ft_memset(id, 0, sizeof(char) * 3);
	i = 0;
	while ((i < 3 && (ft_read(fd, id + i, 1) == 1))
		&& !(ft_isspace(id[i]) || id[i] == '\n'))
			i++;
	if (i == 3)
		ft_error("element is wrong");
	if (i == 0 && id[i] == '\n')
		return (-1);
	type_num = 0;
	id[i] = 0;
	while (type_num < TYPE
		&& !(!ft_strncmp(type[type_num], id, ft_strlen(type[type_num])) \
		&& ft_strlen(id) == ft_strlen(type[type_num])))
		type_num++;
	if (type_num == TYPE)
		ft_error("element is wrong");
	return (type_num);
}

void	read_element(int fd, t_pars *pars)
{
	int		type_flag[TYPE];
	int		type_num;
	int		i;
	char	*type[TYPE];

	ft_memset(type_flag, 0, sizeof(int) * TYPE);
	set_type(type);
	i = 0;
	while (i != TYPE)
	{
		type_num = read_type(fd, type);
		if (type_num < 0)
			continue ;
		else
		{
			if (!type_flag[type_num])
				type_flag[type_num] = 1;
			else
				ft_error("element is wrong");
			pars->element[type_num] = ft_gnl(fd);
		}
		i = 0;
		while (i < TYPE && type_flag[i] == 1)
			i++;
	}
}
