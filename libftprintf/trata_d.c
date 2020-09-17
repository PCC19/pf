/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:12:59 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/17 15:23:33 by pcunha           ###   ########.fr       */
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
	int nw;
	int np;

	// faz itoa do argumento
	p = va_arg(argumentos, long long int);
	p = parse_lhd(p,fs->length);
//		print_fs(*fs);
	// calcula num
	num = p < 0 ? ft_itoa(-p) : ft_itoa(p);
	if (p == 0 && fs->flag_printa_zero == 0) 
		*num = 0;
	// calcula sinal / prefixo
	if (fs->sinal == 0 && p > 0)
		fs->flag_tem_sinal = 0;
	//sig = (p <0 || fs->sinal !=0) ? 1 : 0;
	// calcula n pad do precision
	fs->precision = ft_max(fs->precision, 0);
	np = ft_max((fs->precision - (int)ft_strlen(num)),0);
	// calcula n pad do width
	nw = ft_max(fs->width - ((int)ft_strlen(num) + np + fs->flag_tem_sinal), 0);
//		printf("num: %s  np: %d   nw: %d  sig: %d\n",num,np,nw,sig);
	
	// PAD W ANTES DO SINAL
	if (fs->jus == 0 && (fs->pad ==' ' || (fs->flag_tem_sinal == 0 && p!=0)))
		print_n_chars(nw,' ');

	// IMPRIME PREFIXO / SINAL
	ft_imprime_sinal(p, fs);
	
	// PAD W APOS O SINAL
	if(fs->jus == 0 && fs->pad =='0')
	{
		if(fs->precision > 0)
			print_n_chars(nw,' ');
		else
		{
			if (fs->flag_printa_zero == 0 && p == 0)
				print_n_chars(nw,' ');
			else
			{
				if(np != 0)
					print_n_chars(nw,'0');
				else
				{
					if (fs->ponto == 0)
						print_n_chars(nw,'0');
					else
					{
						if (fs->flag_ast_neg == 1)
							print_n_chars(nw,'0');
						else
							if (fs->flag_tem_sinal == 0)
								print_n_chars(nw,' ');
					}
				}
			}
		}
	}
	/*
	// PAD W DEPOIS DO SINAL
	if (fs->jus == 0 && (fs->pad == '0') && fs->ponto == 0 && sig == 1)
	{
		if (fs->flag_printa_zero == 0)
			print_n_chars(nw,' ');
		else
			print_n_chars(nw,'0');
	}
	*/

	// imprime pad do precision
	print_n_chars(np,'0');
	// imprime num
	print_string(num);
	// imprime pad depois
	if (fs->jus == 1)
		print_n_chars(nw,' ');
	// atualiza contagem
	(*conta) += ft_strlen(num) + fs->flag_tem_sinal + nw + np;
	free(num);
}
// calcula num
	// calcula casos de 0
// calcula sinal
	// nada:	 "" / '-'
	// +:		"+" / '-'
	// ' ':		" " / '-'

// calcula pad de precision
	//						negativo	zero	positivo
	// * negativo
	// * zero
	// * positivo < num
	// * positivo > num
	// sem ponto
	// ponto vazio
	// ponto com 0
	// ponto positivo < num
	// ponto positibo > num

// calcula pad de width
	// width
	// -1(indef)
	// 0		
	// n menor que num (- sig num np)
	// n maior que num
	// se pad a esq: pode ser 0 ou ' '
	// se pad a dir: so ' '

// pad w | sinal | pad precision | num | pad w

