/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:26:29 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/07 14:27:03 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_up(t_data *sd)
{
	if (sd->map[sd->y_p - 1][sd->x_p] != '1')
	{
		if (sd->map[sd->y_p - 1][sd->x_p] == 'C')
			ft_move_up2(sd);
		mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
			(sd->x_p * 50), (sd->y_p * 50));
		sd->y_p -= 1;
		mlx_put_image_to_window(sd->mlx, sd->win, sd->p_ptr,
			(sd->x_p * 50), (sd->y_p * 50));
		if (sd->map[sd->y_p + 1][sd->x_p] == 'E')
			mlx_put_image_to_window(sd->mlx, sd->win, sd->e_ptr,
				(sd->x_e * 50), (sd->y_e * 50));
		if (sd->map[sd->y_p][sd->x_p] == 'E' && sd->count_c == 0)
		{
			write(1, "\033[0;32m<<< CONGRATULATION YOU WON!! >>>\n\033[0m", 45);
			ft_exit(sd);
		}
	}
	return (0);
}

int	ft_move_down(t_data *sd)
{
	if (sd->map[sd->y_p + 1][sd->x_p] != '1')
	{
		if (sd->map[sd->y_p + 1][sd->x_p] == 'C')
			ft_move_down2(sd);
		mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
			(sd->x_p * 50), (sd->y_p * 50));
		sd->y_p += 1;
		mlx_put_image_to_window(sd->mlx, sd->win, sd->p_ptr,
			(sd->x_p * 50), (sd->y_p * 50));
		if (sd->map[sd->y_p - 1][sd->x_p] == 'E')
			mlx_put_image_to_window(sd->mlx, sd->win, sd->e_ptr,
				(sd->x_e * 50), (sd->y_e * 50));
		if (sd->map[sd->y_p][sd->x_p] == 'E' && sd->count_c == 0)
		{
			write(1, "\033[0;32m<<< CONGRATULATION YOU WON!! >>>\n\033[0m", 45);
			ft_exit(sd);
		}
	}
	return (0);
}

int	ft_move_right(t_data *sd)
{
	if (sd->map[sd->y_p][sd->x_p + 1] != '1')
	{
		if (sd->map[sd->y_p][sd->x_p + 1] == 'C')
			ft_move_right2(sd);
		mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
			(sd->x_p * 50), (sd->y_p * 50));
		sd->x_p += 1;
		mlx_put_image_to_window(sd->mlx, sd->win, sd->p_ptr,
			(sd->x_p * 50), (sd->y_p * 50));
		if (sd->map[sd->y_p][sd->x_p - 1] == 'E')
			mlx_put_image_to_window(sd->mlx, sd->win, sd->e_ptr,
				(sd->x_e * 50), (sd->y_e * 50));
		if (sd->map[sd->y_p][sd->x_p] == 'E' && sd->count_c == 0)
		{
			write(1, "\033[0;32m<<< CONGRATULATION YOU WON!! >>>\n\033[0m", 45);
			ft_exit(sd);
		}
	}
	return (0);
}

int	ft_move_left(t_data *sd)
{
	if (sd->map[sd->y_p][sd->x_p - 1] != '1')
	{
		if (sd->map[sd->y_p][sd->x_p - 1] == 'C')
			ft_move_left(sd);
		mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
			(sd->x_p * 50), (sd->y_p * 50));
		sd->x_p -= 1;
		mlx_put_image_to_window(sd->mlx, sd->win, sd->lp_ptr,
			(sd->x_p * 50), (sd->y_p * 50));
		if (sd->map[sd->y_p][sd->x_p + 1] == 'E')
			mlx_put_image_to_window(sd->mlx, sd->win, sd->e_ptr,
				(sd->x_e * 50), (sd->y_e * 50));
		if (sd->map[sd->y_p][sd->x_p] == 'E' && sd->count_c == 0)
		{
			write(1, "\033[0;32m<<< CONGRATULATION YOU WON!! >>>\n\033[0m", 45);
			ft_exit(sd);
		}
	}
	return (0);
}
