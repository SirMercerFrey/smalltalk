#ifndef SMALL_TALK_H
# define SMALL_TALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdio.h>

extern volatile int    g_morse[4][9];
extern volatile int	   g_received;

void    sigaction_handler(int signum, siginfo_t *info, void *more_info);
void    fill_byte(int signum, int n, pid_t link);
void    print_byte(int n, pid_t link);
void    reinitialize_morse(void);
int nbr_bytes(void);
void    send_char_signals(pid_t pid, char c);
void    signal_handler(int signum);
int ft_atoi(const char *str);
char    *ft_itoa(int n);
size_t	ft_strlen(const char *str);

void print_g_morse(void);
#endif
