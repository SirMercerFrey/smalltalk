#include "smalltalk.h"

volatile int	g_received;

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	g_received = 0;
	if (argc != 3)
		return (write(STDERR_FILENO, "./client PID \"message\"\n", 23));
	signal(SIGUSR1, signal_handler);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
    	return (write(STDERR_FILENO, "Invalid PID\n", 12));	
	i = 0;
	while (argv[2][i])
	{
		send_char_signals(pid, argv[2][i]);
		++i;
	}
	send_char_signals(pid, '\0');
	while (!g_received)
		pause();
	return (0);
}

void	send_char_signals(pid_t pid, char c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		--i;
		usleep(500);
	}
}

void	signal_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "Message received.\n", 18);
	g_received = 1;
}
