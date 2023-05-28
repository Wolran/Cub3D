/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:58:28 by vmuller           #+#    #+#             */
/*   Updated: 2023/05/28 19:59:08 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minilibft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	size_t	len;

	temp = (char *)s;
	len = 0;
	while (*temp != 0)
		temp++;
	while (len++ < ft_strlen(s) + 1)
	{
		if (*temp == (char)c)
			return (temp);
		temp--;
	}
	return (0);
}
