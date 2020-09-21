#include "ft_printf.h"

// FUNCAO PARA DEBUG !!!! APAGAR ANTES DA VERSAO FINAL
void print_array(int *arr, int n)
{
	// FUNCAO PARA DEBUG !!!! APAGAR ANTES DA VERSAO FINAL
	int i;

	i = n-1;
	while(i>=0)
	{
		printf("%c",arr[i]+'0');
		if (i%4 == 0 && i >0) printf("_");
		i--;
	}
}

void print_fs(struct s_fs s)
{
	printf("\n--------------------\n");
	printf("jus: %d\n", s.jus);
	printf("sinal: %d\n", s.sinal);
	printf("pad: \"%c\"\n", s.pad);
	printf("prefixo: %d\n", s.prefixo);
	printf("width: %d\n", s.width);
	printf("ponto: %d\n", s.ponto);
	printf("precision: %d\n", s.precision);
	printf("length: %d\n", s.length);
	printf("conversion: %c\n", s.conversion);
	printf("nw: %d\n", s.nw);
	printf("np: %d\n", s.np);
	printf("flag_printa_zero: %d\n", s.flag_printa_zero);
	printf("flag_ast_neg: %d\n", s.flag_ast_neg);
	//printf("padw_char: \"%c\"\n", s.padw_char);
	//printf("padp_char: \"%c\"\n", s.padp_char);
	printf("flag_tem_sinal: %d\n", s.flag_tem_sinal);
	printf("--------------------\n");
}

