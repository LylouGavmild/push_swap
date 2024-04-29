/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:17:21 by abutet            #+#    #+#             */
/*   Updated: 2024/04/16 10:26:28 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strdup(char *s)
{
	char	*sn;

	sn = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sn)
		return (0);
	else
		ft_strlcpy(sn, s, ft_strlen(s) + 1);
	return (sn);
}

char	*ft_substr(char *s, unsigned int start, long long len)
{
	char		*sb;
	long long	i;
	long long	j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	if (start < ft_strlen(s))
		while (j < len && s[start + j] != '\0')
			j++;
	sb = (char *)malloc(sizeof(char) * j + 1);
	if (!sb)
		return (0);
	while (i < j)
	{
		sb[i] = s[start + i];
		i++;
	}
	sb[i] = '\0';
	return (sb);
}

static long long	strlenmal(char *s)
{
	long long	i;

	i = 0;
	while (*s)
	{
		if (!is_whitespace(*s))
		{
			i++;
			while (*s && !is_whitespace(*s))
				s++;
		}
		else
			s++;
	}
	return (i);
}

char	**ft_split(char *s)
{
	char		**sn;
	long long	i;
	long long	j;

	if (!s)
		return (0);
	i = 0;
	sn = malloc(sizeof(char *) * (strlenmal(s) + 1));
	if (!sn)
		return (0);
	while (*s)
	{
		if (!is_whitespace(*s))
		{
			j = 0;
			while (*s && !is_whitespace(*s) && ++j)
				s++;
			sn[i++] = ft_substr(s - j, 0, j);
		}
		else
			s++;
	}
	sn[i] = 0;
	return (sn);
}
