/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:32:12 by kokaimov          #+#    #+#             */
/*   Updated: 2023/10/18 23:33:39 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res || !data)
		return (NULL);
	res->data = data;
	res->next = NULL;
	return (res);
}

int	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*curr;

	new = ft_create_elem(data);
	if (!new)
		return (0);
	if (!(*begin_list))
		(*begin_list) = new;
	else
	{
		curr = *begin_list;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	return (1);
}

void	ft_list_clear(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->data);
		free(tmp);
	}
}

void	ft_list_save(t_list *lst, char *multy)
{
	char	*current_pos;

	current_pos = multy;
	while (lst)
	{
		ft_strcpy(current_pos, lst->data);
		current_pos += ft_strlen(lst->data);
		lst = lst->next;
	}
	*current_pos = '\0';
}
