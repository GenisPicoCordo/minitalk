/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:41:14 by gpico-co          #+#    #+#             */
/*   Updated: 2024/12/12 17:41:16 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv) {
    pid_t server_pid;

    if (argc != 2) {
        ft_printf("Usage: ./client <PID>\n");
        return (1);
    }

    server_pid = (pid_t)atoi(argv[1]);
    if (kill(server_pid, SIGUSR1) == -1) {
        perror("Error sending SIGUSR1");
        return (1);
    }

    if (kill(server_pid, SIGUSR2) == -1) {
        perror("Error sending SIGUSR2");
        return (1);
    }

    return (0);
}
