/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:11:07 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/15 15:02:07 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		fill_heat_map(t_map_figure *mf, int x, int y, int level)
{
	if (mf->heat_map[y][x] == 0)
	{
		if (level == 0)
			--level;
		if ((x + 1 < mf->size_map.x && mf->heat_map[y][x + 1] == level) ||
			(y + 1 < mf->size_map.y && mf->heat_map[y + 1][x] == level) ||
			(x - 1 > 0 && mf->heat_map[y][x - 1] == level) ||
			(y - 1 > 0 && mf->heat_map[y - 1][x] == level) ||
			(y + 1 < mf->size_map.y && x + 1 < mf->size_map.x &&
			mf->heat_map[y + 1][x + 1] == level) ||
			(y + 1 < mf->size_map.y && x - 1 > 0 &&
			mf->heat_map[y + 1][x - 1] == level) ||
			(y - 1 > 0 && x - 1 > 0 && mf->heat_map[y - 1][x - 1] == level) ||
			(y - 1 > 0 && x + 1 < mf->size_map.x
			&& mf->heat_map[y - 1][x + 1] == level))
		{
			if (level == -1)
				mf->heat_map[y][x] = 1;
			else
				mf->heat_map[y][x] = level + 1;
		}
	}
}

static void		create_heat_map(t_map_figure *mf)
{
	int			y;
	int			x;
	int			i;
	int			j;

	j = mf->size_map.y > mf->size_map.x ? mf->size_map.y : mf->size_map.x;
	i = 0;
	while (i < j)
	{
		y = 0;
		while (mf->map[y])
		{
			x = 0;
			while (mf->map[y][x])
			{
				fill_heat_map(mf, x, y, i);
				++x;
			}
			++y;
		}
		++i;
	}
}

void			init_heat_map(t_map_figure *mf, char enemy)
{
	int			y;
	int			x;

	y = 0;
	while (y < mf->size_map.y)
	{
		x = 0;
		while (x < mf->size_map.x)
		{
			if (mf->map[y][x] == enemy)
				mf->heat_map[y][x] = -1;
			else if (mf->map[y][x] != '.')
				mf->heat_map[y][x] = -2;
			else
				mf->heat_map[y][x] = 0;
			++x;
		}
		++y;
	}
	create_heat_map(mf);
}
