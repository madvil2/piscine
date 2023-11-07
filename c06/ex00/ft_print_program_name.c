/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:28:26 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/11 13:34:19 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char *av[])
{
	if (ac != 0)
	{
		while (*av[0])
		{
			ft_putchar(*av[0]);
			av[0]++;
		}
		ft_putchar('\n');
	}
	return (0);
}
