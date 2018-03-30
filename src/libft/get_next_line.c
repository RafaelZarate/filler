/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 01:14:57 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/19 12:47:39 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	give_next_line(char **c_buff, int fd, char **line, int i)
{
	char			*tmp;

	if (c_buff[fd][i] == '\n')
	{
		*line = ft_strsub(c_buff[fd], 0, i);
		tmp = ft_strsub(c_buff[fd], i + 1, ft_strlen(c_buff[fd]) - i - 1);
		free(c_buff[fd]);
		c_buff[fd] = tmp;
	}
	else
	{
		*line = ft_strsub(c_buff[fd], 0, i);
		free(c_buff[fd]);
		c_buff[fd] = NULL;
	}
}

static	int		check_gnl(char **c_buff, int ret, int fd, char **line)
{
	int				i;

	i = 0;
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!c_buff[fd][0] || !c_buff[fd]))
		return (0);
	while (c_buff[fd][i] && c_buff[fd][i] != '\n')
		i++;
	give_next_line(c_buff, fd, line, i);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*c_buff[10240];
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	ret = 0;
	if (read(fd, 0, 0) < 0 || !line)
		return (-1);
	if (c_buff[fd] == NULL)
		c_buff[fd] = ft_strnew(0);
	if (!ft_strchr(c_buff[fd], '\n'))
	{
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			tmp = ft_strjoin(c_buff[fd], buff);
			free(c_buff[fd]);
			c_buff[fd] = tmp;
			if (ft_strchr(c_buff[fd], '\n'))
				break ;
		}
	}
	return (check_gnl(c_buff, ret, fd, line));
}
