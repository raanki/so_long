/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:09:19 by ranki             #+#    #+#             */
/*   Updated: 2022/12/17 12:24:09 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1000
#endif

void	ft_emptyline(char **line, char **tmp, int len)
{
	char	*tmp2;

	*tmp = ft_strsub(*line, 0, len + 1);
	tmp2 = ft_strdup(*line + len + 1);
	free(*line);
	*line = tmp2;
	if ((*line)[0] == 0)
	{
		free(*line);
		*line = NULL;
	}
}

char	*ft_clean(char **line, int ret)
{
	int		len;
	char	*tmp;

	len = 0;
	if (ret <= 0 && line == NULL)
		return (0);
	while ((*line)[len] != '\n' && (*line)[len] != '\0')
		len++;
	if ((*line)[len] == '\n')
		ft_emptyline(line, &tmp, len);
	else
	{
		tmp = ft_strdup(*line);
		free(*line);
		*line = NULL;
	}
	return (tmp);
}

void	ft_makeline(char **line, char **buff)
{
	char	*tmp;

	if (*line != 0)
	{
		tmp = ft_strjoin(*line, *buff);
		free(*line);
		*line = tmp;
	}
	else
		*line = ft_strdup(*buff);
}

int	ft_while(char **buff, int *ret, char **line, int fd)
{
	while (*ret > 0)
	{
		(*buff)[*ret] = 0;
		ft_makeline(line, buff);
		if (ft_strchr(*line, '\n'))
			break ;
		*ret = read (fd, *buff, BUFFER_SIZE);
		if (*ret == -1)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buff;
	int			ret;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc (BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	ret = read (fd, buff, BUFFER_SIZE);
	if (ret <= 0 && line == NULL)
	{
		free(buff);
		return (NULL);
	}
	if (ft_while(&buff, &ret, &line, fd) == 0)
		return (NULL);
	free(buff);
	return (ft_clean(&line, ret));
}
