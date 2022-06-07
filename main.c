/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:26:24 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/07 16:52:57 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char	**av)
{
	t_data	game;

	if (ac != 2)
		return (write(1, "\033[0;31mError : map not found\n", 29), 0);
	ft_check_map_type(av[1]);
	game.map = ft_read_map(av[1]);
	ft_check_map(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (game.x_map * 50),
			(game.y_map * 50), "so_long");
	put_ptr(&game);
	ft_rander_map(&game);
	mlx_hook(game.win, 2, 1L << 1, key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_exit, &game);
	mlx_loop(game.mlx);
}
