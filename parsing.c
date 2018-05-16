/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:07:04 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/15 16:25:11 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				get_number_player(void)
{
	char		*str;

	while (get_next_line(0, &str) > 0 && !ft_strstr(str, "$$$"))
	{
	}
	free(str);
	return (str[10] - 48);
}

t_point			get_size_map(void)
{
	char		*str;
	char		**arr;
	t_point		p;

	while (get_next_line(0, &str) > 0 && !ft_strstr(str, "Plateau"))
	{
	}
	arr = ft_strsplit(str, ' ');
	p.y = ft_atoi(arr[1]);
	p.x = ft_atoi(arr[2]);
	ft_free_2d((void **)arr);
	free(str);
	return (p);
}

static t_point	get_num(char *str)
{
	char		**arr;
	t_point		p;

	arr = ft_strsplit(str, ' ');
	p.y = ft_atoi(arr[1]);
	p.x = ft_atoi(arr[2]);
	ft_free_2d((void **)arr);
	return (p);
}

void			get_map_and_figure(t_map_figure *mf, int wrd)
{
	char		*str;
	char		**arr_figure;
	t_point		size_figure;

	while (get_next_line(0, &str) && !ft_strstr(str, "0123456789"))
		free(str);
	while (!ft_strstr(str, "Piece "))
	{
		free(str);
		get_next_line(0, &str);
		mf->map[wrd] = ft_strcpy(mf->map[wrd], str + 4);
		++wrd;
	}
	size_figure = get_num(str);
	free(str);
	arr_figure = (char **)ft_alloc_2d(size_figure.y + 1, size_figure.x + 1);
	wrd = 0;
	while (wrd < size_figure.y && get_next_line(0, &str) > 0)
	{
		arr_figure[wrd] = ft_strcpy(arr_figure[wrd], str);
		free(str);
		++wrd;
	}
	mf->figure_coord = (t_list_figure *)create_list_figure(arr_figure,
				&mf->size_figure, NULL, NULL);
}
