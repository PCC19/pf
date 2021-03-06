/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_frac_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:33:16 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:33:18 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_menos_tres(int *aux, int n_aux)
{
	int	j;
	int	valor;

	j = 0;
	valor = 0;
	j = n_aux - 1;
	while (j > 2)
	{
		valor = aux[j] * 8 + aux[j - 1] * 4 + aux[j - 2] * 2 + aux[j - 3];
		if (valor > 7)
		{
			valor = valor - 3;
			aux[j] = ((valor >> 3) & 1);
			aux[j - 1] = (valor >> 2) & 1;
			aux[j - 2] = (valor >> 1) & 1;
			aux[j - 3] = (valor >> 0) & 1;
		}
		j = j - 4;
	}
}

void	ft_shifta_d(int *aux, int *arr, int n_aux, int n_arr)
{
	ft_shift_right(aux, n_aux);
	aux[n_aux - 1] = arr[0];
	ft_shift_right(arr, n_arr);
}

void	ft_double_dabble_f(int *arr, int *aux, int n_arr, int n_aux)
{
	int	i;

	i = 0;
	while (i < n_arr - 1)
	{
		ft_menos_tres(aux, n_aux);
		ft_shifta_d(aux, arr, n_aux, n_arr);
		i++;
	}
	ft_menos_tres(aux, n_aux);
}

char	*ft_ftoa_frac(float f)
{
	t_float_cast	n;
	struct s_array	arr;
	struct s_array	aux;
	char			*out;

	n.f = (float)f;
	arr.n = 24 - (n.s_parts.exponent - 127);
	if (arr.n <= 0)
		return ("0");
	aux.n = ((arr.n / 3) * 4);
	if (arr.n % 3 > 0)
		aux.n += 4;
	aux.val = ft_calloc(aux.n, sizeof(int));
	arr.val = ft_calloc(arr.n, sizeof(int));
	ft_popula_array_f(arr.val, arr.n, n);
	ft_double_dabble_f(arr.val, aux.val, arr.n, aux.n);
	out = ft_bcd_to_string(aux.val, aux.n);
	free(aux.val);
	free(arr.val);
	return (out);
}
