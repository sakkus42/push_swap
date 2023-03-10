/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:05:37 by sakkus            #+#    #+#             */
/*   Updated: 2023/03/01 17:05:38 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_satir(char const *s, char c)
{
	int	satir;
	int	index;

	satir = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index])
			satir++;
		while (s[index] != c && s[index])
			index++;
	}
	return (satir);
}

char	*ft_copy(char const *s, char c)
{
	char	*str1;
	int		index;
	int		len;

	if (!(*s))
		return (NULL);
	len = 0;
	while (s[len] != c && s[len])
		len++;
	str1 = (char *)malloc(sizeof(char) * len + 1);
	if (!(str1))
		return (NULL);
	index = 0;
	while (index < len)
		str1[index++] = *s++;
	str1[index] = '\0';
	return (str1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		satir;
	int		i;

	if (s == NULL)
		return (NULL);
	satir = ft_satir(s, c);
	str = (char **)malloc(sizeof(char *) * (satir + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (i < satir)
	{
		while (*s == c)
			s++;
		str[i] = ft_copy(s, c);
		i++;
		while (*s != c && *s)
			s++;
	}
	str[satir] = NULL;
	return (str);
}

long int	ft_atoi(char *str)
{
	int			i;
	long int	dig;

	i = 0;
	dig = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		dig = (dig * 10) + (str[i] - 48);
		i++;
	}
	if (str[0] == '-' || str[i] == '+')
		return (dig * -1);
	return (dig);
}
