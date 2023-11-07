/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:32:33 by mwu               #+#    #+#             */
/*   Updated: 2023/11/06 19:01:19 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_send_bit(char s, int pid)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		if ((s >> bit & 1) && kill(pid, SIGUSR1) == -1)
			ft_string_error("SIGUSR1 can not send");
		else if (!(s >> bit & 1) && kill(pid, SIGUSR2) == -1)
			ft_string_error("SIGUSR2 can not send");
		usleep(200);
	}
}

void	ft_send_message(char *src, int pid)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		ft_send_bit(src[i], pid);
		i++;
	}
	ft_send_bit(src[i], pid);
}

int	main(int argc, char **argv)
{
	if (ft_isnum(argv[1]) == 0)
		ft_string_error("PID with other character is wrong!");
	if (kill(ft_atoi(argv[1]), 0) == -1)
		ft_string_error("PID is not valid!");
	if (argc == 3)
		ft_send_message (argv[2], ft_atoi(argv[1]));
	else
		ft_string_error("error!");
	return (0);
}
