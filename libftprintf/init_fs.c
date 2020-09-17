/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:44:48 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/17 15:24:14 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void init_fs(struct s_fs *p)
{
	p->jus = 0;
	p->sinal = 0;
	p->pad = ' ';
	p->prefixo = 0;
	p->width = -1;
	p->ponto = 0;
	p->precision = 0;
	p->length = 0;
	p->conversion = '\0';
	p->flag_printa_zero = 1;
	p->flag_ast_neg = 0;
	p->padw_char = ' ';
	p->padp_char = '0';
	p->flag_tem_sinal = 1;
}

/*
jus: 0 (default, justifica a direita). 1 = "-" (justifica a esquerda);

sinal: 0 (default, sinal so negativo). 1 = "+" (sinal + e - sempre). 2 = " " (sinal positivo eh SPC inves de +).
pad: ' ' = "" (default, pad com " "). 0 = '0' (faz padding com 0).
prefixo: 0 = "" (sem prefixo no x ou sem ponto). 1 = "#", (printa prefixo do x ou ponto decimal dos demais)

width: le do string ou da lista de argumentos (default -1)

ponto: flag para indicar se ha ponto (default = 0)

precision: le do string ou da lista de argumentos (default -1)

length: 0 = "" (usa defaults de cada conversao)
	l = 1; ll = 2; h = 3; hh = 6;

conversion: qual conversion fazer (i,d,u etc)

flag_flag_printa_zero: se zero nao printa o algarismo zero, caso contrario printa

flag_ast_neg: para saber se ha precision negativo quando entra via asterisco

pad[p|w]_char: caracateres que serao usados para padw e padp

flag_tem_sinal: flag indica se vai printar algum char de sinal nao (depende de
sinal e do numero ser positivo ou nao)


*/

