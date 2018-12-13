/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:02:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 13:20:14 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdlib.h>

void	*queue_pop(t_queue *q)
{
	t_queue_node	*node;
	void			*ret;

	if ((node = q->first) == NULL)
		return (NULL);
	ret = node->data;
	q->first = q->first->next;
	if (q->first == NULL)
		q->last = NULL;
	free(node);
	return (ret);
}
