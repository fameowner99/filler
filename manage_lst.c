/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:39:31 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/15 15:06:37 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_possible_values		*create_lst_values(t_point p)
{
	t_possible_values	*tmp;

	tmp = (t_possible_values *)malloc(sizeof(t_possible_values));
	tmp->value.x = p.x;
	tmp->value.y = p.y;
	tmp->next = NULL;
	return (tmp);
}

t_possible_values		*push_back_values(t_possible_values *curr, int x, int y)
{
	t_possible_values	*tmp;
	t_possible_values	*curr1;

	curr1 = curr;
	while (curr1->next)
	{
		curr1 = curr1->next;
	}
	tmp = (t_possible_values *)malloc(sizeof(t_possible_values));
	tmp->value.x = x;
	tmp->value.y = y;
	tmp->next = NULL;
	curr1->next = tmp;
	return (curr);
}

void					clear_lst_values(t_possible_values *lst)
{
	t_possible_values	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		lst->value.x = 0;
		lst->value.y = 0;
		lst->next = NULL;
		free(lst);
		lst = tmp;
	}
}
