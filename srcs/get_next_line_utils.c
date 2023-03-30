/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/30 23:44:59 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	c = c % 256;
	while (*(s + i) != (char)c && *(s + i) != 0)
		i++;
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlcat2(char *dst, char *src, size_t start)
{
	size_t	j;

	j = 0;
	while (src[j] && src[j] != '\n')
	{
		dst[start + j] = src[j];
		j++;
	}
	if (src[j] == '\n')
	{

		dst[start + j] = src[j];
		j++;
	}
	dst[start + j] = '\0';
	return (start + j);
}

char	*ft_refresh(char *s_buff)
{
	char	*ptr;
	int		len;

	ptr = ft_strchr(s_buff, '\n');
	len = 0;
	while (*ptr && len < BUFFER_SIZE)
	{
		*(s_buff + len) = *ptr;
		len++;
		ptr++;
	}
	while (len < BUFFER_SIZE)
	{
		*(s_buff + len) = 0;
		len++;
	}
	return (s_buff);
}
