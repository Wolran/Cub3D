static int	ft_sreach(char *str, int count)
{
	if (str[0] == 'N' && str[1] == 'O' && !(count & 1))
		count += 1;
	else if (str[0] == 'S' && str[1] == 'O' && !(count & 2))
		count += 2;
	else if (str[0] == 'W' && str[1] == 'E' && !(count & 4))
		count += 4;
	else if (str[0] == 'E' && str[1] == 'A'&& !(count & 8))
		count += 8;
	else if (str[0] == 'F' && !(count & 16))
		count += 16;
	else if (str[0] == 'C' && !(count & 32))
		count += 32;
	else if (str[0] == '\n')
		return (count);
	else
		return (-1);
	return (count);
	
}

int	ft_pars(int map)
{
	char	*str;
	int		count;
	
	count = 0;
	while ((str = get_next_line(map)) || (count < 63 && count > 0))
		count = ft_search(str, count);
	if (count == 63)
	while (str = get_next_line(map)
}