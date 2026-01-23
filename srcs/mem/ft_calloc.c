/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalegran <lalegran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:01:37 by tlegrand          #+#    #+#             */
/*   Updated: 2025/12/03 15:37:34 by lalegran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size > 0 && count >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	*ft_recalloc(void *ptr, size_t size, size_t target)
{
	void	*tmp;

	tmp = NULL;
	if (target > SIZE_MAX)
		return (NULL);
	if (target != 0)
	{
		tmp = malloc(target);
		if (!tmp)
			return (NULL);
		ft_bzero(tmp, target);
		if (!ptr)
			return (tmp);
		if (target < size)
			tmp = ft_memmove(tmp, ptr, target);
		else
			tmp = ft_memmove(tmp, ptr, size);
	}
	if (ptr)
		free(ptr);
	return (tmp);
}
