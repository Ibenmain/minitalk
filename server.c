/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:05:49 by ibenmain          #+#    #+#             */
/*   Updated: 2022/02/13 21:45:41 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid;

void	handler(char *c, int *bit, int new_pid)
{
	*c = 0xFF;
	*bit = 0;
	g_pid = new_pid;
}

void	handler_sigusr(int signum, siginfo_t *siginf, void *ptr)
{
	static char	c = 0xFF;
	static int	bit;

	(void)ptr;
	if (!g_pid)
		g_pid = siginf->si_pid;
	if (g_pid != siginf->si_pid)
		handler(&c, &bit, siginf->si_pid);
	if (signum == SIGUSR1)
	{
		c ^= 128 >> bit;
	}
	else if (signum == SIGUSR2)
	{
		c |= 128 >> bit;
	}
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler_sigusr;
	sa.sa_flags = SA_RESTART;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
