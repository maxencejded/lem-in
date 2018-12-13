/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:59:12 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 13:24:55 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "libft.h"

int	queue_add(t_queue **q, void *data)
{
	t_queue_node	*node;

	MCK(node = queue_new_node(data), 1);
	node->data = data;
	if (*q == NULL)
	{
		MCK(*q = queue_new(), 1);
		(*q)->first = node;
		(*q)->last = node;
	}
	else if ((*q)->first == NULL)
	{
		(*q)->first = node;
		(*q)->last = node;
	}
	else
	{
		(*q)->last->next = node;
		(*q)->last = node;
	}
	return (0);
}
