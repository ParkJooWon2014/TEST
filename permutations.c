/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:45:52 by joowpark          #+#    #+#             */
/*   Updated: 2022/10/10 17:31:41 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*__listdup(int *src, unsigned int size)
{
	int		*ret;
	int		*tmp;
	int		idx;

	idx = 0;
	ret = (int *)malloc(sizeof(*ret) * (size));
	ret[size] = '\0';
	tmp = ret;
	while (size --)
	{
		*tmp++ = *src++;
	}
	return (ret);
}

int	is_in_str(int *str, int depth, int num)
{
	int		*dst;

	dst = str + depth;
	while (str < dst)
	{
		if (*str == num)
			return (1);
		str ++;
	}
	return (0);
}

void	gen_permutations(int **ret, int *idx, int depth, int *str)
{
	int		num;

	num = 0;
	if (depth == 4)
	{
		ret[*idx] = __listdup(str, 5);
		*idx += 1;
		return ;
	}
	while (num++ < 4)
	{
		if (is_in_str(str, depth, num))
			continue ;
		str[depth] = num;
		gen_permutations(ret, idx, depth + 1, str);
	}
}

int	**permutations(void)
{
	int			idx;
	int			str[9];
	int			**ret;

	idx = 0;
	while (idx < 10)
		str[idx++] = 0;
	idx = 0;
	ret = (int **)malloc(sizeof(*ret) * 24);
	gen_permutations(ret, &idx, 0, str);
	return (ret);
}
/*
#include<stdio.h>
int main()
{
	int **matrix = permutations();
	for(int i = 0 ; i < 24 ; i++){
		for(int j = 0 ; j < 4; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return (0);
}*/
