/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:52:30 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 12:54:48 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "libft.h"
#include <unistd.h>

t_queue_node	*queue_new_node(void *data)
{
	t_queue_node	*node;

	MCK(node = (t_queue_node*)malloc(sizeof(t_queue_node)), NULL);
	node->next = NULL;
	node->data = data;
	return (node);
}

t_queue			*queue_new(void)
{
	t_queue	*q;

	MCK(q = (t_queue*)malloc(sizeof(t_queue)), NULL);
	q->first = NULL;
	q->last = NULL;
	return (q);
}
