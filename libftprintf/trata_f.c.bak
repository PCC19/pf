/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:17:55 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/09 15:48:46 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void trata_f(va_list argumentos, int *conta, struct s_fs *fs)
{
	double p;
	char *num;
	int nw;
	int np;
	int sig;

	//fs->precision = ft_max(fs->precision, 0);
	// faz itoa do argumento
	p = va_arg(argumentos, double);
		//debug("p: %f",p);
	num = p < 0 ? ftoa(-p, fs->precision) : ftoa(p, fs->precision);
		//debug("precision: %d num: %s",fs->precision, num);
	sig = (p <0 || fs->sinal !=0) ? 1 : 0;
	// calcula pad do precision
	np = ft_max((fs->precision - (int)ft_strlen(num)),0);
	// calcula pad do width
	//nw = ft_max((fs->width - MAX(fs->precision,(int)ft_strlen(num))),0);
	nw = ft_max(fs->width - ((int)ft_strlen(num) + np + sig), 0);
		//debug("num: %s  np: %d   nw: %d",num,np,nw);
	// se jus = 0 imprime pads antes
	if (fs->jus == 0)
		print_n_chars(nw,fs->pad);
	// imprime sinal
	if (p<0)
		ft_putchar_fd('-',1);
	else
		print_sinal(fs->sinal);
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
