/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:34:04 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:34:05 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_format(char **str, struct s_fs *fs, va_list args, int *conta)
{
	(*str)++;
	ft_init_fs(fs);
	ft_parse_fs(fs, str, args);
	ft_choose_conv(args, conta, fs, (*str));
}

int		ft_printf(const char *string, ...)
{
	va_list		args;
	int			conta;
	char		*str;
	char		*aux;
	struct s_fs	fs;

	str = (char *)malloc(sizeof(char) * ft_strlen(string) + 1);
	ft_strlcpy(str, string, ft_strlen(string) + 1);
	aux = str;
	va_start(args, string);
	conta = 0;
	while (*str)
	{
		if (*str == '%')
			ft_print_format(&str, &fs, args, &conta);
		else
		{
			ft_putchar_fd(*str, 1);
			conta++;
		}
		str++;
	}
	va_end(args);
	free(aux);
	return (conta);
}
