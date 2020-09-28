/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:07:30 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/24 17:51:21 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_choose_conv(va_list args, int *conta, struct s_fs *fs, char *str)
{
	if (*str == 'c' || fs->conversion == '@')
		ft_conv_c(args, conta, fs, str);
	if (*str == 's')
		ft_conv_s(args, conta, fs);
	if (*str == 'd' || *str == 'i')
		ft_conv_d(args, conta, fs);
	if (*str == 'u')
		ft_conv_u(args, conta, fs);
	if (*str == 'x' || *str == 'X')
		ft_conv_x(args, conta, fs);
	if (*str == 'p')
		ft_conv_p(args, conta, fs);
	if (*str == 'n')
		ft_conv_n(args, conta, fs);
	if (*str == 'f')
		ft_conv_f(args, conta, fs);
	if (*str == 'e')
		ft_conv_e(args, conta, fs);
}
