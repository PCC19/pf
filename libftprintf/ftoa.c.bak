/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 12:20:09 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/08 15:41:54 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ftoa(float f, int precision)
{

	char *str_i;
	char *str_f;
	char *str;
	char *tmp;
	
	str_i = ftoa_int(f);
	str_f = ftoa_frac(f);
	if (precision == -1)
		precision = 6;
	//str_f = ft_round(&str_i, str_f, precision);
	tmp = ft_round(&str_i, str_f, precision);
	free(str_f);
	str_f = tmp;
	str = str_i;
	free(str_i);
	if (precision > 0)
	{
		//str = ft_strjoin(str,".");
		tmp = ft_strjoin(str,".");
		free(str);
		str = tmp;
		//str = ft_strjoin(str,str_f);
		tmp = ft_strjoin(str,str_f);
		free(str);
		free(str_f);
		str = tmp;
	}
	return str;
}
