/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:22:05 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/15 15:28:39 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void					answer(t_point p)
{
	ft_putnbr(p.y);
	write(1, " ", 1);
	ft_putnbr(p.x);
	write(1, "\n", 1);
}

static void				end(t_map_figure *mf, t_possible_values *pos)
{
	ft_putnbr(0);
	write(1, " ", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	clear_list_figure(mf->figure_coord);
	clear_lst_values(pos);
	ft_free_2d((void **)mf->map);
	ft_free_2d_int((void **)mf->heat_map, mf->size_map.y);
	exit(666);
}

static inline void		f(int *min_sum, int cur_sum,
				t_point *min_point, t_possible_values *pos)
{
	if (*min_sum > cur_sum)
	{
		*min_sum = cur_sum;
		*min_point = pos->value;
	}
}

t_point					find_best_point(t_map_figure mf, t_possible_values *pos)
{
	t_list_figure		*fig;
	int					cur_sum;
	int					min_sum;
	t_point				min_point;

	if (!pos)
		end(&mf, pos);
	min_sum = 99999;
	min_point = pos->value;
	while (pos)
	{
		fig = mf.figure_coord;
		cur_sum = 0;
		while (fig)
		{
			if (fig->value)
				cur_sum += mf.heat_map[fig->p.y
						+ pos->value.y][fig->p.x + pos->value.x];
			fig = fig->next;
		}
		f(&min_sum, cur_sum, &min_point, pos);
		pos = pos->next;
	}
	return (min_point);
}
