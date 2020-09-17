/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:45:03 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/10 14:22:38 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_printf(const char *string, ...)
{
// Scaneia caracater por caracter
// 1. Caracater normal: printa
// 2. %: parse do format string para uma struct
//		pega ultima char para saber qual tratamento fazer
//		chama funcao para fazer tratamento
//			gera string auxiliar
//		aplica flags dentro de cada tratamento ?
//			printa cada carcater da string auxiliar

	va_list argumentos;
	int conta;
	char *str;
	char *aux;
	struct s_fs ppp;
	
	str = (char *) malloc(sizeof(char)*ft_strlen(string)+1);
	ft_strlcpy(str,string,ft_strlen(string)+1);
	aux = str;

	va_start(argumentos,string);
	//debug("leu arg");
	//printf("string: %s\n",string);

	conta = 0;
	while(*str)
	{
		if (*str == '%')
		{
			str++;
			// ===========
			// Inserir bloco para capturar todas flags em uma struct antes de comecar a fazer os tratamentos.
				init_fs(&ppp);
	//				printf("==============\n");
	//				printf("antes parse: \n");
	//				print_fs(ppp);
				parse_fs(&ppp,&str,argumentos);
	//				printf("\nDepois parse: \n");
	//				print_fs(ppp);
	//				printf("%s\n",string);
			// ===========
			if (*str == 'c')
				trata_c(argumentos, &conta, &ppp);
			if (*str == 's')
				trata_s(argumentos, &conta, &ppp);
			if (*str == 'd' || *str == 'i')
				trata_d(argumentos, &conta, &ppp);
			if (*str == 'u')
				trata_u(argumentos, &conta, &ppp);
			if (*str == 'x' || *str == 'X')
				trata_x(argumentos, &conta, &ppp);
			if (*str == 'p')
				trata_p(argumentos, &conta, &ppp);
			if (*str == 'n')
				trata_n(argumentos, &conta, &ppp);
			if (*str == 'f')
				trata_f(argumentos, &conta, &ppp);
			if (*str == 'e')
				trata_e(argumentos, &conta, &ppp);
		}
		else
		{	
			ft_putchar_fd(*str,1);
			conta++;
		}
		str++;
	}
	va_end(argumentos);
	free(aux);
	return conta;
}
