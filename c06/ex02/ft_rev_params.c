/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:28:53 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/11 13:36:05 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char *av[])
{
	int	j;

	j = 0;
	while (ac--)
	{
		if (ac != 0)
		{
			while (av[ac][j] != '\0')
				ft_putchar(av[ac][j++]);
			j = 0;
			ft_putchar('\n');
		}
	}
	return (0);
}
