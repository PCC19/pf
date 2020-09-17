/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:53:16 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/09 15:48:25 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_tira_ponto(char *s, int i)
{
	int j;
	int n;

	n = ft_strlen(s);

	if (i < n)
	{
		j = i;
		while (j < n-1)
		{
			s[j] = s[j+1];
			j++;
		}
	}
}

void ft_round_e(char **s, int i)
{
	int j;
	char *tmp;

	//debug("i: %d  entrada s: %s",i,*s);

	if (((*s)[i+1] > '5') || (((*s)[i+1] == '5') && ((*s)[i]%2 != 0)))
	{
		(*s)[i] = (*s)[i] + 1;
		//	debug("i: %d  entrada s: %s",i,*s);
		//(*s)[i+2] = 0;
		//	debug("i: %d  entrada s: %s",i,*s);
		j = ft_ajusta_carry((*s),i);
		//	debug("i: %d  entrada s: %s",i,*s);
		if (j < 0)
		{
			//debug("si a: %s",*si);
			//*s = ft_strjoin("1",*s);
			tmp = ft_strjoin("1",*s);
			free(*s);
			*s = tmp;
		}
	}
	(*s)[i+2] = 0;
	//debug("i: %d num round dentro: %s",i, *s);
}

void ft_coloca_ponto(char *s)
{
	int i;
	
	i = ft_strlen(s)-1;
	while(i>0)
	{
		s[i] = s[i-1];
		i--;
	}
	s[1] = '.';
}

void trata_e(va_list argumentos, int *conta, struct s_fs *fs)
{
	double p;
	char *num;
	int nw;
	int np;
	int sig;
	int i;
	int exp;

		(*conta)++; (*conta)--;
	//fs->precision = ft_max(fs->precision, 0);
	// faz cast do argumento como float
	p = va_arg(argumentos, double);
		//debug("p: %f",p);
	// Formata como float com maior precision possivel
	num = p < 0 ? ftoa(-p, 20) : ftoa(p, 20);
		//debug("precision: %d num: %s",fs->precision, num);
	sig = (p <0 || fs->sinal !=0) ? 1 : 0;
	// Ve onde esta o ponto
	i = 0;
	while(num[i] != '.' && num[i] != 0)
		i++;
		//debug("i do ponto: %d",i);
	// Conta quantas casas precisa mover o ponto (sera o expoente)
	exp = i - 1;
	// Tira o ponto
	ft_tira_ponto(num,i);
		//debug("num sem pto: %s",num);
	// Arredonda
	if (fs->precision == -1)
		fs->precision = 6;
	ft_round_e(&num, fs->precision);
		//debug("num: round %s",num);
		//debug("num round: %s",num);
	// Coloca o ponto no lugar certo 2
	if (fs-> precision > 0)
		ft_coloca_ponto(num);
		//debug("num pto: round %s",num);
	// se precision == 0 e num tem 2 chars
	if (fs->precision == 0 && ft_strlen(num) == 2)
		{
			num[1] = '\0';
			exp ++;
		}
		//debug("num com pto: %s",num);
	// calcula pad do precision
	np = ft_max((fs->precision - (int)ft_strlen(num)),0);
	// calcula pad do width
	//nw = ft_max((fs->width - MAX(fs->precision,(int)ft_strlen(num))),0);
	nw = ft_max(fs->width - ((int)ft_strlen(num) + np + sig + 4), 0);
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
	// imprime e
	print_string("e");
	// imprime expoente com sinal
	ft_printf("%+2.2d",exp);
	// imprime pad depois
	if (fs->jus == 1)
		print_n_chars(nw,' ');
	// atualiza contagem
	(*conta) += ft_strlen(num) + sig + nw + np + 4;
	free(num);
/*

0 1 2 3 4 5 6 7 8 9 0
1 2 3 . 5 9 9	p 3		d 2
1 2 3 4 5 6 7	p 7		d 6		
	debug("num: %s",num);
	*/
}
