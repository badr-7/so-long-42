/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:06:52 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/07 13:45:46 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_ptr(t_data *sd)
{
	sd->w_ptr = mlx_xpm_file_to_image(sd->mlx, "img/wall.xpm",
			&sd->img_width, &sd->img_high);
	sd->es_ptr = mlx_xpm_file_to_image(sd->mlx, "img/es.xpm",
			&sd->img_width, &sd->img_high);
	sd->c_ptr = mlx_xpm_file_to_image(sd->mlx, "img/egg.xpm",
			&sd->img_width, &sd->img_high);
	sd->p_ptr = mlx_xpm_file_to_image(sd->mlx, "img/p.xpm",
			&sd->img_width, &sd->img_high);
	sd->lp_ptr = mlx_xpm_file_to_image(sd->mlx, "img/lp.xpm",
			&sd->img_width, &sd->img_high);
	sd->e_ptr = mlx_xpm_file_to_image(sd->mlx, "img/ex.xpm",
			&sd->img_width, &sd->img_high);
}

void	ft_rander_map(t_data *sd)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (sd->map[i])
	{
		while (sd->map[i][j])
		{
			if (sd->map[i][j] == '1')
				mlx_put_image_to_window(sd->mlx, sd->win, sd->w_ptr,
					(j * 50), (i * 50));
			if (sd->map[i][j] == '0')
				mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
					(j * 50), (i * 50));
			if (sd->map[i][j] == 'C' || sd->map[i][j] == 'E'
				|| sd->map[i][j] == 'P')
				ft_rander_map2(sd, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	write(1, "\033[0;32m<< Ah Shit, Here We Go Again!! >>\n", 41);
	write(1, "\033[0m", 5);
}

void	ft_rander_map2(t_data *sd, int i, int j)
{
	if (sd->map[i][j] == 'C')
	{
		mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
			(j * 50), (i * 50));
		mlx_put_image_to_window(sd->mlx, sd->win, sd->c_ptr,
			(j * 50), (i * 50));
	}
	if (sd->map[i][j] == 'E')
	{
		sd->x_e = j;
		sd->y_e = i;
		mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
			(j * 50), (i * 50));
		mlx_put_image_to_window(sd->mlx, sd->win, sd->e_ptr,
			(j * 50), (i * 50));
	}
	if (sd->map[i][j] == 'P')
	{
		sd->x_p = j;
		sd->y_p = i;
		mlx_put_image_to_window(sd->mlx, sd->win, sd->es_ptr,
			(j * 50), (i * 50));
		mlx_put_image_to_window(sd->mlx, sd->win, sd->p_ptr,
			(j * 50), (i * 50));
	}
}

int	key_hook(int key, t_data *sd)
{
	static int	i;

	if (key == 2 || key == 124)
		ft_move_right(sd);
	if (key == 13 || key == 126)
		ft_move_up(sd);
	if (key == 1 || key == 125)
		ft_move_down(sd);
	if (key == 0 || key == 123)
		ft_move_left(sd);
	if (key == 53)
		ft_exit(sd);
	i++;
	write(1, "MOVES : ", 8);
	ft_putnbr_fd(i, 1);
	write(1, "\n", 1);
	return (0);
}

int	ft_exit(t_data *sd)
{
	int	i;

	i = 0;
	mlx_destroy_image(sd->mlx, sd->p_ptr);
	mlx_destroy_image(sd->mlx, sd->e_ptr);
	mlx_destroy_image(sd->mlx, sd->es_ptr);
	mlx_destroy_image(sd->mlx, sd->w_ptr);
	mlx_destroy_image(sd->mlx, sd->lp_ptr);
	mlx_destroy_image(sd->mlx, sd->c_ptr);
	mlx_destroy_window(sd->mlx, sd->win);
	while (sd->map[i++])
	{
		free(sd->map[i]);
	}
	free (sd->map);
	write(1, "END\n", 4);
	exit (1);
}
