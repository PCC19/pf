/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:32:18 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:32:19 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_pad_f(struct s_fs *fs, int negativo)
{
	if (fs->jus == 0)
		ft_print_n_chars(fs->nw, fs->pad);
	if (negativo)
		ft_putchar_fd('-', 1);
	else
		ft_print_sinal(fs->sinal);
}

void	ft_conv_f(va_list args, int *conta, struct s_fs *fs)
{
	float			p;
	char			*num;
	int				precision;
	int				negativo;
	t_float_cast	n;

	p = (float)va_arg(args, double);
	negativo = 0;
	n.f = (float)p;
	if (n.s_parts.sign)
		negativo = 1;
	if (!fs->ponto)
		precision = 6;
	num = negativo ? ft_ftoa(-p, precision) : ft_ftoa(p, precision);
	fs->flag_tem_sinal = (negativo || fs->sinal != 0) ? 1 : 0;
	fs->np = ft_max((fs->precision - (int)ft_strlen(num)), 0);
	fs->nw = ft_max(fs->width - ((int)ft_strlen(num) + fs->np
	+ fs->flag_tem_sinal), 0);
	ft_pad_f(fs, negativo);
	ft_print_n_chars(fs->np, '0');
	ft_print_string(num);
	if (fs->jus == 1)
		ft_print_n_chars(fs->nw, ' ');
	(*conta) += ft_strlen(num) + fs->flag_tem_sinal + fs->nw + fs->np;
	free(num);
}
