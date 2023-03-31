/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:14 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/31 11:12:01 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen_s(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static char	*ft_strchr2(const char *s, int c)
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
	while (src && src[j] && src[j] != '\n')
	{
		dst[start + j] = src[j];
		j++;
	}
	if (src && src[j] == '\n')
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
	if (!ptr)
		return (NULL);
	len = 0;
	ptr++;
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

char	*ft_expand(char *line, size_t *size)
{
	char	*new_line;

	*size = (*size + BUFFER_SIZE) * 2 + 1;
	new_line = malloc(*size * sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	ft_strlcat2(new_line, line, 0);
	if (line)
		free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	s_buff[OPEN_MAX][BUFFER_SIZE];
	char		*line;
	size_t		idx;
	size_t		size;
	int			n_read;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	idx = 0;
	line = NULL;
	size = 1;
	//printf("is deha dans buff :#%s#\n", s_buff[fd]);

	if (s_buff[fd][0] != '\0')
	{
		line = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line)
			return (NULL);
		idx = ft_strlcat2(line, s_buff[fd], idx);
		ft_refresh(s_buff[fd]);
		if (ft_strchr2(line, '\n'))
			return (line);
	}
	while (!ft_strchr2(s_buff[fd], '\n'))
	{
		//printf("idx = %ld\tsize = %ld\n", idx, size);
		n_read = read(fd, s_buff[fd], BUFFER_SIZE);
		if (n_read == -1)
			return (free(line), NULL);
		if (n_read == 0)
		{
			ft_bzero(s_buff[fd], BUFFER_SIZE);
			return (line);
		}
		if (idx == size - 1)
			line = ft_expand(line, &size);
		if (!line)
			return (NULL);
		//printf("read :%s:\n", s_buff[fd]);
		idx = ft_strlcat2(line, s_buff[fd], idx);
		//printf("line atfer strlcat :%s:\n", line);
		if (s_buff[fd][0] == '\0')
			break ;
	}
	//printf("rbuff avant refresh :#%s#\n", s_buff[fd]);
	ft_refresh(s_buff[fd]);
	//printf("reste buff :#%s#\n", s_buff[fd]);
	return (line);
}
