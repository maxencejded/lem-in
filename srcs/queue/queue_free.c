/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:55:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 12:58:38 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdlib.h>

static void	default_del(void *d)
{
	free(d);
}

void		queue_free(t_queue *q, t_queue_del_fn del)
{
	t_queue_node *cur;
	t_queue_node *next;

	if (del == NULL)
		del = default_del;
	cur = q->first;
	while (cur)
	{
		next = cur->next;
		del(cur->data);
		free(cur);
		cur = next;
	}
}
