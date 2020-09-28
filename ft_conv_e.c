/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:52:44 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 11:23:03 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tira_ponto(char *s, int i)
{
	int j;
	int n;

	n = ft_strlen(s);
	if (i < n)
	{
		j = i;
		while (j < n - 1)
		{
			s[j] = s[j + 1];
			j++;
		}
	}
}

void	ft_round_e(char **s, int i)
{
	int		j;
	char	*tmp;

	if (((*s)[i + 1] > '5') || (((*s)[i + 1] == '5') && ((*s)[i] % 2 != 0)))
	{
		(*s)[i] = (*s)[i] + 1;
		j = ft_ajusta_carry((*s), i);
		if (j < 0)
		{
			tmp = ft_strjoin("1", *s);
			free(*s);
			*s = tmp;
		}
	}
	(*s)[i + 2] = 0;
}

void	ft_coloca_ponto(char *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		s[i] = s[i - 1];
		i--;
	}
	s[1] = '.';
}

void	ft_pad_e(struct s_fs *fs, double p)
{
	if (fs->pad == '0')
	{
		if (p < 0)
			ft_putchar_fd('-', 1);
		else
			ft_print_sinal(fs->sinal);
		ft_print_n_chars(fs->nw, fs->pad);
	}
	else
	{
		ft_print_n_chars(fs->nw, fs->pad);
		if (p < 0)
			ft_putchar_fd('-', 1);
		else
			ft_print_sinal(fs->sinal);
	}
}

void	ft_conv_e(va_list args, int *conta, struct s_fs *fs)
{
	double	p;
	char	*num;
	int		i;
	int		exp;

	p = va_arg(args, double);
	num = p < 0 ? ft_ftoa(-p, 20) : ft_ftoa(p, 20);
	fs->flag_tem_sinal = (p < 0 || fs->sinal != 0) ? 1 : 0;
	i = 0;
	while (num[i] != '.' && num[i] != 0)
		i++;
	exp = i - 1;
	ft_tira_ponto(num, i);
	if (fs->flag_ast_neg)
		fs->precision = 6;
	if (!fs->ponto)
	{
		fs->precision = 6;
		fs->width = 0;
	}
	ft_round_e(&num, fs->precision);
	ft_aux_e(fs, num, p, exp);
	(*conta) += ft_strlen(num) + fs->flag_tem_sinal + fs->nw + fs->np + 4;
	free(num);
}
