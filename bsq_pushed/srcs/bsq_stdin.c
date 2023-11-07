/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:18:17 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/18 21:26:41 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;

	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (*s1)
			res[i++] = *s1++;
	}
	while (*s2)
		res[i++] = *s2++;
	res[i] = 0;
	return (res);
}

int	bsq_stdin(t_bsq *data)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	char	*multy;

	multy = NULL;
	while (nullification(buf, BUFF_SIZE + 1) && read(0, buf, BUFF_SIZE) != 0)
	{
		temp = multy;
		multy = ft_strjoin(multy, buf);
		if (!multy)
			return (print_error());
		free(temp);
	}
	if (!multy || !check_input(&multy, data))
		print_error();
	else
	{
		if (!bsq_main(multy, *data))
			return (print_error());
	}
	free(data->save);
	return (0);
}
