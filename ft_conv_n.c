/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 21:04:59 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/25 17:30:25 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_n(va_list args, int *conta, struct s_fs *fs)
{
	if (fs->length == 0)
		*va_arg(args, int *) = (int)*conta;
	if (fs->length == 1)
		*va_arg(args, long int *) = (long int)*conta;
	if (fs->length == 2)
		*va_arg(args, long long int *) = (long long int)*conta;
	if (fs->length == 3)
		*va_arg(args, short int *) = (short int)*conta;
	if (fs->length == 6)
		*va_arg(args, signed char *) = (signed char)*conta;
}
