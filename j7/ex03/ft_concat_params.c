/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkieffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:03:05 by lkieffer          #+#    #+#             */
/*   Updated: 2017/08/18 14:23:15 by lkieffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int taille;

	taille = 0;
	while (*(str + taille) > 0)
		taille++;
	return (taille);
}

int			ft_strlen_totale(char *argv[])
{
	int i;
	int taille_totale;

	i = 1;
	taille_totale = 0;
	while (argv[i] != 0)
	{
		taille_totale += ft_strlen(argv[i]);
		i++;
	}
	return (taille_totale);
}

char		*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen_totale(argv) + argc);
	while (argv[i] != 0)
	{
		while (argv[i][j] != 0)
		{
			str += argv[i][j];
			j++;
		}
		i++;
		str += '\n';
	}
	str += '\n';
	return (str);
}
