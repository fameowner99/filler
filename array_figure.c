/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:22:09 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/15 16:14:36 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline void		f(t_list_figure *tmp, t_point *i,
				t_point **size_figure, char **arr)
{
	tmp->p.x = i->x;
	tmp->p.y = i->y;
	if (arr[i->y][i->x] == '.')
		tmp->value = 0;
	else
		tmp->value = 1;
	(*size_figure)->x = i->x;
	(*size_figure)->y = i->y;
	++i->x;
}

t_list_figure			*create_list_figure(char **arr, t_point *size_figure,
				t_list_figure *tmp, t_list_figure *tmp1)
{
	t_point				i;

	i.y = 0;
	while (arr[i.y])
	{
		i.x = 0;
		while (arr[i.y][i.x])
		{
			if (!tmp1)
			{
				tmp1 = (t_list_figure *)malloc(sizeof(t_list_figure));
				tmp = tmp1;
			}
			else
			{
				tmp->next = (t_list_figure *)malloc(sizeof(t_list_figure));
				tmp = tmp->next;
			}
			f(tmp, &i, &size_figure, arr);
		}
		++i.y;
	}
	tmp->next = NULL;
	ft_free_2d((void **)arr);
	return (tmp1);
}

void					clear_list_figure(t_list_figure *lst)
{
	t_list_figure		*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		lst->p.x = 0;
		lst->p.y = 0;
		lst->value = 0;
		lst->next = NULL;
		free(lst);
		lst = tmp;
	}
}

int						check_if_fit(t_map_figure mf, int x, int y, char sign)
{
	int					touch;
	t_list_figure		*tmp;

	touch = 0;
	tmp = mf.figure_coord;
	while (tmp)
	{
		if (touch > 1 || (x + tmp->p.x >= mf.size_map.x) ||
			(y + tmp->p.y >= mf.size_map.y) ||
			(mf.map[y + tmp->p.y][x + tmp->p.x] != '.' &&
			mf.map[y + tmp->p.y][x + tmp->p.x] != sign))
			return (0);
		if (mf.map[y + tmp->p.y][x + tmp->p.x] == sign && tmp->value)
			++touch;
		tmp = tmp->next;
	}
	if (touch != 1)
		return (0);
	return (1);
}

t_possible_values		*find_possible_values(t_map_figure mf)
{
	t_point				i;
	t_possible_values	*value;

	value = NULL;
	i.y = 0;
	while (mf.map[i.y])
	{
		i.x = 0;
		while (mf.map[i.y][i.x])
		{
			if (check_if_fit(mf, i.x, i.y, mf.number_player == 1 ? 'O' : 'X'))
			{
				if (!value)
					value = (t_possible_values *)create_lst_values(i);
				else
					push_back_values(value, i.x, i.y);
			}
			++i.x;
		}
		++i.y;
	}
	return (value);
}
