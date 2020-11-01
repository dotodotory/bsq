/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiykim <jiykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:56:29 by jiykim            #+#    #+#             */
/*   Updated: 2020/11/01 23:04:34 by jiykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(char *str, int size)
{
	int a_i;

	a_i = 0;
	while (str[a_i] == ' ' || (str[a_i] >= 9  && str[a_i] <= 13))
		a_i++;
	while (a_i < size)
	{
		if (!(str[a_i] >= '0' && str[a_i] <= '9'))
			return (0);
		g_row = g_row * 10 + (str[a_i] - '0');
		a_i++;
	}
	return (1);
}

int	ft_first_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (!(ft_atoi(str, i - 3)))
	{
		free(str);
		return (0);
	}
	c[0] = str[i - 3];
	c[1] = str[i - 2];
	c[2] = str[i - 1];
	if (c[0] == c[1] || c[1] == c[2] || c[2] == c[0])
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

int	ft_read_file(int fd, char *buf)
{
	char	*tmp;
	char	*first;
	int		rd_size;
	int		flag;
	int	count;
	int	buf_i;

	flag = 0;
	count = 0;
	while (0 < (rd_size = read(fd, buf, BUFF_SIZE)))
	{
		while (buf_i < rd_size)
		{
			tmp = buf;
			while (*buf != '\n')
				buf++;
			if (flag++ == 0)
			{
				first = (char *)malloc(sizeof(char) * (buf - tmp + 1));
				first = ft_strncpy(first, tmp, buf - tmp);
				if (!ft_first_line(first))
					return (0);
			}
			buf_i = 0;
			if (flag == 1 && *buf == '\n')
				g_col = buf-tmp;
			if (flag++ >= 1 && *buf == '\n')
			{
				printf("ifas\n");
				if ((buf - tmp) != g_col)//no
					return (-1);
				count++;
			}
			buf_i++;
		}
	}
	printf("%d %d\n", g_row, count);
	if (g_row != count)
	{
		printf("as\n");
		return (-1);
	}
	return (1);
}

int	is_in_string(char *str, char c)
{
	int str_i;

	str_i = 0;
	while (str_i < 2)
	{
		if (str[str_i] == c)
			return (1);
		str_i++;
	}
	return (0);
}

int	handle_map_error(char *str)
{
	while (*str)
	{
		if (!(is_in_string(c, *str)))//no
			return (-1);
		str++;
	}
	return (1);
}

int	*ft_str_to_int(int *list, char *str, int size)
{
	int list_i;

	if (!handle_map_error(str))
		return (0);
	list_i = 1;
	while (list_i < size)
	{
		if (list[list_i] == c[0])
			list[list_i] = 1;
		else if (list[list_i] == c[1])
			list[list_i] = 0;
		list_i++;
	}
	return (list);
}

int 	ft_read_file2(int **map, int fd2, char *buf2)
{
	char *tmp2;
	int rd_size2;
	int flag2;

	flag2 = 0;
	map++;
	while (0 < (rd_size2 = read(fd2, buf2, BUFF_SIZE)))
	{
		tmp2 = buf2;
		while (*buf2 != '\n')
			buf2++;
		if (flag2 == 0)
		{
			flag2++;
			continue ;
		}
		if (flag2 == 1 && *buf2 == '\n')
		{
			*map = ft_str_to_int(*map, tmp2, buf2 - tmp2);
			if (*map == 0)//no
				return (-1);
			map++;
		}
		buf2++;
	}
	*map = 0;
	return (1);
}

int		handle_error(int fd, char *buf)
{
	int f;

	f = ft_read_file(fd, buf);
	if (f == 0)
		return (0);
	if (f == -1)
	{
		//printf("as\n");
		return (-1);
	}
	return (1);
}
