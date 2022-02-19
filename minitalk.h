/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:22:12 by ibenmain          #+#    #+#             */
/*   Updated: 2022/02/13 15:23:13 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *s);
void	ft_putnbr(int pid);
int		ft_atoi(char *str);
void	send_signals(char message, int pid);
void	send_message(char *str, int pid);
void	handler(char *c, int *bit, int new_pid);
void	handler_sigusr(int signum, siginfo_t *siginf, void *ptr);

#endif
