/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:41:21 by gpico-co          #+#    #+#             */
/*   Updated: 2024/12/12 17:41:24 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int sig) {
    if (sig == SIGUSR1)
        ft_printf("SIGUSR1 received\n");
    else if (sig == SIGUSR2)
        ft_printf("SIGUSR2 received\n");
}

int main(void) {
    pid_t pid;

    pid = getpid();
    ft_printf("Server PID: %d\n", pid);

    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    while (1)
        pause(); // Espera señales
    return (0);
}
