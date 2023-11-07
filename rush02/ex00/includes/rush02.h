/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:47:46 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/15 21:06:57 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE	20

// init.c
char	**dict_create(char **arr);
char	*find_value(char **arr, int key, int flag);
char	*save_value(char *str);
int		is_suff(char *str, int power);

// main.c
int		main(int ac, char **av);

// prints.c
void	if_zero(char **dict);
void	print_hundreds(char a, char b, char c, char **dict);
void	print_reminder(char *nb, char **dict, int len, int *i);
void	print(char *str, char **dict);

// split.c
int		check_symb(char c, char *sep);
int		str_count(char *str, char *sep);
int		len_count(char *str, char *sep, int n);
char	*string_save(char *str, char *sep, int n);
char	**ft_split(char *str, char *charset);

// utils-1.c
int		error_print(int error);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		fill_zero(char *str, int size);
int		check_input(char **str);

// utils-2.c
void	*free_arr(char **arr, int size, int flag);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif