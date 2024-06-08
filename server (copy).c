#include "minitalk.h"

static t_minitalk	g_mt = {{0}, 0, 0, 0L, 0, 0};

void	fetch_pid()
{
	int	i;

	i = -1;
	while (++i < g_mt.pid_size)
	{
		g_mt.client_pid = 10 * g_mt.client_pid + (g_mt.pid_ar[i] - '0');
		g_mt.pid_ar[i] = '\0';
	}
	kill(g_mt.client_pid, SIGUSR2);
	g_mt.is_pid = 0;
	g_mt.pid_size = 0;
	g_mt.client_pid = 0;
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR2)
		g_mt.ch |= 1 << g_mt.bit;
	g_mt.bit++;
	if (g_mt.bit == 8)
	{
		if (g_mt.is_pid)
		{
			if (g_mt.ch == '\n')
				fetch_pid();
			else
				g_mt.pid_ar[g_mt.pid_size++] = g_mt.ch;
		}
		else
		{
			if (g_mt.ch == '\n')
				g_mt.is_pid = 1;
			ft_putchar_fd(g_mt.ch, 1);
		}
		g_mt.ch = 0;
		g_mt.bit = 0;
	}
}

int	main(void)
{
	printf("SERVER | PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
