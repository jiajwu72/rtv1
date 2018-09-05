/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:34:46 by klin              #+#    #+#             */
/*   Updated: 2017/11/16 13:49:26 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tab_size(char const *str)
{
	int size;
	int word;
	int i;

	size = 0;
	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && word != 1)
		{
			word = 1;
			size++;
		}
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			word = 0;
		i++;
	}
	return (size);
}

static int	ft_word_position(int i, char const *str, int *wordsize)
{
	int word;
	int position;

	word = 0;
	position = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && word != 1)
		{
			word = 1;
			position = i;
			while (str[i] != ' ' && str[i] != '\t' &&
					str[i] != '\n' && str[i] != '\0')
				i++;
			*wordsize = i - position;
			break ;
		}
		i++;
	}
	return (position);
}

char		**ft_strsplit_whitespace(char const *str)
{
	int		i[2];
	int		tab_size;
	int		wordsize;
	char	**tab;
	int		word_position;

	if (!str)
		return (NULL);
	i[0] = 0;
	word_position = 0;
	tab_size = ft_tab_size(str);
	if (!(tab = (char**)malloc(sizeof(char*) * tab_size + 1)))
		return (NULL);
	while (i[0] < tab_size)
	{
		i[1] = 0;
		word_position = ft_word_position(word_position, str, &wordsize);
		if (!(tab[i[0]] = (char*)malloc(sizeof(char) * (wordsize + 1))))
			return (NULL);
		while (i[1] < wordsize)
			tab[i[0]][(i[1])++] = str[word_position++];
		tab[(i[0])++][(i[1])] = '\0';
	}
	tab[tab_size] = 0;
	return (tab);
}
