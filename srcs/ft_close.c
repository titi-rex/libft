/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:19:00 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/30 18:20:54 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_close_secure(int fd)
{
	if (fd != -1)
		if (close(fd))
			perror("Error ");
	return (-1);
}

void	ft_close_pipe(int pipefd[2])
{
	if (pipefd[0] != -1)
		close(pipefd[0]);
	pipefd[0] = -1;
	if (pipefd[1] != -1)
		close(pipefd[1]);
	pipefd[1] = -1;
}
