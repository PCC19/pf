/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:45:04 by pcunha            #+#    #+#             */
/*   Updated: 2020/09/28 13:05:11 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <wchar.h>
# include <unistd.h>
# include "./libft/libft.h"

struct					s_fs {
	int					jus;
	int					sinal;
	char				pad;
	int					prefixo;
	int					width;
	int					ponto;
	int					precision;
	int					length;
	char				conversion;
	int					nw;
	int					np;
	int					flag_printa_zero;
	int					flag_ast_neg;
	int					flag_tem_sinal;
};

typedef union			{
	float				f;
	struct		{
		unsigned int	mantisa:23;
		unsigned int	exponent:8;
		unsigned int	sign:1;
	}					s_parts;
}						t_float_cast;

struct					s_array {
	int					*val;
	int					n;
};

int						ft_printf(const char *string, ...);
void					ft_init_fs(struct s_fs *p);
int						ft_parse_fs(struct s_fs *fs, char **s, va_list arg);
int						ft_parse_flags(struct s_fs *fs, char **s);
int						ft_parse_ponto(char **s, struct s_fs *fs);
int						ft_parse_num(char **s, va_list arg, struct s_fs *fs);
int						ft_parse_length(struct s_fs *fs, char **s);
int						ft_parse_conversion(struct s_fs *fs, char **s);
int						ft_parse_fs(struct s_fs *fs, char **s, va_list arg);
void					ft_choose_conv(va_list args, int *conta,
		struct s_fs *fs, char *str);
void					ft_print_pads(int tipo_pad, struct s_fs *fs);
void					ft_print_sinal(int sinal);
void					ft_print_n_chars(int n, char c);
void					ft_print_string(char *s);
void					ft_printa_ox(int p, struct s_fs *fs, int *conta);
char					*ft_converte(long long unsigned int p, struct s_fs *fs);
void					ft_conv_d(va_list args, int *conta, struct s_fs *fs);
void					ft_conv_c(va_list args, int *conta, struct s_fs *fs,
		char *c);
void					ft_conv_s(va_list args, int *conta, struct s_fs *fs);
void					ft_conv_u(va_list args, int *conta, struct s_fs *fs);
void					ft_conv_x(va_list args, int *conta, struct s_fs *fs);
void					ft_conv_p(va_list args, int *conta, struct s_fs *fs);
void					ft_conv_n(va_list args, int *conta, struct s_fs *fs);
void					ft_conv_f(va_list args, int *conta, struct s_fs *fs);
void					ft_conv_e(va_list args, int *conta, struct s_fs *fs);
void					ft_aux_e(struct s_fs *fs, char *num, double p, int exp);
void					ft_coloca_ponto(char *s);
void					ft_pad_e(struct s_fs *fs, double p);
char					*ft_ftoa_int(float f);
char					*ft_ftoa_frac(float f);
void					ft_popula_array_i(int *arr, int n_arr, t_float_cast n);
void					ft_popula_array_f(int *arr, int n_arr, t_float_cast n);
char					*ft_bcd_to_string(int *aux, int n_aux);
char					*ft_ftoa(float f, int precision);
char					*ft_round(char **si, char *sf, int p);
int						ft_ajusta_carry(char *a, int i);

#endif
