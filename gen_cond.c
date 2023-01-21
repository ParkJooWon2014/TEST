/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_cond.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:09:07 by soohkang          #+#    #+#             */
/*   Updated: 2023/01/21 20:21:53 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	__isspace(char c)
{
	char	*str;

	str = " \t\n\v\f\r";
	while (*str)
	{
		if (*str == c)
			return (1);
		str ++;
	}
	return (0);
}

int	__parse(char **ret, char *line)
{
	char	is_word;
	char	*str;
	int		count;

	str = line;
	is_word = 1;
	count = 0;
	while (*str)
	{
		if (!__isspace(*str))
		{
			if (is_word)
				ret[count++] = str;
			is_word = 0;
		}
		else
		{
			*str = '\0';
			is_word = 1;
		}
		str ++;
		if (count >= 4096)
			return (0);
	}
	return (count);
}

int	__atoi(char *str)
{
	long	ret;
	char	is_minus;
	char	*tmp;

	if (!str)
		return (0);
	tmp = str;
	is_minus = 0;
	ret = 0;
	while (*tmp == '-' || *tmp == '+' || __isspace(*tmp))
	{
		if (*tmp++ == '-')
			is_minus = !is_minus;
	}
	while ('0' <= *tmp && *tmp <= '9')
	{
		ret *= 10;
		ret += *tmp - '0';
		tmp ++;
	}
	if (is_minus)
		ret *= -1;
	return (ret);
}

int	**__gen_cond(int **ret, char **words)
{
	int		idx;
	int		i;
	int		j;

	idx = 0;
	while (idx < 16)
	{
		i = idx / 4;
		j = idx % 4;
		if (j == 0)
			ret[i] = (int *)malloc(sizeof(int) * 4);
		ret[i][j] = __atoi(words[idx]);
		if (ret[i][j] < 1 || ret[i][j] > 4)
			return (NULL);
		idx += 1;
	}
	free(words);
	return (ret);
}

int	**gen_cond(char *line)
{
	char	**words;
	int		size;
	int		**ret;
	int		idx ;

	idx = 0;
	words = (char **)malloc(sizeof(*ret) * 4096);
	size = __parse(words, line);
	if (size != 16)
		return (NULL);
	ret = (int **)malloc(sizeof(int) * size);
	return (__gen_cond(ret, words));
}
