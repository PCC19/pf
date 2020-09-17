/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:36:29 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/17 15:07:51 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

//#include "../dbg.h"
#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <stdlib.h>

struct s_fs {
	int jus;
	int sinal;
	char pad;
	int prefixo;
	int width;
	int ponto;
	int precision;
	int length;
	char conversion;
	int flag_printa_zero;
	int flag_ast_neg;
	char padw_char;
	char padp_char;
	int flag_tem_sinal;
};

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } s_parts;
} u_float_cast;

struct s_array {
	int *val;
	int n;
};

// FUNCOES DE DEBUG PARA APAGAR
void print_fs(struct s_fs s);
void print_array(int *arr, int n);
// ========================================
int ft_printf(const char *string, ...);
void init_fs(struct s_fs *p);
int parse_fs(struct s_fs *fs, char **s, va_list arg);
int parse_flags(struct s_fs *fs, char **s);
int parse_ponto(char **s,struct s_fs *fs);
int parse_num(char **s,va_list arg, struct s_fs *fs);
int parse_length(struct s_fs *fs,char **s);
int parse_conversion(struct s_fs *fs,char **s);
int parse_fs(struct s_fs *fs, char **s, va_list arg);
void	print_sinal(int sinal);
void print_n_chars(int n, char c);
void print_string(char *s);
char *converte(long unsigned int p, struct s_fs *fs);
void trata_d(va_list argumentos, int *conta, struct s_fs *fs);
void trata_c(va_list argumentos, int *conta, struct s_fs *fs);
void trata_s(va_list argumentos, int *conta, struct s_fs *fs);
void trata_u(va_list argumentos, int *conta, struct s_fs *fs);
void trata_x(va_list argumentos, int *conta, struct s_fs *fs);
void trata_p(va_list argumentos, int *conta, struct s_fs *fs);
void trata_n(va_list argumentos, int *conta, struct s_fs *fs); 
void trata_f(va_list argumentos, int *conta, struct s_fs *fs);
void trata_e(va_list argumentos, int *conta, struct s_fs *fs);
char *ftoa_int(float f);
char *ftoa_frac(float f);
void popula_array_i(int *arr, int n_arr, u_float_cast n); 
void popula_array_f(int *arr, int n_arr, u_float_cast n); 
char *bcd_to_string(int *aux, int n_aux);
char *ftoa(float f, int precision);
char *ft_round(char **si, char *sf, int p);
int ft_ajusta_carry(char *a, int i);

#endif
