/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:04:22 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/15 16:25:25 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					main(void)
{
	t_map_figure		mf;
	t_possible_values	*all_values;

	mf.number_player = get_number_player();
	mf.size_map = get_size_map();
	mf.map = (char **)ft_alloc_2d(mf.size_map.y + 1, mf.size_map.x + 1);
	mf.heat_map = (int **)ft_alloc_2d_int(mf.size_map.y + 1, mf.size_map.x + 1);
	while (1)
	{
		get_map_and_figure(&mf, 0);
		init_heat_map(&mf, mf.number_player == 1 ? 'X' : 'O');
		all_values = find_possible_values(mf);
		answer(find_best_point(mf, all_values));
		clear_list_figure(mf.figure_coord);
		clear_lst_values(all_values);
	}
	return (0);
}
