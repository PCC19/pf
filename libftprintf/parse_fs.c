/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:21:44 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/17 15:45:56 by pcunha           ###   ########.fr       */
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
		if(fs->ponto == 1 && fs->precision == 0)
			fs->flag_printa_zero = 0;
	}
	// LENGTH
	parse_length(fs,s);
	// CONVERSION
	parse_conversion(fs,s);
	// PAD_CHARS
	if (fs->precision < 0)
	{
		fs->padp_char = 0;
		fs->padw_char = fs->pad;
	}
	if (fs->precision >= 0)
	{
		fs->padp_char = '0';
		fs->padw_char = ' ';
	}

	return 0;
}
