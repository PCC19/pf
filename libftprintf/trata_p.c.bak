/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:57:17 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/08 15:22:42 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_prefix(char *num)
{
	char *tmp;

	tmp = ft_strjoin("0x",num);
	free(num);

	return tmp;
}

void trata_p(va_list argumentos, int *conta, struct s_fs *fs)
{
	long int p;
	char *num;
	int nw;
	int np;
	int sig;

    //debug("entrou !");
	fs->precision = ft_max(fs->precision, 0);
	// faz itoa do argumento
	p = va_arg(argumentos, long int);
	//printf("p:  %p\n",(void*)p);
	//printf("p:  %lu\n",p);
	//printf("Entrou!!!");
	num = converte(p,fs);
	sig = 0;
	// print prefixo 0x
	//num = ft_strjoin("0x",num);
	num = ft_prefix(num);
	// calcula pad do precision
	np = ft_max((fs->precision - (int)ft_strlen(num)),0);
	// calcula pad do width
	nw = ft_max(fs->width - ((int)ft_strlen(num) + np + sig), 0);
	//debug("num: %s  np: %d   nw: %d",num,np,nw);
	// se jus = 0 imprime pads antes
	if (fs->jus == 0)
		print_n_chars(nw,fs->pad);
	// imprime sinal
	//if (p<0)
	//	ft_putchar_fd('-',1);
	//else
	//	print_sinal(fs->sinal);
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
