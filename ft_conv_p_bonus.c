/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:32:39 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:32:40 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_prefix(char *num)
{
	char *tmp;

	tmp = ft_strjoin("0x", num);
	free(num);
	return (tmp);
}

void	ft_conv_p(va_list args, int *conta, struct s_fs *fs)
{
	long int	p;
	char		*num;

	fs->precision = ft_max(fs->precision, 0);
	p = va_arg(args, long int);
	num = ft_converte(p, fs);
	fs->flag_tem_sinal = 0;
	fs->np = ft_max((fs->precision - (int)ft_strlen(num)), 0);
	fs->nw = ft_max(fs->width - ((int)ft_strlen(num) + fs->np + 2), 0);
	ft_print_pads(0, fs);
	fs->prefixo = 1;
	ft_printa_ox(p, fs, conta);
	ft_print_pads(1, fs);
	ft_print_pads(2, fs);
	ft_print_string(num);
	ft_print_pads(3, fs);
	(*conta) += ft_strlen(num) + fs->flag_tem_sinal + fs->nw + fs->np;
	free(num);
}
