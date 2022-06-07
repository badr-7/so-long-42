/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:51:26 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/07 15:45:50 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_inisialisation(t_data *sd)
{
	sd->x_map = 0;
	sd->y_map = 0;
	sd->count_e = 0;
	sd->count_c = 0;
	sd->count_p = 0;
}

void	ft_lastcheck(t_data	*sd)
{
	if (sd->count_c < 1)
	{
		write(1, "there's no collectible\n", 23);
		exit(1);
	}
	if (sd->count_p != 1)
	{
		write(1, "we need one player\n", 19);
		exit(1);
	}
	if (sd->count_e < 1)
	{
		write(1, "there's no exit\n", 16);
		exit(1);
	}
	if (sd->count_e > 2)
	{
		write(1, "to much exits\n", 14);
		exit(1);
	}
}

void	ft_check_map(t_data *gm)
{
	ft_inisialisation(gm);
	ft_check_map_walls(gm);
	ft_check_map_norm(gm);
	ft_map_content(gm);
	ft_counte(gm);
	ft_lastcheck(gm);
}

void	ft_counte(t_data	*sd)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (sd->map[i])
	{
		while (sd->map[i][j] != '\0')
		{
			if (sd->map[i][j] == 'C')
				sd->count_c += 1;
			if (sd->map[i][j] == 'E')
				sd->count_e += 1;
			if (sd->map[i][j] == 'P')
				sd->count_p += 1;
			j++;
		}
		j = 0;
		i++;
	}
}
