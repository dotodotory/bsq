/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiykim <jiykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:29:00 by jiykim            #+#    #+#             */
/*   Updated: 2020/11/01 18:47:18 by jiykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *ft_strncpy(char *dest, char *src, int size)
{
	int index;

	index = 0;
	while (index < size && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	while (index < size)
		dest[index++] = '\0';
	return (dest);
}
