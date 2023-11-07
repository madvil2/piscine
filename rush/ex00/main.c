/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:05:04 by evan-ite          #+#    #+#             */
/*   Updated: 2023/09/30 17:16:22 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int x, int y);

int	get_number(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i++] - '0');
		else
			return (-1);
	}
	return (result);
}

void	errors(void)
{
	write(1, "Please enter valid arguments (width height)\n", 44);
}

int	main(int ac, char **av)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	if (ac == 3)
	{
		width = get_number(av[1]);
		height = get_number(av[2]);
		if (width > 0 && height > 0)
			rush(width, height);
		else
			errors();
	}
	else
		errors();
	return (0);
}
