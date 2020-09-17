/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:12:59 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/15 12:06:15 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int unsigned parse_lhx(long long int x, int length)
{
	if (length == 0)
		x = (unsigned int) x;
	if (length == 1)
		x = (unsigned long int) x;
	if (length == 2)
		x = (unsigned long long int) x;
	if (length == 3)
		x = (unsigned short int) x;
	if (length == 6)
		x = (unsigned char) x;
	return x;
}

void printa_ox(int p, struct s_fs *fs, int *conta )
{
	if (fs->prefixo == 1 && p != 0)
	{
		if (fs->conversion == 'x')
			print_string("0x");
		if (fs->conversion == 'X')
			print_string("0X");
	(*conta) += 2;
	}
}

void trata_x(va_list argumentos, int *conta, struct s_fs *fs)
{
	long long unsigned int p;
	char *num;
	int nw;
	int np;
	int sig;

	// faz itoa do argumento
	p = va_arg(argumentos, long long unsigned int);
	p = parse_lhx(p,fs->length);
	num = converte(p,fs);
	if (p == 0 && fs->flag_printa_zero == 0) 
		*num = 0;
	//num = p < 0 ? ft_itoa_base(-p,base) : ft_itoa_base(p,base);
	//sig = (p <0 || fs->sinal !=0) ? 1 : 0;
	sig = 0;
	// calcula pad do precision
	fs->precision = ft_max(fs->precision, 0);
	np = ft_max((fs->precision - (int)ft_strlen(num)),0);
	// calcula pad do width
	nw = ft_max(fs->width - ((int)ft_strlen(num) + np + sig), 0);
	if (fs->prefixo == 1 && p != 0 && nw > 2)
		nw -=2;
	//debug("num: %s  np: %d   nw: %d",num,np,nw);
	// se jus = 0 imprime pads antes
	if (fs->jus == 0)
		print_n_chars(nw,fs->pad);
	// imprime sinal
	//if (p<0)
	//	ft_putchar_fd('-',1);
	//else
	//	print_sinal(fs->sinal);
	// print prefixo 0x
	printa_ox(p, fs, conta);
	// imprime pad do precision
	print_n_chars(np,'0');
	// imprime num
	print_string(num);
	// imprime pad depois
	if (fs->jus == 1)
		print_n_chars(nw,' ');
	// atualiza contagem
	(*conta) += ft_strlen(num) + sig + nw + np;
	free(num);
}
