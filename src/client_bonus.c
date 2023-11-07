/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:21:09 by mwu               #+#    #+#             */
/*   Updated: 2023/11/06 19:15:45 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	success(int sig)
{
	write(1, "server connected\n", 17);
	exit(0);
}

void	bit_send(char c, int pid)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		if ((c >> bit & 1) && (kill(pid, SIGUSR1) == -1))
			ft_string_error("SIGUSR1 can not send");
		else if (!(c >> bit & 1) && (kill(pid, SIGUSR2) == -1))
			ft_string_error("SIGUSR2 can not send");
		usleep(299);
	}
}

void	ft_send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		bit_send(str[i], pid);
		i++;
	}
	bit_send(str[i], pid);
}

int	main(int argc, char **argv)
{
	if (ft_isnum(argv[1]) == -1)
		ft_string_error("PID with other character is wrong!");
	if (kill(ft_atoi(argv[1]), 0) == -1)
		ft_string_error("PID is not valid!");
	if (argc == 3)
	{
		signal(SIGUSR2, success);
		ft_send_message(argv[2], ft_atoi(argv[1]));
		while (1)
			pause();
	}
	else
		ft_string_error("error!");
}
