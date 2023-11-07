/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:18:17 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/18 23:34:05 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

ssize_t	read_stdin(t_list **lst)
{
	char	buf[BUFF_SIZE + 1];
	ssize_t	nbytes;
	ssize_t	total_size;

	nbytes = read(0, buf, BUFF_SIZE);
	total_size = nbytes;
	(*lst) = ft_create_elem(ft_strdup(buf));
	while (nullification(buf, BUFF_SIZE + 1) && nbytes > 0)
	{
		nbytes = read(0, buf, BUFF_SIZE);
		total_size += nbytes;
		if (!ft_list_push_back(lst, ft_strdup(buf)))
		{
			ft_list_clear(*lst);
			return (0);
		}
	}
	return (total_size);
}

int	bsq_stdin(t_bsq *data)
{
	t_list	*lst;
	char	*multy;
	ssize_t	total_size;

	total_size = read_stdin(&lst);
	multy = malloc((total_size + 1) * (sizeof(char)));
	ft_list_save(lst, multy);
	ft_list_clear(lst);
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
