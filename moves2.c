/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:26:00 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/07 14:26:01 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up2(t_data	*sd)
{
	mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
		(sd->x_p * 50), ((sd->y_p - 1) * 50));
	sd->count_c -= 1;
	sd->map[sd->y_p - 1][sd->x_p] = '0';
	if (sd->count_c == 0)
	{
		mlx_destroy_image(sd->mlx, sd->e_ptr);
		sd->e_ptr = mlx_xpm_file_to_image(sd->mlx, "img/open_ex.xpm",
				&sd->img_width, &sd->img_high);
		mlx_put_image_to_window(sd->mlx, sd->win, sd->e_ptr,
			(sd->x_e * 50), (sd->y_e * 50));
	}
}

void	ft_move_down2(t_data *sd)
{
	mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
		(sd->x_p * 50), ((sd->y_p + 1) * 50));
	sd->count_c -= 1;
	sd->map[sd->y_p + 1][sd->x_p] = '0';
	if (sd->count_c == 0)
	{
		mlx_destroy_image(sd->mlx, sd->e_ptr);
		sd->e_ptr = mlx_xpm_file_to_image(sd->mlx, "img/open_ex.xpm",
				&sd->img_width, &sd->img_high);
		mlx_put_image_to_window(sd->mlx, sd->win, sd->e_ptr,
			(sd->x_e * 50), (sd->y_e * 50));
	}
}

void	ft_move_right2(t_data *sd)
{
	mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
		((sd->x_p + 1) * 50), (sd->y_p * 50));
	sd->count_c -= 1;
	sd->map[sd->y_p][sd->x_p + 1] = '0';
	if (sd->count_c == 0)
	{
		mlx_destroy_image(sd->mlx, sd->e_ptr);
		sd->e_ptr = mlx_xpm_file_to_image(sd->mlx, "img/open_ex.xpm",
				&sd->img_width, &sd->img_high);
		mlx_put_image_to_window(sd->mlx, sd->win, sd->e_ptr,
			(sd->x_e * 50), (sd->y_e * 50));
	}
}

void	ft_move_left2(t_data *sd)
{
	mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
		((sd->x_p - 1) * 50), (sd->y_p * 50));
	sd->count_c -= 1;
	sd->map[sd->y_p][sd->x_p - 1] = '0';
	if (sd->count_c == 0)
	{
		mlx_destroy_image(sd->mlx, sd->e_ptr);
		sd->e_ptr = mlx_xpm_file_to_image(sd->mlx, "img/open_ex.xpm",
				&sd->img_width, &sd->img_high);
		mlx_put_image_to_window(sd->mlx, sd->win, sd->e_ptr,
			(sd->x_e * 50), (sd->y_e * 50));
	}
}
