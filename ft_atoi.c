/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:01:04 by onelda            #+#    #+#             */
/*   Updated: 2022/06/13 20:49:32 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	iswhite_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	issign(char c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	k;

	k = 1;
	res = 0;
	while (iswhite_space(*nptr))
		nptr++;
	if (issign(*nptr))
	{
		if (*nptr == '-')
			k = -k;
		nptr++;
	}
	while (ft_isdigit(*nptr))
		res = res * 10 + ((*nptr++) - '0');
	return (res * k);
}
