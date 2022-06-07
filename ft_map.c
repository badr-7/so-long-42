/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:05:50 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/07 17:05:07 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "so_long.h"

void	ft_check_map_type(char	*str)
{
	int		i;
	char	*d;
	int		a;
	int		s;

	d = ".ber";
	i = 0;
	s = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '.')
			break ;
		i++;	
	}
	if(ft_strlen(&str[i]) > 4)
		ft_check_map_type(&str[++i]);
	while (str[i] != '\0')
	{
		a = (str[i++] - d[s++]);
		if (a == 0 && str[i] == '\0')
			break ;
		if (a != 0)
		{
			write(1, "\033[0;31mthe map should be \".ber\"", 31);
			exit(1);
		}
	}
}

void	ft_map_content(t_data *sd)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (sd->map[i])
	{
		while (sd->map[i][j] != '\0')
		{
			if (sd->map[i][j] == '1' || sd->map[i][j] == '0')
				j++;
			else if (sd->map[i][j] == 'C' || sd->map[i][j] == 'E'
					|| sd->map[i][j] == 'P')
				j++;
			else
			{
				write(1, "invalide item", 13);
				exit (1);
			}
		}
		j = 0;
		i++;
	}
}

char	ft_check_map_norm(t_data	*sd)
{
	int	i;
	int	a;
	int	j;

	j = 0;
	i = 0;
	if (sd->map[0] == NULL)
		return (write(1, "\033[0;31minvalid forme\n", 22), exit(1), 0);
	i = ft_strlen(sd->map[j++]);
	a = i;
	while (sd->map[j])
	{
		i = ft_strlen(sd->map[j]);
		if (i != a)
			return (write(1, "\033[0;31mmap not symmetric\n", 25), exit(1), 0);
		j++;
	}
	if (j == a)
		return (write(1, "\033[0;31mthe map not rectangular\n", 31), exit(1), 0);
	sd->x_map = a;
	sd->y_map = j;
	return (0);
}

int	ft_check_map_walls(t_data	*sd)
{
	int	i;

	i = 0;
	if (sd->map[0] == NULL)
		return (write(1, "\033[0;31minvalid forme", 22), 0);
	ft_check_line_is_1(sd->map[0]);
	while (sd->map[++i])
	{
		if (sd->map[i] == NULL)
			break ;
		ft_check_middle_lines(sd->map[i]);
	}
	ft_check_line_is_1(sd->map[i - 1]);
	return (0);
}

char	**ft_read_map(char *map)
{
	int		fd;
	char	*str;
	char	*temp;
	char	**d;

	str = "";
	temp = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (write(2, "fd error\n", 9), exit(1), NULL);
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL || str[0] == '\n')
			break ;
		temp = ft_strjoin(temp, str);
		free(str);
	}
	close(fd);
	free(str);
	if (temp[0] == '\0')
		return (write(2, "can't read the map\n", 19), exit(1), NULL);
	d = ft_split(temp, '\n');
	free (temp);
	return (d);
}
