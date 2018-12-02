/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:51:21 by mjacques          #+#    #+#             */
/*   Updated: 2018/08/12 19:10:06 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *str, char c)
{
	int		len;
	char	*newstr;

	len = ft_strlen(str);
	newstr = (char *)malloc(sizeof(char) * len + 2);
	ft_strcpy(newstr, str);
	newstr[len] = c;
	newstr[len + 1] = '\0';
	return (newstr);
}
