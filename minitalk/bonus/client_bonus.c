/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:27:03 by gpico-co          #+#    #+#             */
/*   Updated: 2024/12/16 15:29:44 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	mt_error_output(int i)
{
	if (i == 0)
	{
		ft_printf("KILL error.\n");
		exit(1);
	}
	if (i == 1)
	{
		ft_printf("SIGACTION error.\n");
		exit(1);
	}
}

void	mt_terminate(int pid)
{
	static int	i = 0;

	if (i < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			mt_error_output(0);
		i++;
	}
}

void	mt_send_sign(int pid, char *msg)
{
	static int	bit = 0;
	static char	*msg_copy = NULL;

	if (msg)
		msg_copy = msg;
	if (*msg_copy)
	{
		if (((unsigned char)*msg_copy >> bit) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				mt_error_output(0);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				mt_error_output(0);
		}
		bit++;
		if (bit == 8)
		{
			msg_copy++;
			bit = 0;
		}
	}
	else
		mt_terminate(pid);
}

void	mt_ack(int sig, siginfo_t *info, void *context)
{
	static int	id;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)context;
	if (sig == SIGUSR1)
		mt_send_sign(id, NULL);
	if (sig == SIGUSR2)
	{
		ft_printf("The message arrived at the server.\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = mt_ack;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		mt_error_output(1);
	mt_send_sign(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();

	return (0);
}

