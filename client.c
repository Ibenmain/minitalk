/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:10:01 by ibenmain          #+#    #+#             */
/*   Updated: 2022/02/13 21:41:45 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(char message, int pid)
{
	int	shift;

	shift = -1;
	while (++shift < 8)
	{
		if (message & (128 >> shift))
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit (1);
		}
		usleep(300);
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signals(str[i], pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("invalid arguments");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (write (2, "ERROR", 5), 0);
	send_message(argv[2], pid);
	return (0);
}
