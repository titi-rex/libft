/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:14 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/31 00:20:53 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_strlen_s(const char *s)
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
	//printf("strlcat2.start\n");
	while (src && src[j] && src[j] != '\n')
	{
		//printf("strlcat2.src[%ld] = :%c:\t", j, src[j]);
		dst[start + j] = src[j];
		j++;
	}
	//printf("strlcat2.cpy\n");
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
	while (*ptr && len < BUFFER_SIZE)
	{
		*(s_buff + len) = *ptr;
		len++;
		ptr++;
	}
	len--;
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

	*size = *size * 2 + 1;
	new_line = ft_calloc(*size, sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	//printf("expand.malloc\n");
	ft_strlcat2(new_line, line, 0);
	//printf("expand.strlcat2\n");
	if (line)
		free(line);
	//printf("expand.new_line :%s:\n", new_line);
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
	size = ft_strlen_s(line) + 1;
	while (!ft_strchr2(s_buff[fd], '\n'))
	{
		//printf("idx = %ld\tsize = %ld\n", idx, size);
		//printf("while.expand\n");
		n_read = read(fd, s_buff[fd], BUFFER_SIZE);
		if (n_read == -1)
			return (free(line), NULL);
		if (n_read == 0)
			return (line);
		if (idx == size - 1)
			line = ft_expand(line, &size);
		if (!line)
			return (NULL);
		//printf("buffer :%s:\n", s_buff[fd]);
		idx = ft_strlcat2(line, s_buff[fd], idx);
		//printf("line :%s:\n", line);
		if (s_buff[fd][0] == '\0')
			break ;
	}
	ft_refresh(s_buff[fd]);
	printf("#%s#\n", s_buff[fd]);
	return (line);
}
