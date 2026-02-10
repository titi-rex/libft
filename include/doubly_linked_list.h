/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalegran <lalegran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:43:09 by lalegran          #+#    #+#             */
/*   Updated: 2025/12/05 13:09:20 by lalegran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

# include <stddef.h>

# define DLL_NOERROR 0
# define DLL_NOMEMORY 1

typedef struct s_doubly_linked_list
{
	void						*data;
	struct s_doubly_linked_list	*next;
	struct s_doubly_linked_list	*previous;
	int							flags;
}	t_dll;

// Flags 
# define F_NODE_HEAD    0b0001
# define F_NODE_TAIL    0b0010
# define F_NODE_TAG     0b0100

typedef void	(*t_node_func)(t_dll *);
typedef void	(*t_data_func)(void *);

t_dll	*dll_new(void *data, int flags);
void	dll_insert_before(t_dll *node, t_dll *new_node);
void	dll_insert_after(t_dll *node, t_dll *new_node);
int		dll_add_head(t_dll **node, void *data);
int		dll_add_tail(t_dll **node, void *data);

size_t	dll_size(t_dll *node);
void	dll_get_head(t_dll **node);
void	dll_set_head(t_dll **node);

void	dll_iter(t_dll *node, t_data_func f);
void	dll_iter_previous(t_dll *node, t_data_func f);

int		dll_iter_n(t_dll *node, size_t n, t_data_func f);

void	dll_delete_node(t_dll *node, t_data_func del);
void	dll_clear(t_dll **node, t_data_func del);

void	dll_debug_node(t_dll *node);

#endif
