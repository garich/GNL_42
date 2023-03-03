/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:28:33 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/02 15:39:23 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2);
	result = ft_calloc((size + 1), sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			result[i] = s1[i];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p)
		ft_memset(p, 0, count * size);
	return (p);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	cast_c;
	unsigned long	counter;
	char			*cast_b;

	counter = 0;
	cast_c = (unsigned char) c;
	cast_b = (char *)b;
	while (len != 0 && counter <= len - 1)
	{
		*(cast_b + counter) = cast_c;
		counter++;
	}
	return (cast_b);
}
