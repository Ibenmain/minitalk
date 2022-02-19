/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minitalk.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:23:34 by ibenmain          #+#    #+#             */
/*   Updated: 2022/02/13 15:24:04 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_MINITALK_H
# define BONUS_MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *s);
void	ft_putnbr(int pid);
int		ft_atoi(char *str);
void	msg_handler1(int id);
void	send_signals1(char message, int pid);
void	send_message1(char *str, int pid);
void	handler1(char *c, int *bit, int new_pid);
void	handler_sigusr1(int signum, siginfo_t *siginf, void *ptr);

#endif
