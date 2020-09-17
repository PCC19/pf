/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 21:04:59 by pcunha            #+#    #+#             */
/*   Updated: 2020/08/21 16:33:17 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void trata_n(va_list argumentos, int *conta, struct s_fs *fs)
{
	if (fs->length == 0)
		*va_arg(argumentos,int *) = (int)*conta;
	if (fs->length == 1)
		*va_arg(argumentos,long int *) = (long int)*conta;
	if (fs->length == 2)
		*va_arg(argumentos,long long int *) = (long long int)*conta;
	if (fs->length == 3)
		*va_arg(argumentos,short int *) = (short int)*conta;
	if (fs->length == 6)
		*va_arg(argumentos,signed char *) = (signed char)*conta;
	
/*	
	int *p;

	p = va_arg(argumentos,int *);
	*p = *conta;
	fs->width ++; fs->width --;
*/

}

