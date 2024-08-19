/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:28:25 by vpelc             #+#    #+#             */
/*   Updated: 2024/07/01 20:04:25 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_nbrstr(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i + 1] == c || str[i + 1] == '\0') && str[i] != c)
			j++;
		i++;
	}
	return (j);
}

static	void	ft_putstr_split(char *split, char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
	{
		split[i] = str[i];
		i++;
	}
	split[i] = '\0';
}

static	int	ft_put_in_split(char **split, char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j])
				j++;
			split[k] = malloc(sizeof(char) * j + 1);
			if (!split[k])
				return (0);
			ft_putstr_split(split[k], str + i, c);
			i += j;
			k++;
		}
	}
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	size_t	size;
	int		k;

	if (!str)
		return (0);
	size = ft_nbrstr(str, c);
	split = malloc((size + 1) * sizeof(char *));
	if (!split)
		return (0);
	k = ft_put_in_split(split, str, c);
	if (k == 0)
	{
		while (split[k])
		{
			free(split[k]);
			k++;
		}
		free(split);
		return (0);
	}
	split[size] = 0;
	return (split);
}
