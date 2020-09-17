/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:53:27 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/11 16:31:33 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		tamanho_da_base(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

static long int		ft_conta(long unsigned int n, long unsigned int nb)
{
	long unsigned int i;
	long unsigned int a;

	a = n;
	i = 1;
	while (a / nb != 0)
	{
		a = a / nb;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(long int n, char *base)
{
	int				i;
	char			*c;
	int				s;
	long unsigned int	nn;
	long unsigned int	nb;

	nn = (long unsigned int)n; 
	nb = (long unsigned int)tamanho_da_base(base);
	i = ft_conta(nn,nb);
	s = 0;
	c = (char *)malloc(i + 1 + s);
	if (c == NULL)
		return (NULL);
	c[i + s] = 0;
	while (i > 0)
	{
		c[i + s - 1] = base[nn % nb];
		nn = nn / nb;
		i--;
	}
	if (s == 1)
		c[0] = '-';
	return (c);
}

