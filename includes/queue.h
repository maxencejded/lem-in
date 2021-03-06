/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:41:49 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/13 15:47:45 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# define MCK(addr, ret) if (!(addr)) return (ret)

typedef struct	s_queue_node
{
	void				*data;
	struct s_queue_node	*next;
}				t_queue_node;

typedef struct	s_queue
{
	t_queue_node	*first;
	t_queue_node	*last;
}				t_queue;

t_queue_node	*queue_new_node(void *data);
t_queue			*queue_new(void);
void			queue_free(t_queue *q);
int				queue_add(t_queue **q, void *data);
void			*queue_pop(t_queue *q);

#endif
