/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:12:59 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/20 18:29:15 by pcunha           ###   ########.fr       */
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

	// faz itoa do argumento
	p = va_arg(argumentos, long long unsigned int);
	p = parse_lhx(p,fs->length);
	num = converte(p,fs);
	if (p == 0 && fs->flag_printa_zero == 0) 
		*num = 0;
	fs->flag_tem_sinal = 0;
	// calcula pad do precision
	fs->np = ft_max((fs->precision - (int)ft_strlen(num)),0);
	// calcula pad do width
	fs->nw = ft_max(fs->width - ((int)ft_strlen(num) + fs->np + fs->flag_tem_sinal), 0);
	if (fs->prefixo == 1 && p != 0 && fs->nw > 2)
		fs->nw -=2;
	//debug("num: %s  np: %d   nw: %d",num,np,nw);

	// PAD W ANTES DO SINAL
	ft_print_pads(0, fs);
	// print prefixo 0x
	printa_ox(p, fs, conta);
	// PAD W APOS O SINAL
	ft_print_pads(1, fs);
	// imprime pad do precision
	ft_print_pads(2, fs);
	// imprime num
	print_string(num);
	// imprime pad depois
	ft_print_pads(3, fs);
	//if (fs->jus == 1)
	//	print_n_chars(fs->nw,' ');//' '
	// atualiza contagem
	(*conta) += ft_strlen(num) + fs->flag_tem_sinal + fs->nw + fs->np;
//		printf("\t\t\tconta: %lu\n",(ft_strlen(num) + fs->flag_tem_sinal + fs->nw + fs->np));
	free(num);
}
