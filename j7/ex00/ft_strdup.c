/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkieffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 19:04:06 by lkieffer          #+#    #+#             */
/*   Updated: 2017/08/17 20:22:27 by lkieffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] > 0)
		i++;
	str = (char *)malloc(sizeof(*src) * (i + 1));
	while (src[j] > 0)
	{
		str[j] = src[j];
		j++;
	}
	str[i] = 0;
	return (str);
}
