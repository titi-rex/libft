/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalegran <lalegran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:37:45 by tlegrand          #+#    #+#             */
/*   Updated: 2025/12/04 11:41:18 by lalegran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max3(int a, int b, int c)
{
	if (a >= b && b >= c)
		return (a);
	if (b > c)
		return (b);
	return (c);
}

int	ft_min3(int a, int b, int c)
{
	if (a <= b && b <= c)
		return (a);
	if (b < c)
		return (b);
	return (c);
}

long int	ft_abs(long int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
