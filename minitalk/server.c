/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:41:21 by gpico-co          #+#    #+#             */
/*   Updated: 2024/12/16 11:15:35 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 0;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handle_signal;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
