/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:06:19 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/18 21:26:41 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*parse_map(char *file)
{
	char		*res;
	char		buf[BUFF_SIZE + 1];
	int			fd;
	ssize_t		nbytes;
	ssize_t		size;

	fd = open(file, O_RDONLY);
	size = 0;
	nbytes = read(fd, buf, BUFF_SIZE);
	while (nbytes > 0)
	{
		size += nbytes;
		nbytes = read(fd, buf, BUFF_SIZE);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	read(fd, res, size);
	res[size] = 0;
	close(fd);
	return (res);
}

int	bsq_main(char *multy, t_bsq data)
{
	int	**tab;

	data.map = init_map(multy, data.y, data.x);
	if (!data.map)
		return (0);
	tab = init_tab(data.y + 1, data.x + 1);
	if (!tab)
		return (0);
	bsq_solve(data.map, tab, &data);
	free_tab((void **)tab, data.y + 1);
	print_solution(data.map, data);
	free_tab((void **)data.map, data.y);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	char	*multy;
	t_bsq	data;

	if (ac == 1)
		bsq_stdin(&data);
	i = 1;
	while (i < ac)
	{
		data.save = NULL;
		multy = parse_map(av[i]);
		if (!multy || !check_input(&multy, &data))
			print_error();
		else
		{
			if (!bsq_main(multy, data))
				print_error();
		}
		if (ac > 2)
			ft_putchar('\n');
		i++;
		free(data.save);
	}
}
