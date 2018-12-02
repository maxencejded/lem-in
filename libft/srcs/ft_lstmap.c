/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 18:33:31 by mjacques          #+#    #+#             */
/*   Updated: 2018/08/12 19:09:11 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	newlist = tmp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if ((tmp->next = f(lst)) == NULL)
		{
			free(tmp->next);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (newlist);
}
