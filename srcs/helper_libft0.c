/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_libft0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:17:31 by abutet            #+#    #+#             */
/*   Updated: 2024/04/16 10:26:33 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_strlen(const char *s)
{
	long long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long long	ft_strlcpy(char *dst, char *src, long long size)
{
	long long	i;
	long long	j;

	i = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size)
	{
		if (i >= size)
			j = size - 1;
		else
			j = i;
		ft_memcpy(dst, src, j);
		dst[j] = '\0';
	}
	return (i);
}

void	*ft_memcpy(void *dest, void *src, long long n)
{
	char	*sr;
	char	*ds;

	sr = (char *)src;
	ds = (char *)dest;
	if (!src && !dest)
		return (0);
	while (n--)
		*ds++ = *sr++;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sj;
	int		n;
	int		n1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	n = ft_strlen(s1);
	n1 = ft_strlen(s2);
	sj = (char *)malloc((sizeof(char) * n) + (sizeof(char) * n1) + 2);
	if (!sj)
		return (NULL);
	while (s1[i] != '\0')
		sj[j++] = s1[i++];
	i = 0;
	sj[j++] = ' ';
	while (s2[i] != '\0')
		sj[j++] = s2[i++];
	sj[j] = '\0';
	return (free(s1), sj);
}
