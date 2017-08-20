/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkieffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 17:34:01 by lkieffer          #+#    #+#             */
/*   Updated: 2017/08/20 00:41:15 by lkieffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		nbword(char *str)
{
	int i;
	int count;
	int check;
	int j;

	i = 0;
	count = 0;
	check = 0;
	j = 0;

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
	tab = (char**)malloc(sizeof(char*) * (nbword(str) + 1));
	if (tab == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == ' '  || str[i] == '\n')
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
	tab[j] = NULL;
	return (tab);
}

void ft_print_words_tables(char **tab)
{
	int j;
	int k;
	int n;

	j = 0;
	k = 0;
	n = '\n';
	while (tab[j])
	{
		while (tab[j][k])
		{
			ft_putchar(tab[j][k]);
			k++;
		}
		ft_putchar(n);
		j++;
	}
}

int		main(void)
{
	char **tab;
	char *str;

	str = "";
	tab = ft_split_whitespaces(str);
	ft_print_words_tables(tab);
	return (0);
}
