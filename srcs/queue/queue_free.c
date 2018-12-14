/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:55:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/13 20:55:22 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdlib.h>

void		queue_free(t_queue *q)
{
	t_queue_node *cur;
	t_queue_node *next;

	cur = q->first;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(q);
}
