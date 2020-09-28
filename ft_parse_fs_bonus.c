/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:33:50 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:33:51 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse_fs(struct s_fs *fs, char **s, va_list arg)
{
	int	w;
	int	conversion;

	w = 0;
	ft_parse_flags(fs, s);
	if (fs->ponto == 0)
		fs->width = ft_parse_num(s, arg, fs);
	ft_parse_ponto(s, fs);
	if (fs->ponto == 1)
	{
		fs->precision = ft_parse_num(s, arg, fs);
		if (fs->flag_ast_neg == 0 && fs->precision == 0)
			fs->flag_printa_zero = 0;
	}
	ft_parse_length(fs, s);
	conversion = ft_parse_conversion(fs, s);
	if (!conversion)
		fs->conversion = '@';
	return (0);
}
