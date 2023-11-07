/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:18:10 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/18 21:26:41 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	free_tab(void **array, int nb_rows)
{
	int	i;

	i = 0;
	while (i < nb_rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*ft_linecpy(char *dest, char *src, int index, int nb_cols)
{
	int	count;
	int	i;

	count = 0;
	i = index * (nb_cols + 1);
	while (src[i] != '\n' && count < nb_cols)
	{
		dest[count] = src[i];
		count++;
		i++;
	}
	return (dest);
}

char	**init_map(char *str, int nb_rows, int nb_cols)
{
	char	**array;
	int		i;
	int		index;

	array = (char **)malloc(nb_rows * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	index = 0;
	while (i < nb_rows)
	{
		array[i] = (char *)malloc(nb_cols * sizeof(char));
		if (!array[i])
		{
			free_tab((void **)array, i);
			return (NULL);
		}
		ft_linecpy(array[i], str, index, nb_cols);
		i++;
		index++; 
	}
	return (array);
}

int	**init_tab(int nb_rows, int nb_cols)
{
	int	**array;
	int	i;
	int	j;

	array = (int **)malloc(nb_rows * sizeof(int *));
	if (!array)
		return (NULL);
	i = -1; 
	while (++i < nb_rows)
	{
		j = -1;
		array[i] = (int *)malloc(nb_cols * sizeof(int));
		if (!array[i])
		{
			free_tab((void **)array, i);
			return (NULL);
		}
		while (++j < nb_cols)
		{
			if (i == nb_rows - 1 || j == nb_cols - 1)
				array[i][j] = 0;
		}
	}
	return (array);
}
