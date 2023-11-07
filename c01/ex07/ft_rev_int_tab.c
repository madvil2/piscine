/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:21:35 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/02 20:53:20 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	temp;

	temp = 0;
	start = 0;
	while (start < size / 2)
	{
		temp = tab[start];
		tab[start] = tab[size - 1 - start];
		tab[size - 1 - start] = temp;
		start++;
	}
}
