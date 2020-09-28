/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:49:35 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/25 18:51:39 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pads(int t, struct s_fs *fs)
{
	int a;

	a = fs->ponto;
	if (t == 0 && (fs->jus == 0 && (a || (!a && fs->pad == ' '))))
	{
		if (!(fs->ponto && fs->flag_ast_neg))
			ft_print_n_chars(fs->nw, ' ');
		if (fs->jus == 0 && fs->ponto && fs->flag_ast_neg && fs->pad == ' ')
			ft_print_n_chars(fs->nw, fs->pad);
	}
	if (t == 1 && fs->jus == 0 && !fs->ponto && fs->pad == '0')
		ft_print_n_chars(fs->nw, '0');
	if (t == 1 && fs->jus == 0 && t && fs->flag_ast_neg && fs->pad == '0')
		ft_print_n_chars(fs->nw, fs->pad);
	if (t == 2)
	{
		if (fs->ponto && !fs->flag_ast_neg)
			ft_print_n_chars(fs->np, '0');
	}
	if (t == 3)
	{
		if (fs->jus == 1)
			ft_print_n_chars(fs->nw, ' ');
	}
}

void	ft_print_sinal(int sinal)
{
	if (sinal == 1)
		ft_putchar_fd('+', 1);
	if (sinal == 2)
		ft_putchar_fd(' ', 1);
}

void	ft_print_n_chars(int n, char c)
{
	if (n > 0)
	{
		while (n-- > 0)
			ft_putchar_fd(c, 1);
	}
}

void	ft_print_string(char *s)
{
	ft_putstr_fd(s, 1);
}

void	ft_printa_ox(int p, struct s_fs *fs, int *conta)
{
	if (fs->prefixo && p != 0 && fs->conversion == 'x')
	{
		ft_print_string("0x");
		(*conta) += 2;
	}
	if (fs->prefixo && p != 0 && fs->conversion == 'X')
	{
		ft_print_string("0X");
		(*conta) += 2;
	}
	if (fs->prefixo && fs->conversion == 'p')
	{
		ft_print_string("0x");
		(*conta) += 2;
	}
}
