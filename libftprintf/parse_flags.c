/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:08:15 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/17 21:05:38 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int parse_flags(struct s_fs *fs, char **s)
{
	while(ft_is_in(**s,"-+ 0#"))
	{
		if (**s == '-')
			fs->jus = 1;
		if (**s == '+')
			fs->sinal = 1;
		if (**s == ' ' && fs->sinal == 0)
			fs->sinal = 2;
		if (**s == '0')
			fs->pad = '0';
		if (**s == '#')
			fs->prefixo = 1;
		(*s)++;
	}
	return 0;
}

int parse_ponto(char **s,struct s_fs *fs)
{

	if (**s == '.')
	{
		fs->ponto = 1;
		(*s)++;
	}
	return 0;
}

int parse_num(char **s,va_list arg, struct s_fs *fs)
{
	int aux;
	
	/*if (ft_is_in(**s,"*1234567890")==0)
		aux = -1;
	else*/
		aux = 0;
	while(ft_is_in(**s,"*1234567890"))
	{
		if (**s == '*')
		{
			aux = va_arg(arg, int);
			if (fs->ponto == 0 && aux < 0)
			{
				fs->jus = 1;
				aux = ft_abs(aux);
			}
			if (fs->ponto == 1 && aux < 0)
			{
				aux = 0;
				fs->flag_ast_neg = 1;
			}
		}
		if (ft_isdigit(**s))
			aux = 10*aux + (**s - '0');
		(*s)++;
	}
	return aux;
}

int parse_length(struct s_fs *fs,char **s)
{
	while(ft_is_in(**s,"lh"))
	{
		if (**s == 'l')
			fs->length+=1;
		if(**s == 'h')
			fs->length+=3;
		(*s)++;
	}
	return 0;
}

int parse_conversion(struct s_fs *fs,char **s)
{
	if(ft_is_in(**s,"csdiuxXpnfge"))
	{
		fs->conversion = **s;
	}
	return 0;
}

