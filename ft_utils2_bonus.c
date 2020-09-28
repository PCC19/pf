/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:34:26 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:34:28 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_popula_bits(int *arr, int mantisa)
{
	int i;

	i = 0;
	while (i < 23)
	{
		arr[i] = ft_get_bit(mantisa, i);
		i++;
	}
	arr[i] = 1;
}

void	ft_popula_array_i(int *arr, int n_arr, t_float_cast n)
{
	int	i;
	int	mantisa;

	mantisa = n.s_parts.mantisa;
	if (n.s_parts.exponent - 127 > 0)
	{
		i = 0;
		while (i < n_arr - 1)
		{
			if ((mantisa >> (i + 24 - n_arr) & 1))
			{
				arr[i] = 1;
			}
			i++;
		}
		arr[i] = 1;
	}
	else
	{
		arr[0] = 1;
	}
}

void	ft_popula_array_f(int *arr, int n_arr, t_float_cast n)
{
	int i;
	int mantisa;

	mantisa = n.s_parts.mantisa;
	i = 0;
	while (i < n_arr - 1)
	{
		arr[i] = ft_get_bit(mantisa, i);
		i++;
	}
	arr[i] = 1;
}

char	*ft_converte(long long unsigned int p, struct s_fs *fs)
{
	char *base;
	char *num;

	if (!p && fs->conversion == 'p')
	{
		if (fs->ponto && !fs->flag_ast_neg)
		{
			num = malloc(sizeof(char) + 1);
			*num = 0;
		}
		else
			num = ft_itoa(0);
		return (num);
	}
	if (ft_is_in(fs->conversion, "xX"))
		p = (long long unsigned int)p;
	if (ft_is_in(fs->conversion, "xp"))
		base = "0123456789abcdef";
	if (fs->conversion == 'X')
		base = "0123456789ABCDEF";
	num = ft_itoa_base(p, base);
	return (num);
}

void	ft_aux_e(struct s_fs *fs, char *num, double p, int exp)
{
	if (fs->precision > 0)
		ft_coloca_ponto(num);
	if (fs->precision == 0 && ft_strlen(num) == 2)
		num[1] = '\0';
	fs->np = ft_max((fs->precision - (int)ft_strlen(num)), 0);
	fs->nw = ft_max(fs->width - ((int)ft_strlen(num) + fs->np +
	fs->flag_tem_sinal + 4), 0);
	if (!fs->flag_tem_sinal)
		ft_print_n_chars(fs->nw, fs->pad);
	else
		ft_pad_e(fs, p);
	ft_print_pads(2, fs);
	ft_printf("%s%s%+2.2d", num, "e", exp);
	ft_print_pads(3, fs);
}
