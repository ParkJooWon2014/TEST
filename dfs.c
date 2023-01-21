/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:31:13 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/21 20:17:44 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	init_dict(int *dict);
void	__listncpy(int *dst, int *src, int size);
int		**permutations(void);
void	__is_fine(int *cmd, int *cnt_left, int *cnt_right, int n);
int		__fine_row_up(int **matrix, int *dict, int idx);
int		__fine_row_down(int **matrix, int idx);

int	is_fine_col(int *cmd, char left, char right, int n)
{
	int		cnt_left;
	int		cnt_right;
	int		tmp;
	int		idx;

	tmp = 0;
	cnt_left = 0;
	cnt_right = 0;
	idx = 0;
	__is_fine(cmd, &cnt_left, &cnt_right, n);
	if (left != cnt_left || right != cnt_right)
		return (0);
	return (1);
}

int	__is_fine_row(int **matrix, int **cond, int *dict, int idx)
{
	int		tmp ;
	int		j;
	int		cnt_down;
	int		cnt_up;

	tmp = 0;
	j = 0;
	cnt_up = __fine_row_up(matrix, dict, idx);
	cnt_down = __fine_row_down(matrix, idx);
	if (cnt_up != cond[0][idx] || cnt_down != cond[1][idx])
	{
		return (1);
	}
	return (0);
}

int	is_fine_row(int **matrix, int **cond, int n)
{
	int		dict[5];
	int		idx;
	int		tmp;

	tmp = 0;
	idx = 0;
	while (idx < n)
	{
		init_dict(dict);
		if (__is_fine_row(matrix, cond, dict, idx))
			return (0);
		idx += 1;
	}
	return (1);
}

void	__dfs(int **matrix, int depth, int **cond, char *result, int **cmd)
{
	int		i;
	int		j;

	if (*result)
		return ;
	if (depth == 4)
	{
		if (is_fine_row(matrix, cond, 4))
			*result = 1;
		return ;
	}
	i = 0;
	while (i < 24)
	{
		j = 0;
		if (is_fine_col(cmd[i], cond[2][depth], cond[3][depth], 4) && !*result)
		{
			__listncpy(matrix[depth], cmd[i], 4);
			__dfs(matrix, depth + 1, cond, result, cmd);
		}
		i ++;
	}
}

int	**dfs(int **cond)
{
	int			**ret;
	int			idx;
	char		result;
	int			**cmd;

	cmd = permutations();
	result = 0;
	idx = 0;
	ret = (int **)malloc(sizeof(*ret) * 4);
	while (idx < 4)
	{
		ret[idx++] = (int *)malloc(sizeof(int) * 4);
	}
	__dfs(ret, 0, cond, &result, cmd);
	if (!result)
	{
		while (idx--)
		{
			free(ret[idx]);
		}
		free(ret);
		return (NULL);
	}
	idx = 0;
	while (idx < 4)
		free(cmd[idx++]);
	free(cmd);
	return (ret);
}
