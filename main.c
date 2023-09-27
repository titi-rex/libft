/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:45:07 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/27 16:12:17 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **arg)
{
	if (ac != 2)
		return (1);
	int	fd = open(arg[1], O_RDONLY);
	if (fd == -1)
		return (1);
	char	*line = NULL;
	
	do
	{
		ft_free_secure(line);
		if (get_next_line(fd, &line))
			ft_printf("gnl malloc error\n");
		else
			ft_printf("line:%s\n", line);
	}	while (line);


	
	// printf("%s\n", line);
	ft_free_secure(line);
	close(fd);
	return (0);
}
