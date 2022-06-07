/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:25:36 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/07 16:45:03 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<mlx.h>
# include<fcntl.h>
# include<stdlib.h>
# include"libft/libft.h"

typedef struct s_data{
	int		count_c;
	int		count_e;
	int		count_p;
	char	**map;
	int		x_map;
	int		y_map;
	void	*mlx;
	void	*win;
	void	*w_ptr;
	void	*p_ptr;
	void	*lp_ptr;
	void	*c_ptr;
	void	*es_ptr;
	void	*e_ptr;
	int		x_p;
	int		y_p;
	int		x_e;
	int		y_e;
	int		cnt_mvs;
	int		img_high;
	int		img_width;

}	t_data;

char	*get_next_line(int fd);
void	ft_check_middle_lines(char *str);
void	ft_check_line_is_1(char *str);
void	ft_check_map_type(char	*str);
void	ft_map_content(t_data *sd);
int		ft_check_map_walls(t_data *sd);
char	**ft_read_map(char *map);
char	ft_check_map_norm(t_data *sd);
void	ft_check_map(t_data *gm);
void	ft_inisialisation(t_data *sd);
void	ft_lastcheck(t_data	*sd);
void	ft_rander_map(t_data *sd);
void	put_ptr(t_data *sd);
int		key_hook(int key, t_data *sd);
int		ft_move_up(t_data *sd);
int		ft_move_down(t_data *sd);
int		ft_move_right(t_data *sd);
int		ft_move_left(t_data *sd);
int		ft_exit(t_data *sd);
void	ft_rander_map2(t_data *sd, int i, int j);
void	ft_move_up2(t_data	*sd);
void	ft_move_left2(t_data *sd);
void	ft_move_right2(t_data *sd);
void	ft_move_down2(t_data *sd);
void	ft_counte(t_data	*sd);

#endif
