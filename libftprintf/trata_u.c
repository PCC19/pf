/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:12:59 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/20 18:18:02 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

long long int unsigned parse_lhu(long long unsigned int x, int length)
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
void trata_u(va_list argumentos, int *conta, struct s_fs *fs)
{
	long long unsigned int p;
	char *num;

	num = NULL;
	// igual trata_d porem ignorando tratamento de sinal
	// faz itoa do argumento
	p = va_arg(argumentos, long long unsigned int);
	p = parse_lhu(p,fs->length);
	num = ft_itoa((unsigned)p);
	if (p == 0 && fs->flag_printa_zero == 0) 
		*num = 0;
	// calcula sinal / prefixo
	fs->flag_tem_sinal = 0;
	// calcula n pad do precision
	fs->np = ft_max((fs->precision - (int)ft_strlen(num)),0);
	// calcula n pad do width
	fs->nw = ft_max(fs->width - ((int)ft_strlen(num) + fs->np + fs->flag_tem_sinal), 0);
//		printf("num: %s  fs->np: %d   fs->nw: %d  sig: %d\n",num,fs->np,fs->nw,fs->flag_tem_sinal);
	//	print_fs(*fs);
	
	// PAD W ANTES DO SINAL
	ft_print_pads(0, fs);


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
