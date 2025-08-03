/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 15:37:21 by mcharret          #+#    #+#             */
/*   Updated: 2025/08/03 15:37:50 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smalltalk.h"

void	reinitialize_morse(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 9)
		{
			g_morse[i][j] = 42;
			++j;
		}
		++i;
	}
}

int	nbr_bytes(void)
{
	if (g_morse[0][0] == 0)
		return (1);
	if (g_morse[0][0] == 1 && g_morse[0][1] == 1
		&& g_morse[0][2] == 0)
		return (2);
	if (g_morse [0][0] == 1 && g_morse[0][1] == 1
		&& g_morse[0][2] == 1 && g_morse[0][3] == 0)
		return (3);
	if (g_morse [0][0] == 1 && g_morse[0][1] == 1
		&& g_morse[0][2] == 1 && g_morse[0][3] == 1
		&& g_morse[0][4] == 0)
		return (4);
	return (0);
}
