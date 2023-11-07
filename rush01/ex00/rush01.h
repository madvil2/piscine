/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:34:31 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/08 18:38:34 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# define COMBINATIONS	"123412431324134214231432213421432314234124132431\
312431423214324134123421412341324213423143124321"

# include <unistd.h>

//utils.c
void	ft_putchar(char c);
void	print(int *result[4]);
void	create_comb(int arr[24][4]);
void	get_input(char *av, int arr[16]);

//logic.c
int		brute2(int *result[4], int comb[24][4], int clues[16], int r[4]);
void	brute_force(int *result[4], int comb[24][4], int clues[16]);
int		check(int *arr[4], int clues[16]);
int		count(int a, int b, int c, int d);
int		unic(int *result[4]);

#endif