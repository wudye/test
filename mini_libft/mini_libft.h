/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:29:22 by mwu               #+#    #+#             */
/*   Updated: 2023/11/07 10:41:59 by mwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LIBFT_H
# define MINI_LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isnum(char *s);
void	ft_print_char(char c);
void	ft_string_error(char *s);
int		ft_atoi(char *s);
size_t	ft_strlen(char *s);
#endif
