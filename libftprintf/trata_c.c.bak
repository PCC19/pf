/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:00:53 by pcunha            #+#    #+#             */
/*   Updated: 2020/08/21 15:55:41 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void trata_c(va_list argumentos, int *conta, struct s_fs *fs)
{
	void *p;
	int n;

	if(fs->length == 1)
		p = va_arg(argumentos, wint_t *);
	else
		p = va_arg(argumentos, char *);
	// considerar width (pad com " ") > 1
	if (fs->width > 1)
	{
		// calcula width -1
		n = fs->width - 1;
		// se jus = 0 imprime pads antes
		if (fs->jus == 0)
			while (n-- >0)
				ft_putchar_fd(fs->pad,1);
	}
	ft_putchar_fd((char)p,1);
	if (fs->width > 1)
	{
		// se jus = 1 imprime " " depois (depois nao printa 0)
		if (fs->jus == 1)
			while (n-- > 0)
				ft_putchar_fd(' ',1);
	}
	fs->width > 1 ? (*conta) += fs->width : (*conta)++; 
}
