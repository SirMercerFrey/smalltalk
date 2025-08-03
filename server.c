/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 15:39:29 by mcharret          #+#    #+#             */
/*   Updated: 2025/08/03 15:40:21 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smalltalk.h"

volatile int	g_morse[4][9];

int	main(void)
{
	char				*pid;
	struct sigaction	act;

	pid = ft_itoa(getpid());
	if (!pid)
		return (1);
	write(STDOUT_FILENO, "PID : ", 6);
	write(STDOUT_FILENO, pid, ft_strlen(pid));
	write(STDOUT_FILENO, "\n", 1);
	act.sa_sigaction = sigaction_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	reinitialize_morse();
	free(pid);
	while (1)
		pause();
	return (0);
}

void	sigaction_handler(int signum, siginfo_t *info, void *more_info)
{
	static pid_t	link;

	(void)more_info;
	if (info->si_pid)
		link = info->si_pid;
	if (g_morse[0][7] == 42)
		fill_byte(signum, 0, link);
	else if (g_morse[1][7] == 42)
		fill_byte(signum, 1, link);
	else if (g_morse[2][7] == 42)
		fill_byte(signum, 2, link);
	else if (g_morse[3][7] == 42)
		fill_byte(signum, 3, link);
}

void	fill_byte(int signum, int n, pid_t link)
{
	int			i;
	static int	expected_bytes;

	i = 0;
	while (i < 8 && g_morse[n][i] != 42)
		++i;
	if (i == 8)
		exit(EXIT_FAILURE);
	if (signum == SIGUSR1)
		g_morse[n][i] = 0;
	else
		g_morse[n][i] = 1;
	if (i == 7 && n == 0)
	{
		expected_bytes = nbr_bytes();
	}
	if (expected_bytes && i == 7 && (n + 1) == expected_bytes)
	{
		print_byte(expected_bytes, link);
		reinitialize_morse();
		expected_bytes = 0;
	}
}

void	print_byte(int n, pid_t link)
{
	int		bit;
	int		i;
	int		j;
	char	str[4];

	i = 0;
	while (i < n)
	{
		bit = 0;
		j = 0;
		while (j < 8)
			bit = bit * 2 + g_morse[i][j++];
		str[i++] = (char)bit;
	}
	write(STDOUT_FILENO, str, n);
	if (!*str)
	{
		write(STDOUT_FILENO, "\n", 1);
		kill(link, SIGUSR1);
	}
}
