/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 03:49:22 by pcollio-          #+#    #+#             */
/*   Updated: 2018/08/31 04:02:45 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int temp;

	temp = ***a;
	***a = *b;
	*b = ****d;
	****d = *******c;
	*******c = temp;
}