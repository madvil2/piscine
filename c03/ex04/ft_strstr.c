/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:57:51 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/06 22:07:31 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	counter;

	counter = 0;
	while (*str++ != '\0')
		counter++;
	return (counter);
}

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

char	*ft_strstr(char *str, char *to_find) // "12345test123" "test" 4
{
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (ft_strncmp(str, to_find, ft_strlen(to_find)) != 0)
			str++;
		else
			return (str);
	}
	return (0);
}
