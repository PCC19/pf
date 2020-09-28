/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:32:47 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:32:48 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_pad_s(struct s_fs *fs, int n, char *p)
{
	if (fs->jus == 0)
		ft_print_n_chars(n, fs->pad);
	ft_print_string(p);
	if (fs->jus == 1)
		ft_print_n_chars(n, ' ');
}

void	ft_conv_s(va_list args, int *conta, struct s_fs *fs)
{
	char	*p;
	char	*pp;
	int		n;
	int		prec;

	n = 0;
	if (fs->length == 0)
		pp = va_arg(args, char *);
	else
		pp = (char*)va_arg(args, wchar_t *);
	if (pp == NULL)
		pp = "(null)";
	prec = (int)ft_strlen(pp);
	p = malloc(sizeof(char) * (prec + 1));
	if (fs->ponto && !fs->flag_ast_neg)
		prec = ft_min((int)ft_strlen(pp), fs->precision);
	ft_strlcpy(p, pp, prec + 1);
	if (fs->width > (int)ft_strlen(p))
		n = fs->width - ft_strlen(p);
	ft_pad_s(fs, n, p);
	(*conta) += fs->width > (int)ft_strlen(p) ? fs->width : (int)ft_strlen(p);
	free(p);
}
