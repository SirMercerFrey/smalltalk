/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 15:42:54 by mcharret          #+#    #+#             */
/*   Updated: 2025/08/03 15:43:14 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smalltalk.h"

static int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;

	sign = 1;
	while (*str && is_space(*str))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		++str;
	}
	return (sign * result);
}

static int	nb_int(int n)
{
	int			nb;
	long int	nbr;

	nbr = n;
	nb = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		++nb;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= 10;
		++nb;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			len;
	long int	nbr;

	nbr = n;
	len = nb_int(nbr);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[0] = '0';
	result[len--] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		result[len] = nbr % 10 + '0';
		nbr /= 10;
		--len;
	}
	return (result);
}

size_t	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end)
		++end;
	return (end - str);
}
