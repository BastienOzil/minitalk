/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:25:18 by bozil             #+#    #+#             */
/*   Updated: 2025/03/18 12:53:58 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	send_signal(pid_t server_pid, unsigned char c)
{
	int	bit;

	bit = 7;
	if (server_pid <= 0)
	{
		ft_printf("Error: wrong PID\n");
		return ;
	}
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(350);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;
	int		y;

	if (argc < 3)
	{
		write(2, "Usage: ./client server_PID \"message\"\n", 38);
		return (1);
	}
	server_pid = atoi(argv[1]);
	y = 2;
	while (argc > y)
	{
		i = 0;
		while (argv[y][i])
		{
			send_signal(server_pid, (unsigned char)argv[y][i]);
			i++;
		}
		y++;
	}
	if (server_pid > 0)
		send_signal(server_pid, '\0');
	return (0);
}
