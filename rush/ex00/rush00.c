/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:15:47 by kokaimov          #+#    #+#             */
/*   Updated: 2023/09/30 15:46:57 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	display_width(int x, char symbol)
{
	int	width;

	width = 0;
	while (width < (x - 2))
	{
		ft_putchar(symbol);
		width++;
	}
}

void	display_line(char left_char, char right_char, char filling, int x)
{
	if (x < 2)
		ft_putchar(left_char);
	else
	{
		ft_putchar(left_char);
		display_width(x, filling);
		ft_putchar(right_char);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	height;

	height = 1;
	while (height <= y)
	{
		if (height == 1)
			display_line('o', 'o', '-', x);
		else if (height == y)
			display_line('o', 'o', '-', x);
		else
			display_line('|', '|', ' ', x);
		height++;
	}
}
