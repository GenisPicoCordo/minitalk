/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:41:21 by gpico-co          #+#    #+#             */
/*   Updated: 2024/12/18 14:59:22 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

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

void	mt_process_bit(int sig, unsigned char *val, int *bit)
{
	if (sig == SIGUSR2)
		*val += *bit;
	*bit *= 2;
}

void	mt_complete_char(int *bit, unsigned char *val, int id)
{
	*bit = 1;
	if (*val == 0)
	{
		if (kill(id, SIGUSR2) == -1)
			mt_error_output(0);
		*val = 0;
		return ;
	}
	write(1, val, 1);
	*val = 0;
}

void	mt_signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	val = 0;
	static int				bit = 1;
	static int				id = 0;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)context;
	mt_process_bit(sig, &val, &bit);
	if (bit == 256)
		mt_complete_char(&bit, &val, id);
	if (kill(id, SIGUSR1) == -1)
		mt_error_output(0);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = mt_signal_handler;
	sigemptyset(&action.sa_mask);
	pid = getpid();
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		mt_error_output(1);
	ft_printf("Server PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}