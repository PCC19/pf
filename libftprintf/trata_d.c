/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:12:59 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/20 18:19:32 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int parse_lhd(long long int x, int length)
{
	if (length == 0)
		x = (int) x;
	if (length == 1)
		x = (long int) x;
	if (length == 2)
		x = (long long int) x;
	if (length == 3)
		x = (short int) x;
	if (length == 6)
		x = (signed char) x;
	return x;
}

void ft_imprime_sinal(long long int p, struct s_fs *fs)
{
	// calcula sinal
		// nada:	 "" / '-'
		// +:		"+" / '-'
		// ' ':		" " / '-'
	if (p<0)
		ft_putchar_fd('-',1);
	else
		print_sinal(fs->sinal);
}




void trata_d(va_list argumentos, int *conta, struct s_fs *fs)
{
	long long int p;
	char *num;

	// faz itoa do argumento
	p = va_arg(argumentos, long long int);
	p = parse_lhd(p,fs->length);
	// calcula num
	num = p < 0 ? ft_itoa(-p) : ft_itoa(p);
	if (p == 0 && fs->flag_printa_zero == 0) 
		*num = 0;
	// calcula sinal / prefixo
	if (fs->sinal == 0 && p >= 0)
		fs->flag_tem_sinal = 0;
	// calcula n pad do precision
	fs->np = ft_max((fs->precision - (int)ft_strlen(num)),0);
	// calcula n pad do width
	fs->nw = ft_max(fs->width - ((int)ft_strlen(num) + fs->np + fs->flag_tem_sinal), 0);
//		printf("num: %s  fs->np: %d   fs->nw: %d  sig: %d\n",num,fs->np,fs->nw,fs->flag_tem_sinal);
	//	print_fs(*fs);
	
	// PAD W ANTES DO SINAL
	ft_print_pads(0, fs);
	// IMPRIME PREFIXO / SINAL
	ft_imprime_sinal(p, fs);
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
// calcula num
	// calcula casos de 0
// calcula sinal
	// nada:	 "" / '-'
	// +:		"+" / '-'
	// ' ':		" " / '-'


// padw a | sinal | padw d| pad precision | num | padw

