/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:44:48 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/25 18:21:26 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_fs(struct s_fs *p)
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
	p->nw = 0;
	p->np = 0;
	p->flag_printa_zero = 1;
	p->flag_ast_neg = 0;
	p->flag_tem_sinal = 1;
}
