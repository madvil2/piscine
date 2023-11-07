/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:57:27 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/05 18:59:20 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i) && i < n - 1)
		i++;
	if (n)
		return (*(s1 + i) - *(s2 + i));
	return (0);
}