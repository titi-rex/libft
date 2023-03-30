/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:36:37 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/31 00:16:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **arg)
{
	int		fd;
	char	*line;
	int		len = 15;

	if (ac != 2)
		return (1);
	fd = open(arg[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error "), 1);
	line = "";
	while (line && len--> 0)
	{
		line = get_next_line(fd);
		ft_printf(":%s:", line);
		ft_free_secure(line);
	}
	ft_printf("\nEND\n");
}
