/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:26:00 by mvoloshy          #+#    #+#             */
/*   Updated: 2024/06/10 13:26:02 by mvoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(WAIT_TIME);
		i++;
	}
}

void	send_message(pid_t server_pid, const char *message)
{
	while (*message)
	{
		send_char(server_pid, *message);
		message++;
	}
	send_char(server_pid, '\n');
}

void	handle_ack(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf(":\tSuccessfully delivered!\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*client_pid;

	if (argc != 3 || ft_strlen(argv[1]) == 0)
		return (1);
	client_pid = ft_itoa(getpid());
	printf("CLIENT | PID: %s\n", client_pid);
	ft_printf(":\tMessage sent: %s\n", argv[2]);
	server_pid = atoi(argv[1]);
	signal(SIGUSR2, handle_ack);
	send_message(server_pid, argv[2]);
	send_message(server_pid, client_pid);
	free(client_pid);
	return (0);
}
