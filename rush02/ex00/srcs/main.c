/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:48:10 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/15 19:48:10 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	main(int ac, char **av)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	char	*multy;

	if (ac > 3 || ac <= 1) //check for the number of arguments
		return (error_print(1));
	if (check_input(&(av[ac - 1])) != 0) // check if input is valid
		return (error_print(check_input(&(av[ac - 1]))));
	if (ac == 2) //open a dictionary
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(av[1], O_RDONLY);
	if (fd == -1) //case  where we cannot open a dictionary
		return (error_print(2));
	multy = NULL;
	while (fill_zero(buf, BUFF_SIZE + 1) && read(fd, buf, BUFF_SIZE) != 0) // reading a BUFF_SIZE characters from a dictionary into a buffer
	{
		temp = multy;
		multy = ft_strjoin(multy, buf); // concatenate result with new portion
		if (!multy)
			return (error_print(2));
		free(temp); // free the old result
	}
	print(av[ac - 1], dict_create(ft_split(multy, "\n"))); //split a dictionary into 2D array, create a new "pretty" version and pass it to the printing function
}
