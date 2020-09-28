/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:33:01 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:33:02 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

long long int unsigned	ft_parse_lhx(long long int x, int length)
{
	if (length == 0)
		x = (unsigned int)x;
	if (length == 1)
		x = (unsigned long int)x;
	if (length == 2)
		x = (unsigned long long int)x;
	if (length == 3)
		x = (unsigned short int)x;
	if (length == 6)
		x = (unsigned char)x;
	return (x);
}

void					ft_conv_x(va_list args, int *conta, struct s_fs *fs)
{
	long long unsigned int	p;
	char					*num;

	p = va_arg(args, long long unsigned int);
	p = ft_parse_lhx(p, fs->length);
	num = ft_converte(p, fs);
	if (p == 0 && !fs->flag_printa_zero)
		*num = 0;
	fs->flag_tem_sinal = 0;
	fs->np = ft_max((fs->precision - (int)ft_strlen(num)), 0);
	fs->nw = ft_max(fs->width - ((int)ft_strlen(num) + fs->np
	+ fs->flag_tem_sinal), 0);
	if (fs->prefixo == 1 && p != 0)
		fs->nw -= 2;
	fs->nw = ft_max(fs->nw, 0);
	ft_print_pads(0, fs);
	ft_printa_ox(p, fs, conta);
	ft_print_pads(1, fs);
	ft_print_pads(2, fs);
	ft_print_string(num);
	ft_print_pads(3, fs);
	(*conta) += ft_strlen(num) + fs->flag_tem_sinal + fs->nw + fs->np;
	free(num);
}
