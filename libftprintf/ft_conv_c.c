/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:52:34 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/24 18:02:00 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padc(struct s_fs *fs, int n)
{
	if (fs->jus == 0)
		while (n-- > 0)
			ft_putchar_fd(fs->pad, 1);
}

void	ft_conv_c(va_list args, int *conta, struct s_fs *fs, char *c)
{
	void	*p;
	int		n;

	p = 0;
	n = fs->width - 1;
	if (fs->conversion == 'c')
	{
		if (fs->length == 1)
			p = va_arg(args, wint_t *);
		else
			p = va_arg(args, char *);
	}
	if (fs->width > 1)
		ft_padc(fs, n);
	if (fs->conversion == '@')
		ft_putchar_fd(*c, 1);
	else
		ft_putchar_fd((char)p, 1);
	if (fs->width > 1)
	{
		if (fs->jus == 1)
			while (n-- > 0)
				ft_putchar_fd(' ', 1);
	}
	fs->width > 1 ? (*conta) += fs->width : (*conta)++;
}
