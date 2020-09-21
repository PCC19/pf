/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:21:44 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/20 14:19:29 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int parse_fs(struct s_fs *fs, char **s, va_list arg)
{
	int w;
	w = 0;
	parse_flags(fs,s);
	// WIDTH
	if (fs->ponto == 0)
		fs->width = parse_num(s,arg, fs);
	// PONTO
	parse_ponto(s,fs);
	// PRECISION
	if (fs->ponto == 1)
	{
		fs->precision = parse_num(s,arg, fs);
		if(fs->flag_ast_neg == 0 && fs->precision == 0)
			fs->flag_printa_zero = 0;
	}
	// LENGTH
	parse_length(fs,s);
	// CONVERSION
	parse_conversion(fs,s);

	return 0;
}
