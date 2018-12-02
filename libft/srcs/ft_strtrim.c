/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:03:02 by mjacques          #+#    #+#             */
/*   Updated: 2018/08/12 19:11:36 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (ISSPACE(s[i]) && s[i])
		i++;
	j = ft_strlen(s) - 1;
	while (ISSPACE(s[j]) && j != 0)
		j--;
	if ((i == 0 && ft_strlen(s) == 0) || j == 0)
		return ("");
	if (!(str = (char *)malloc(sizeof(char) * (j - i) + 2)))
		return (NULL);
	k = 0;
	while (k <= (j - i))
	{
		str[k] = s[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}
