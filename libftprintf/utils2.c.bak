/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:14:11 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/08 13:51:12 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void popula_bits(int *arr, int mantisa)
{
	int i;

	i = 0;
	while(i<23)
	{
		arr[i] = ft_get_bit(mantisa,i);
		i++;
	}
	arr[i] = 1;
}

void popula_array_i(int *arr, int n_arr, u_float_cast n)
{
	int i;
	int mantisa;
	
	mantisa = n.s_parts.mantisa;
	if (n.s_parts.exponent-127 > 0)
	{
		i = 0;
		while(i<n_arr-1)
		{
			if ((mantisa >> (i+24-n_arr) & 1))
			{
				arr[i] = 1;
			}
			i++;
		}
		arr[i] = 1;
	}
	else
	{
		popula_bits(arr, mantisa);
	/*
		i = 0;
		while(i<23)
		{
			arr[i] = get_bit(mantisa,i);
			i++;
		}
		arr[i] = 1;
	*/
	}
}

void popula_array_f(int *arr, int n_arr, u_float_cast n)
{
	int i;
	int mantisa;
	
	mantisa = n.s_parts.mantisa;
	i = 0;
	while(i<n_arr)
	{
		arr[i] = ft_get_bit(mantisa,i);
		i++;
	}
	arr[i] = 1;
}
