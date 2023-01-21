/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:58:17 by joowpark          #+#    #+#             */
/*   Updated: 2022/10/11 10:58:19 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	init_dict(int *dict)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		dict[i] = 0;
		i ++;
	}
}

void	__listncpy(int *dst, int *src, int size)
{
	int		*tmp;

	tmp = dst;
	while (size --)
		*tmp ++ = *src ++;
}

void	__is_fine(int *cmd, int *cnt_left, int *cnt_right, int n)
{
	int		idx;
	int		tmp;

	idx = 0;
	tmp = -1;
	while (idx < n)
	{
		if (tmp < cmd[idx])
		{
			tmp = cmd[idx];
			*cnt_left += 1;
		}
		idx ++;
	}
	tmp = -1;
	while (idx--)
	{
		if (tmp < cmd[idx])
		{
			tmp = cmd[idx];
			*cnt_right += 1;
		}
	}
}

int	__fine_row_up(int **matrix, int *dict, int idx)
{
	int		j;
	int		tmp;
	int		cnt_up;

	tmp = 0;
	j = 0;
	cnt_up = 0;
	while (j < 4)
	{
		if (dict[matrix[j][idx]])
			return (-1);
		dict[matrix[j][idx]] = 1;
		if (tmp < matrix[j][idx])
		{
			tmp = matrix[j][idx];
			cnt_up += 1;
		}
		j += 1;
	}
	return (cnt_up);
}

int	__fine_row_down(int **matrix, int idx)
{
	int		j;
	int		tmp;
	int		cnt_down;

	cnt_down = 0;
	tmp = 0;
	j = 4;
	while (j--)
	{
		if (tmp < matrix[j][idx])
		{
			tmp = matrix[j][idx];
			cnt_down += 1;
		}
	}
	return (cnt_down);
}
