/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:19:00 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/08 15:33:02 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *pad_frac(char *sf, int *nf, int p)
{
	int i;
	char *str;
	char *tmp;

	str = sf;
	if (p - *nf > 0)
	{
		i = p - *nf;
		while (i>0)
		{
			//str = ft_strjoin(str,"0");
			tmp = ft_strjoin(str,"0");
			free(str);
			str = tmp;
			i--;
		}
		*nf = p;
	}
	return str;
}

int ft_ajusta_carry(char *a, int i)
{
	while (i > 0 && a[i] > '9')
	{
		a[i] = '0';
		a[i-1] = a[i-1] + 1;
			//debug("i: %d a[i]: %c",i,a[i]);
		i--;
	}
	if (a[i] > '9')
	{
		a[i] = '0';
			//debug("i: %d a[i]: %c",i,a[i]);
		i--;
	}
	//debug("i final %d",i);
	return i;
}

void ft_round_a(char **si, char *sf, int i, int ni)
{
	int j;
	char *tmp;

	if ((sf[i+1] > '5') || ((sf[i+1] == '5') && ((*si)[ni-1]%2 != 0)))
	{
		(*si)[ni-1] = (*si)[ni-1] + 1;
			//debug("a");
		j = ft_ajusta_carry(*si,ni-1);
		if (j < 0)
		{
			//*si = ft_strjoin("1",*si);
			tmp = ft_strjoin("1",*si);
			free(*si);
			*si = tmp;
		}
	}
}


void ft_round_b(char **si, char *sf, int i, int ni)
{
	int j;
	char *tmp;

	if ((sf[i+1] > '5') || ((sf[i+1] == '5') && (sf[i]%2 != 0)))
	{
		sf[i] = sf[i] + 1;
			//debug("b");
		j = ft_ajusta_carry(sf,i);
		if (j < 0)
		{
			(*si)[ni-1] = (*si)[ni-1] + 1;
				//debug("c");
			j = ft_ajusta_carry(*si,ni-1);
		}
		if (j < 0)
		{
			//debug("si a: %s",*si);
			tmp = ft_strjoin("1",*si);
			free(*si);
			*si = tmp;
		//	*si = ft_strjoin("1",*si);
		}
	}
}

char *ft_round(char **si, char *sf, int p)
{
	int nf;
	int ni;
	int i;

	nf = ft_strlen(sf);
	ni = ft_strlen(*si);
	sf = pad_frac(sf,&nf, p);
	i = p-1;
		//debug("ft_round: i: %d",i);
		//debug("si: %s  sf: %s   p: %d",*si,sf,p);
	if (i < 0)
	{
		ft_round_a(si, sf, i, ni);
		sf[i+1] = '\0';
	}
	else
	{
		ft_round_b(si, sf, i, ni);
		sf[i+1] = '\0';
	}
	return sf;
}
