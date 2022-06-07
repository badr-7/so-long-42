/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_dep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:26:16 by mel-hous          #+#    #+#             */
/*   Updated: 2022/06/07 14:26:17 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*buff;
	char	*rest;
	int		i;

	buff = malloc(2);
	rest = NULL;
	buff[0] = '\0';
	while (buff[0] != '\n')
	{
		i = read(fd, buff, 1);
		if (i == -1)
		{
			free(buff);
			free(rest);
			return (NULL);
		}
		if (i == 0)
			break ;
		buff[i] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	free(buff);
	if (rest == NULL || ft_strncmp(rest, "", 2) == 0)
		return (NULL);
	return (rest);
}

void	ft_check_line_is_1(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
		{
			write(1, "\033[0;31minvalid forme", 22);
			exit (1);
		}
		i++;
	}
}

void	ft_check_middle_lines(char	*str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != '1' || str[0] != '1')
	{
		write(1, "\033[0;31minvalid forme", 21);
		exit (1);
	}
}
