/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:01:27 by mwu               #+#    #+#             */
/*   Updated: 2023/11/07 10:53:26 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_putchar(char c, long int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putnbr(int nbr, long int *len)
{
	char	c;

	if (nbr == -2147483648)
	{
		ft_putchar('-', len);
		ft_putchar('2', len);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	else if (nbr > 9)
		ft_putnbr(nbr / 10, len);
	c = nbr % 10 + '0';
	ft_putchar(c, len);
}

int	mini_printf(char *str, ...)
{
	va_list		var;
	int			i;
	long int	len;

	i = 0;
	len = 0;
	va_start(var, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_putnbr(va_arg(var, int), &len);
			i++;
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(var);
	return (len);
}

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned int	c;
	static int			bit	;

	(void)info;
	(void)context;
	c = (signal == SIGUSR1) << bit | c;
	bit++;
	if (bit == 8)
	{
		if (!c)
			ft_print_char('\n');
		else
			ft_print_char(c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	mini_printf("PID is: %d\n", getpid());
	sig.sa_sigaction = sig_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, 0) == -1)
		ft_string_error("failure SIGUSR1");
	if (sigaction(SIGUSR2, &sig, 0) == -1)
		ft_string_error("failure SIGUSR2");
	while (1)
		pause();
}
