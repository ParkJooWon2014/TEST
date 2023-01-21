/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:06:31 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/21 20:25:56 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		**gen_cond(char *line);
int		**dfs(int **cond);

void	error_print(void)
{
	write(2, "Error\n", 6);
}

void	__putc(char ch)
{
	write(1, &ch, 1);
}

void	print_matrix(int **matrix)
{
	int		idx;
	int		i;
	int		j;

	idx = 0;
	while (idx < 16)
	{
		i = idx / 4;
		j = idx % 4;
		__putc(matrix[i][j] + '0');
		if (j == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		idx ++;
	}
}

void	free_matrix(int **matrix)
{
	int		idx;

	idx = 0;
	while (idx < 4)
	{
		free(matrix[idx++]);
		idx++;
	}
	free(matrix);
}

int	main(int argc, char *argv[])
{
	int		**cond;
	int		**matrix;

	if (argc == 2)
	{
		cond = gen_cond(argv[1]);
		if (!cond)
		{
			error_print();
			return (0);
		}
		matrix = dfs(cond);
		if (matrix)
		{
			print_matrix(matrix);
			free_matrix(matrix);
		}
		else
			error_print();
		free(cond);
	}
	else
	{
		write(2, "Error\n", 6);
	}
	return (0);
}
