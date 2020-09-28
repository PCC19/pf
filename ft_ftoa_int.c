/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:13:27 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 11:15:19 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mais_tres(int *aux, int n_aux)
{
	int	j;
	int	valor;

	j = 0;
	valor = 0;
	j = n_aux - 1;
	while (j > 2)
	{
		valor = aux[j] * 8 + aux[j - 1] * 4 + aux[j - 2] * 2 + aux[j - 3];
		if (valor > 4)
		{
			valor = valor + 3;
			aux[j] = ((valor >> 3) & 1);
			aux[j - 1] = (valor >> 2) & 1;
			aux[j - 2] = (valor >> 1) & 1;
			aux[j - 3] = (valor >> 0) & 1;
		}
		j = j - 4;
	}
}

void	ft_shifta_e(int *aux, int *arr, int n_aux, int n_arr)
{
	ft_shift_left(aux, n_aux);
	aux[0] = arr[n_arr - 1];
	ft_shift_left(arr, n_arr);
}

void	ft_double_dabble_i(int *arr, int *aux, int n_arr, int n_aux)
{
	int	i;

	i = 0;
	while (i < n_arr)
	{
		ft_mais_tres(aux, n_aux);
		ft_shifta_e(aux, arr, n_aux, n_arr);
		i++;
	}
}

char	*ft_bcd_to_string(int *aux, int n_aux)
{
	int		i;
	int		j;
	int		valor;
	char	*out;

	out = (char *)malloc(n_aux / 4 * sizeof(char) + 1);
	valor = 0;
	i = n_aux - 1;
	j = 0;
	while (i > 2)
	{
		valor = aux[i] * 8 + aux[i - 1] * 4 + aux[i - 2] * 2 + aux[i - 3];
		if (valor != 0)
		{
			out[j] = valor + '0';
			j++;
		}
		i = i - 4;
	}
	out[j] = 0;
	return (out);
}

char	*ft_ftoa_int(float f)
{
	t_float_cast	n;
	struct s_array	arr;
	struct s_array	aux;
	char			*out;

	n.f = (float)f;
	if ((n.s_parts.exponent - 127) < 0)
	{
		out = ft_strjoin("", "0");
		return (out);
	}
	else
		arr.n = n.s_parts.exponent - 127 + 1;
	aux.n = ((arr.n / 3) * 4);
	if (arr.n % 3 > 0)
		aux.n += 4;
	aux.val = ft_calloc(aux.n, sizeof(int));
	arr.val = ft_calloc(arr.n, sizeof(int));
	ft_popula_array_i(arr.val, arr.n, n);
	ft_double_dabble_i(arr.val, aux.val, arr.n, aux.n);
	out = ft_bcd_to_string(aux.val, aux.n);
	free(aux.val);
	free(arr.val);
	return (out);
}
