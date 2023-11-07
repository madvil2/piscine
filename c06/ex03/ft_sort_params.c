/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:29:00 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/10 19:59:38 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	bubble_sort(char *strs[], int n)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (ft_strcmp(strs[j], strs[j + 1]) > 0)
			{
				temp = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	bubble_sort(av + 1, ac - 1);
	while (i < ac)
	{
		while (av[i][j] != '\0')
			ft_putchar(av[i][j++]);
		i++;
		j = 0;
		ft_putchar('\n');
	}
	return (0);
}
