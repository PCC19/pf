/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:32:27 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:32:31 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
