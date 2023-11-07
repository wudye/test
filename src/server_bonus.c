/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:20:47 by mwu               #+#    #+#             */
/*   Updated: 2023/11/07 10:55:18 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	ft_putchar(char c, long int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putnbr(int n, long int *len)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putchar('-', len);
		ft_putchar('2', len);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, len);
	c = n % 10 + '0';
	ft_putchar(c, len);
}

int	mini_printf(char *s, ...)
{
	va_list		var;
	int			i;
	long int	len;

	i = 0;
	len = 0;
	va_start(var, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_putnbr(va_arg(var, int), &len);
			i++;
		}
		else
			ft_print_char(s[i]);
		i++;
	}
	va_end(var);
	return (len);
}

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned int	c;
	static int			bit;

	c = (signal == SIGUSR1) << bit | c;
	bit++;
	if (bit == 8)
	{
		if (!c)
		{
			kill(info->si_pid, SIGUSR2);
			ft_print_char('\n');
		}
		else
			ft_print_char(c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	mini_printf("Server PID: %d\n", getpid());
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, 0) == -1)
		ft_string_error("ERROR in SIGURSR1");
	if (sigaction(SIGUSR2, &act, 0) == -1)
		ft_string_error("ERROR in SIGURSR1");
	while (1)
		pause();
}
