/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:13:10 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 11:13:14 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa(float f, int precision)
{
	char	*str_i;
	char	*str_f;
	char	*str;
	char	*tmp;
	char	*tmp2;

	str_i = ft_ftoa_int(f);
	str_f = ft_ftoa_frac(f);
	if (precision == -1)
		precision = 6;
	tmp = ft_round(&str_i, str_f, precision);
	str = ft_strjoin(str_i, ".");
	free(str_i);
	tmp2 = ft_strjoin(str, tmp);
	free(str);
	str = tmp2;
	free(tmp);
	return (str);
}
