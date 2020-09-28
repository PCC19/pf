/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:12:59 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 11:03:22 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_parse_lhd(long long int x, int length)
{
	if (length == 0)
		x = (int)x;
	if (length == 1)
		x = (long int)x;
	if (length == 2)
		x = (long long int)x;
	if (length == 3)
		x = (short int)x;
	if (length == 6)
		x = (signed char)x;
	return (x);
}

void			ft_imprime_sinal(long long int p, struct s_fs *fs)
{
	if (p < 0)
		ft_putchar_fd('-', 1);
	else
		ft_print_sinal(fs->sinal);
}

void			ft_conv_d(va_list args, int *conta, struct s_fs *fs)
{
	long long int	p;
	char			*num;

	p = va_arg(args, long long int);
	p = ft_parse_lhd(p, fs->length);
	num = p < 0 ? ft_itoa(-p) : ft_itoa(p);
	if (p == 0 && fs->flag_printa_zero == 0)
		*num = 0;
	if (fs->sinal == 0 && p >= 0)
		fs->flag_tem_sinal = 0;
	fs->np = ft_max((fs->precision - (int)ft_strlen(num)), 0);
	fs->nw = ft_max(fs->width - ((int)ft_strlen(num) + fs->np +
	fs->flag_tem_sinal), 0);
	ft_print_pads(0, fs);
	ft_imprime_sinal(p, fs);
	ft_print_pads(1, fs);
	ft_print_pads(2, fs);
	ft_print_string(num);
	ft_print_pads(3, fs);
	(*conta) += ft_strlen(num) + fs->flag_tem_sinal + fs->nw + fs->np;
	free(num);
}
