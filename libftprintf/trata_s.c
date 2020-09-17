/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trata_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:09:50 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/15 12:52:20 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void trata_s(va_list argumentos, int *conta, struct s_fs *fs)
{
	char *p;
	char *pp;
	int n;
	int prec;

	n = 0;
	if (fs->length == 0)
		pp = va_arg(argumentos,char *);
	else
		pp = (char* )va_arg(argumentos,wchar_t *);
			//print_fs(*fs);
	prec = (int)ft_strlen(pp);
	p = malloc(sizeof(char)*(prec+1));
	fs->precision = ft_max(fs->precision, 0);
	if (fs->precision > 0)
		prec = ft_min((int)ft_strlen(pp), fs->precision);
	//p = malloc(sizeof(pp)+1);
	ft_strlcpy(p,pp,prec+1);
		//printf("%s\n%s\n%d\n",p,pp,prec+1);
	if (fs->width > (int)ft_strlen(p))
		// calcula width -1
		n = fs->width - ft_strlen(p);
	if (fs->jus == 0)
		// se jus = 0 imprime pads antes
		print_n_chars(n,fs->pad);
	// Imprime argumento
	print_string(p);
	if(fs->jus == 1)
		// se jus = 1 imprime " " depois (depois nao printa 0)
		print_n_chars(n, ' ');
	(*conta) += fs->width > (int)ft_strlen(p) ? fs->width : (int)ft_strlen(p);
	free(p);
}
