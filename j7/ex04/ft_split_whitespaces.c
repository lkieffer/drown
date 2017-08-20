/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkieffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 17:34:01 by lkieffer          #+#    #+#             */
/*   Updated: 2017/08/20 04:37:32 by lkieffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		fcknorme(char *str, int count, int check, int j)
{
	int i;

	i = 0;
	while (str[j])
		j++;
	if (!str)
		return (0);
	while (i < j)
	{
		while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
		{
			i++;
			check = 1;
		}
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == 0)
		{
			count += (check == 1) ? 1 : 0;
			check = 0;
			i++;
		}
	}
	return (count);
}

int		nbword(char *str)
{
	int count;
	int check;
	int j;

	count = 0;
	check = 0;
	j = 0;
	return (fcknorme(str, count, check, j));
}

int		ft_strlen(char *str, int i)
{
	int count;

	count = 0;
	while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	if ((tab = (char**)malloc(sizeof(char*) * (nbword(str) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
			i++;
		if (str[i])
		{
			tab[j] = (char*)malloc(sizeof(char) * ft_strlen(str, i) + 1);
			if (tab[j] == NULL)
				return (NULL);
			while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
				tab[j][k++] = str[i++];
			tab[j++][k] = 0;
		}
	}
	return (tab[j] = NULL) ? tab : tab;
}
