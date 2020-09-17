/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:49:35 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/10 18:47:40 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sinal(int sinal)
{
	if (sinal == 1)
		ft_putchar_fd('+',1);
	if (sinal == 2)
		ft_putchar_fd(' ',1);
}

void print_n_chars(int n, char c)
{
	if (n>0)
	{
		while(n-- > 0)
			ft_putchar_fd(c,1);
	}
}

void print_string(char *s)
{
	ft_putstr_fd(s,1);
/*
	char c;
	while (*s)
	{
		c = (char)*s;
		//ft_putchar_fd(c,1);
		//ft_putchar(c);
		write(1, s, 1);
		//printf("%c",c);
		s++;
	}
*/
}

char *converte(long unsigned int p, struct s_fs *fs)
{
	char *base;
	char *num;
	if (ft_is_in(fs->conversion,"xX"))
		p = (unsigned int)p;
	if (ft_is_in(fs->conversion,"xp"))
		base = "0123456789abcdef";
	if (fs->conversion == 'X')
		base = "0123456789ABCDEF";
	num = ft_itoa_base(p,base);
	return num;
}
