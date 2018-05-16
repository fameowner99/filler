/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 20:00:55 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/15 18:29:16 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft/libft.h"

# include <unistd.h>

typedef struct					s_point
{
	int							x;
	int							y;
}								t_point;

typedef struct					s_list_figure
{
	t_point						p;
	int							value;
	struct s_list_figure		*next;
}								t_list_figure;

typedef struct					s_limit
{
	t_point						min;
	t_point						max;
}								t_limit;
typedef struct					s_map_figure
{
	char						**map;
	t_point						size_map;
	t_limit						limit;
	t_point						size_figure;
	t_list_figure				*figure_coord;
	int							**heat_map;
	int							number_player;
}								t_map_figure;

typedef struct					s_possible_values
{
	t_point						value;
	struct s_possible_values	*next;
}								t_possible_values;

t_point							get_size_map();
int								get_number_player();
void							get_map_and_figure(t_map_figure *mf, int wrd);
t_list_figure					*create_list_figure(char **figure,
			t_point *size_figure, t_list_figure *tmp, t_list_figure *tmp1);
int								count_figure(char **figure);
void							clear_list_figure(t_list_figure	*lst);
t_point							size_of_figure(t_list_figure *lst);
t_possible_values				*create_lst_values(t_point p);
t_possible_values				*push_back_values(t_possible_values *curr,
			int x, int y);
int								check_if_fit(t_map_figure mf,
			int x, int y, char sign);
t_possible_values				*find_possible_values(t_map_figure mf);
void							clear_lst_values(t_possible_values *lst);
void							answer(t_point value);
t_point							find_best_point(t_map_figure mf,
			t_possible_values *pos);
void							init_heat_map(t_map_figure *mf, char enemy);

#endif
