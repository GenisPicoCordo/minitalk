/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:41:14 by gpico-co          #+#    #+#             */
/*   Updated: 2024/12/16 11:21:41 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

volatile int	g_ack = 0;

void	signal_ack(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	send_bit(pid_t server_pid, int bit)
{
	if (bit == 1)
	{
		if (kill(server_pid, SIGUSR2) == -1)
		{
			perror("Error sending SIGUSR2");
			exit(1);
		}
	}
	else
	{
		if (kill(server_pid, SIGUSR1) == -1)
		{
			perror("Error sending SIGUSR1");
			exit(1);
		}
	}
	while (!g_ack)
		pause();
	g_ack = 0;
}

void	send_char(pid_t server_pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		send_bit(server_pid, (c >> bit) & 1);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <message>\n");
		return (1);
	}
	server_pid = (pid_t)atoi(argv[1]);
	signal(SIGUSR1, signal_ack);
	i = 0;
	while (argv[2][i])
	{
		send_char(server_pid, argv[2][i]);
		i++;
	}
	send_char(server_pid, '\0');
	return (0);
}
