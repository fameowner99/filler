/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:28:02 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/15 18:45:01 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int			main(void)
{
	char	*str;
	int		i;

	i = 0;
	while (get_next_line(0, &str))
	{
		i = 4;
		while (ft_strlen(str) > 20 && !ft_strstr(str, "012345678") && str[i])
		{
			if (str[i] == 'X' || str[i] == 'x')
				ft_printf(RED"%C"RESET, 9633);
			else if (str[i] == 'O' || str[i] == 'o')
				ft_printf(GREEN"%C"RESET, 9633);
			else
				ft_printf("%s", ".");
			++i;
		}
		ft_printf("\n");
		free(str);
	}
	return (0);
}
