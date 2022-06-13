/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onelda <onelda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:03:01 by onelda            #+#    #+#             */
/*   Updated: 2022/06/13 21:11:26 by onelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static size_t	ft_number_of_words(const char *str, char c)
{
	size_t			i;
	size_t			res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i + 1] == c)
			|| (str[i] != c && !str[i + 1]))
			res++;
		i++;
	}
	return (res);
}

static size_t	ft_strlen_until_c(const char *str, char c)
{
	size_t			res;

	res = 0;
	while (str[res] && str[res] != c)
		res++;
	return (res);
}

static char	**ft_clear(char **res)
{
	unsigned int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t			i;
	size_t			b;
	char			**res;

	i = 0;
	b = 0;
	res = malloc((ft_number_of_words(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return (NULL);
	while (s[i++] == c)
		b++;
	i = -1;
	while (++i < ft_number_of_words(s, c))
	{
		res[i] = ft_substr(s, b, ft_strlen_until_c(&s[b], c));
		if (!res)
			return (ft_clear(res));
		b += ft_strlen_until_c(&s[b], c);
		while (s[b] == c)
			b++;
	}
	res[i] = NULL;
	return (res);
}