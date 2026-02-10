/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalegran <lalegran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:04:16 by lalegran          #+#    #+#             */
/*   Updated: 2026/01/23 12:11:59 by lalegran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_dll	*dll_new(void *data, int flags)
{
	t_dll	*node;

	node = ft_calloc(1, sizeof(t_dll));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->flags = flags;
	return (node);
}

void	dll_insert_before(t_dll *node, t_dll *new_node)
{
	if (node)
	{
		if (node->previous != NULL)
		{
			node->previous->next = new_node;
			new_node->previous = node->previous;
		}
		else
		{
			node->next = new_node;
			new_node->previous = node;
		}
		new_node->next = node;
		node->previous = new_node;
	}
}

void	dll_insert_after(t_dll *node, t_dll *new_node)
{
	if (node)
	{
		if (node->next != NULL)
		{
			node->next->previous = new_node;
			new_node->next = node->next;
		}
		else
		{
			node->previous = new_node;
			new_node->next = node;
		}
		new_node->previous = node;
		node->next = new_node;
	}
}

void	dll_debug_node(t_dll *node)
{
	if (node == NULL)
		dprintf(2, "(nil)\n");
	else
		dprintf(2, "DEBUG(node): %p <- %p!!%d -> %p\n",
			node->previous, node, node->flags, node->next);
}

int	dll_add_head(t_dll **node, void *data)
{
	t_dll	*new_node;

	new_node = dll_new(data, 0);
	if (new_node == NULL)
		return (DLL_NOMEMORY);
	if (*node)
	{
		if ((*node)->flags ^ F_NODE_HEAD)
			dll_get_head(node);
		(*node)->flags ^= F_NODE_HEAD;
		dll_insert_before(*node, new_node);
	}
	new_node->flags |= F_NODE_HEAD;
	*node = new_node;
	return (DLL_NOERROR);
}

int	dll_add_tail(t_dll **node, void *data)
{
	t_dll	*new_node;

	new_node = dll_new(data, 0);
	if (new_node == NULL)
		return (DLL_NOMEMORY);
	if (*node)
	{
		if ((*node)->flags ^ F_NODE_HEAD)
			dll_get_head(node);
		dll_insert_before(*node, new_node);
	}
	return (DLL_NOERROR);
}

size_t	dll_size(t_dll *node)
{
	size_t	i;

	i = 1;
	if (node == NULL)
		return (0);
	node = node->next;
	while (node && node->flags ^ F_NODE_HEAD)
	{
		++i;
		node = node->next;
	}
	return (i);
}

void	dll_get_head(t_dll **node)
{
	while ((*node)->flags ^ F_NODE_HEAD)
		(*node) = (*node)->next;
}

void	dll_set_head(t_dll **node)
{
	t_dll	*tmp;

	if (*node == NULL || (*node)->flags & F_NODE_HEAD)
		return ;
	tmp = *node;
	while (tmp->flags ^ F_NODE_HEAD)
		tmp = tmp->next;
	tmp->flags ^= F_NODE_HEAD;
	(*node)->flags |= F_NODE_HEAD;
}

void	dll_iter(t_dll *node, t_data_func f)
{
	f(node->data);
	node = node->next;
	while (node && node->flags ^ F_NODE_HEAD)
	{
		f(node->data);
		node = node->next;
	}
}

void	dll_iter_previous(t_dll *node, t_data_func f)
{
	f(node->data);
	node = node->previous;
	while (node && node->flags ^ F_NODE_HEAD)
	{
		f(node->data);
		node = node->previous;
	}
}

int	dll_iter_n(t_dll *node, size_t n, t_data_func f)
{
	size_t	i;

	i = 0;
	while (node && i < n)
	{
		f(node->data);
		node = node->next;
		++i;
		if (node->flags & F_NODE_HEAD)
			break ;
	}
	return (i);
}

void	dll_delete_node(t_dll *node, t_data_func del)
{
	if (node)
	{
		del(node->data);
		free(node);
	}
}

void	dll_clear(t_dll **node, t_data_func del)
{
	t_dll	*tmp;
	t_dll	*start;

	if (*node == NULL)
		return ;
	start = *node;
	*node = (*node)->next;
	while (*node && (*node)->flags ^ F_NODE_HEAD)
	{
		tmp = (*node)->next;
		dll_delete_node(*node, del);
		*node = tmp;
	}
	dll_delete_node(start, del);
	*node = NULL;
}
