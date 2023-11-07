/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:07:19 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/18 23:32:58 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 1000000

typedef struct s_bsq
{
	char	**map;
	char	charset[3];
	int		x;
	int		y;
	int		x_start;
	int		y_start;
	int		max;
	char	*save;
}				t_bsq;

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

int		min(int a, int b, int c);
void	bsq_solve(char **map, int **tab, t_bsq *data);

char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
ssize_t	read_stdin(t_list **lst);
int		bsq_stdin(t_bsq *data);

void	free_tab(void **array, int nb_rows);
char	*ft_linecpy(char *dest, char *src, int index, int nb_cols);
char	**init_map(char *str, int nb_rows, int nb_cols);
int		**init_tab(int nb_rows, int nb_cols);

char	*parse_map(char *file);
int		bsq_main(char *multy, t_bsq data);
int		main(int ac, char **av);

int		print_error(void);
int		ft_strlen(char *str);
int		nullification(char *str, int size);
void	ft_putchar(char c);
void	print_solution(char **map, t_bsq data);

int		check_charset(char *charset, char **str);
int		check_lines_count(char **str);
int		check_rows(char **str, t_bsq *data);
int		check_input(char **str, t_bsq *data);

t_list	*ft_create_elem(void *data);
int		ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_clear(t_list *lst);
void	ft_list_save(t_list *lst, char *multy);

#endif