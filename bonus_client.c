/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:00:01 by ibenmain          #+#    #+#             */
/*   Updated: 2022/02/13 21:45:12 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_minitalk.h"

void	msg_handler1(int id)
{
	(void)id;
	ft_putstr("\nMessage successfully sent...");
	exit(0);
}

void	send_signals1(char message, int pid)
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
		usleep(500);
	}
}

void	send_message1(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signals1(str[i], pid);
		i++;
	}
	send_signals1('\0', pid);
}

int	main(int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, msg_handler1);
	if (argc != 3)
	{
		ft_putstr("invalid arguments");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (write (2, "ERROR", 5), 0);
	send_message1(argv[2], pid);
	pause();
	return (0);
}
