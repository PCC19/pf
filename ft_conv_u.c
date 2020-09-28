/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:12:59 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:11:50 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int unsigned	ft_parse_lhu(long long unsigned int x, int length)
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

void					ft_conv_u(va_list args, int *conta, struct s_fs *fs)
{
	long long unsigned int	p;
	char					*num;

	num = NULL;
	p = va_arg(args, long long unsigned int);
	p = ft_parse_lhu(p, fs->length);
	num = ft_itoa(p);
	if (p == 0 && fs->flag_printa_zero == 0)
		*num = 0;
	fs->flag_tem_sinal = 0;
	fs->np = ft_max((fs->precision - (int)ft_strlen(num)), 0);
	fs->nw = ft_max(fs->width - ((int)ft_strlen(num) + fs->np
	+ fs->flag_tem_sinal), 0);
	ft_print_pads(0, fs);
	ft_print_pads(1, fs);
	ft_print_pads(2, fs);
	ft_print_string(num);
	ft_print_pads(3, fs);
	(*conta) += ft_strlen(num) + fs->flag_tem_sinal + fs->nw + fs->np;
	free(num);
}
