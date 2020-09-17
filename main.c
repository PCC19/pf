/*#include "dbg.h"
#include <stdio.h>
#include <stdarg.h>
#include "./libft/libft.h"
*/
#include "./libftprintf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

#define PRINT printf
//#define PRINT ft_printf

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
		if (i>0) printf("_");
    }
    puts("");
}

int main(void)
{

	char *fs = "%s";
	int num = 17;
	
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
		
		//printf("aaaaaaaaa: \t\t");
		//printf("Teste ---> %d\n", printf(fs,teste));
		//printf("\n");

		//printf("bbbbbbbbb: \t\t");
		//ft_printf("Num: %d\n",num);
		//ft_printf(fs,teste);
		//ft_printf("Teste ---> %d\n", ft_printf(fs,teste));


	//printf("pf: %d\n", l);
	//ft_printf("ft: %d\n", l);

	//ft_printf("ft: %d\n",l);
	//printf("pf: %d\n",l);
	//ft_printf("ft: %.0d\n",l);
	//printf("pf: %.0d\n",l);
	//ft_printf("ft: %0.d\n",l);
	//printf("pf: %0.d\n",l);
	//ft_printf("ft: %0.0d\n",l);
	//printf("pf: %0.0d\n",l);
	//ft_printf("ft: %0d\n",l);
	//printf("pf: %0d\n",l);
	//printf("============\n");

/*
	a = -12;
	PRINT("%0d\n",a);
	PRINT("============\n");
	PRINT("%00d\n",a);
	PRINT("%01d\n",a);
	PRINT("%02d\n",a);
	PRINT("%03d\n",a);
	PRINT("%04d\n",a);
	PRINT("============\n");
	
	PRINT("%00.d\n",a);
	PRINT("%01.d\n",a);
	PRINT("%02.d\n",a);
	PRINT("%03.d\n",a);
	PRINT("%04.d\n",a);
	PRINT("============\n");

	PRINT("%00.0d\n",a);
	PRINT("%01.0d\n",a);
	PRINT("%02.0d\n",a);
	PRINT("%03.0d\n",a);
	PRINT("%04.0d\n",a);
	PRINT("============\n");

	PRINT("%00.1d\n",a);
	PRINT("%01.1d\n",a);
	PRINT("%02.1d\n",a);
	PRINT("%03.1d\n",a);
	PRINT("%04.1d\n",a);
	PRINT("============\n");

	PRINT("%00.3d\n",a);
	PRINT("%01.3d\n",a);
	PRINT("%02.3d\n",a);
	PRINT("%03.3d\n",a);
	PRINT("%04.3d\n",a);
	PRINT("============\n");
	
	PRINT("%00.5d\n",a);
	PRINT("%01.5d\n",a);
	PRINT("%02.5d\n",a);
	PRINT("%03.5d\n",a);
	PRINT("%04.5d\n",a);
	PRINT("============\n");
	*/
/*
// ======================================================
	char *teste[100];
	int x = -12;
	i = 0;

	teste[0] = "|%-d|   :";
	teste[1] = "|%- d|   :";
	teste[2] = "|%-+d|   :";

	teste[3] = "|%-3d|   :";
	teste[4] = "|%- 3d|   :";
	teste[5] = "|%-+3d|   :";

	teste[6] = "|%-03d|   :";
	teste[7] = "|%- 03d|   :";
	teste[8] = "|%-+03d|   :";

	teste[9] = "|%-0d|   :";
	teste[10] = "|%- 0d|   :";
	teste[11] = "|%-+0d|   :";

	teste[12] = "|%-.d|   :";
	teste[13] = "|%- .d|   :";
	teste[14] = "|%-+.d|   :";

	teste[15] = "|%-3.d|   :";
	teste[16] = "|%- 3.d|   :";
	teste[17] = "|%-+3.d|   :";

	teste[18] = "|%-03.d|   :";
	teste[19] = "|%- 03.d|   :";
	teste[20] = "|%-+03.d|   :";

	teste[21] = "|%-0.d|   :";
	teste[22] = "|%- 0.d|   :";
	teste[23] = "|%-+0.d|   :";
	
	teste[24] = "|%-.1d|   :";
	teste[25] = "|%- .1d|   :";
	teste[26] = "|%-+.1d|   :";

	teste[27] = "|%-3.1d|   :";
	teste[28] = "|%- 3.1d|   :";
	teste[29] = "|%-+3.1d|   :";

	teste[30] = "|%-03.1d|   :";
	teste[31] = "|%- 03.1d|   :";
	teste[32] = "|%-+03.1d|   :";

	teste[33] = "|%-0.1d|   :";
	teste[34] = "|%- 0.1d|   :";
	teste[35] = "|%-+0.1d|   :";
	
	teste[36] = "|%-.2d|   :";
	teste[37] = "|%- .2d|   :";
	teste[38] = "|%-+.2d|   :";

	teste[39] = "|%-3.2d|   :";
	teste[40] = "|%- 3.2d|   :";
	teste[41] = "|%-+3.2d|   :";

	teste[42] = "|%-03.2d|   :";
	teste[43] = "|%- 03.2d|   :";
	teste[44] = "|%-+03.2d|   :";

	teste[45] = "|%-0.2d|   :";
	teste[46] = "|%- 0.2d|   :";
	teste[47] = "|%-+0.2d|   :";

	teste[48] = "|%-.3d|   :";
	teste[49] = "|%- .3d|   :";
	teste[50] = "|%-+.3d|   :";

	teste[51] = "|%-3.3d|   :";
	teste[52] = "|%- 3.3d|   :";
	teste[53] = "|%-+3.3d|   :";

	teste[54] = "|%-03.3d|   :";
	teste[55] = "|%- 03.3d|   :";
	teste[56] = "|%-+03.3d|   :";

	teste[57] = "|%-0.3d|   :";
	teste[58] = "|%- 0.3d|   :";
	teste[59] = "|%-+0.3d|   :";

	teste[60] = "|%-.4d|   :";
	teste[61] = "|%- .4d|   :";
	teste[62] = "|%-+.4d|   :";

	teste[63] = "|%-3.4d|   :";
	teste[64] = "|%- 3.4d|   :";
	teste[65] = "|%-+3.4d|   :";

	teste[66] = "|%-03.4d|   :";
	teste[67] = "|%- 03.4d|   :";
	teste[68] = "|%-+03.4d|   :";

	teste[69] = "|%-0.4d|   :";
	teste[70] = "|%- 0.4d|   :";
	teste[71] = "|%-+0.4d|   :";

	while(i < 72)
	{

		PRINT("n: %d\t",PRINT(teste[i],x)-6);
		PRINT("   %s   ",teste[i]);
		PRINT("\n");
		PRINT("n: %d\t",PRINT(teste[i+1],x)-6);
		PRINT("   %s   ",teste[i+1]);
		PRINT("\n");
		PRINT("n: %d\t",PRINT(teste[i+2],x)-6);
		PRINT("   %s   ",teste[i+2]);
		PRINT("\n");
		PRINT("\n--------\n");
		i+=3;
	}
// ======================================================
*/

	printf("pf:|%d|\n",0);
	printf("pf:|%.d|\n",0);
	printf("pf:|%.0d|\n",0);
	printf("=========\n");
	printf("pf:|%.d|\n",0);
	printf("pf:|%.0d|\n",0);
	printf("pf:|%0.d|\n",0);
	printf("pf:|%0.d|\n",0);

	printf("pf:|%.d|\n",123);
	printf("pf:|%.0d|\n",123);
	printf("pf:|%0.d|\n",123);
	printf("pf:|%0.d|\n",123);


	printf("pf:|%.d|\n",-123);
	printf("pf:|%.0d|\n",-123);
	printf("pf:|%0.d|\n",-123);
	printf("pf:|%0.d|\n",-123);

	char *teste[100];
	int x;
	int wid, prec;

	teste[0] = "|%*.*d|   :";
	teste[1] = "|%0*.*d|   :";
	teste[2] = "|% *.*d|   :";
	teste[3] = "|%+*.*d|   :";
	
	int xx[10];
	xx[0] = 0;
	xx[1] = 123;
	xx[2] = -123;

	j = 0;
	for (wid = -6; wid < 7; wid++)
	{

		for (prec = -6;prec < 7; prec ++)
		{
			i = 0;
			for (j = 0; j < 3; j++)
			{	
				PRINT("\t\t\tn: %d wid:%d prec:%d\t",PRINT(teste[i],wid,prec,xx[j])-6,wid,prec);
				PRINT("   %s   ",teste[i]);
				PRINT("\n");
			}
			i++;
			for (j = 0; j < 3; j++)
			{	
				PRINT("\t\t\tn: %d wid:%d prec:%d\t",PRINT(teste[i],wid,prec,xx[j])-6,wid,prec);
				PRINT("   %s   ",teste[i]);
				PRINT("\n");
			}
			i++;
			for (j = 0; j < 3; j++)
			{	
				PRINT("\t\t\tn: %d wid:%d prec:%d\t",PRINT(teste[i],wid,prec,xx[j])-6,wid,prec);
				PRINT("   %s   ",teste[i]);
				PRINT("\n");
			}
			i++;
			for (j = 0; j < 3; j++)
			{	
				PRINT("\t\t\tn: %d wid:%d prec:%d\t",PRINT(teste[i],wid,prec,xx[j])-6,wid,prec);
				PRINT("   %s   ",teste[i]);
				PRINT("\n");
			}
			i++;
			PRINT("\n--------\n");
		}
	}
}
/*
	PRINT("%3d\n",0);
	PRINT("% 3d\n",0);
	PRINT("%+3d\n",0);
	PRINT("--------\n");

	PRINT("%03d\n",0);
	PRINT("% 03d\n",0);
	PRINT("%+03d\n",0);
	PRINT("--------\n");

	PRINT("%0d\n",0);
	PRINT("% 0d\n",0);
	PRINT("%+0d\n",0);
	PRINT("--------\n");
	PRINT("--------\n");

	PRINT("%.d\n",0);
	PRINT("% .d\n",0);
	PRINT("%+.d\n",0);
	PRINT("--------\n");

	PRINT("%3.d\n",0);
	PRINT("% 3.d\n",0);
	PRINT("%+3.d\n",0);
	PRINT("--------\n");

	PRINT("%03.d\n",0);
	PRINT("% 03.d\n",0);
	PRINT("%+03.d\n",0);
	PRINT("--------\n");

	PRINT("%0.d\n",0);
	PRINT("% 0.d\n",0);
	PRINT("%+0.d\n",0);
	PRINT("--------\n");

*/


/*
	a = 1;
	b = 0;
	int n1 = 8;
	int n2 = 0;

	ft_printf("ft:%0*.*d\n",a,b,n1);
	printf("pf:%0*.*d\n",a,b,n1);
	printf("============\n");

	ft_printf("ft:%0*.*d\n",a,b,n2);
	printf("pf:%0*.*d\n",a,b,n2);
	printf("============\n");



	int nt = 187;
	a = -4;
	while (a < 5) //T187-213
	{
		PRINT(" --- Return : %d\n", PRINT("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		printf(" --- Return : %d\n", printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		printf("-- nt:  %d %d %d ----------------\n", nt++, a, b);
		PRINT(" --- Return : %d\n", PRINT("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		printf(" --- Return : %d\n", printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		printf("-- nt:  %d %d %d ----------------\n", nt++, a, b);
		PRINT(" --- Return : %d\n", PRINT("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		printf(" --- Return : %d\n", printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		printf("-- nt:  %d %d %d ----------------\n", nt++, a, b);
		a++;
	}

	nt = 214;
	a = -1;
	while (a < 5) //T214-256
	{
		PRINT(" --- Return : %d\n", PRINT("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		printf(" --- Return : %d\n", printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		printf("-- nt:  %d %d %d ----------------\n", nt++, a, b);
		PRINT(" --- Return : %d\n", PRINT("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		printf(" --- Return : %d\n", printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		printf("-- nt:  %d %d %d ----------------\n", nt++, a, b);
		PRINT(" --- Return : %d\n", PRINT("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		printf(" --- Return : %d\n", printf("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		printf("-- nt:  %d %d %d ----------------\n", nt++, a, b);
		PRINT(" --- Return : %d\n", PRINT("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		printf(" --- Return : %d\n", printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		printf("-- nt:  %d %d %d ----------------\n", nt++, a, b);
		a++;
	}
}


	int contagem = 0;
	
	int xx = atoi("-+10");
	int yy = atoi("010.5dafds");
	printf("%d\n",xx);
	printf("%d\n",yy);

	char c = 'X';
	char *s = "kwxyz";
	char *t = "Tes %c te %s\n";
	printf("ft_printf =============\n");
	contagem = ft_printf(t,c,s);
	debug("caracteres escritos: %d",contagem);
	printf("printf ===========\n");
	contagem = printf(t,c,s);
	debug("caracteres escritos: %d",contagem);

// ######################################################	
	char *teste_s[100];
	int i = 0;
	teste_s[0] = "%15s\n";
	teste_s[1] = "%-15s\n";
	teste_s[2] = "%015s\n";
	teste_s[3] = "% 15s\n";
	teste_s[4] = "%15s\n";
	teste_s[5] = "%15.6s\n";
	teste_s[6] = "%015.6s\n";
	teste_s[7] = "%-015.6s\n";
	teste_s[8] = "%-15.6s\n";
	teste_s[9] = "%- 15.6s\n";
	int n = 10;
	while (i<n)
	{

		printf("\n");
		printf("teste_s %d\n",i);
		debug("   printf: ");
		contagem = printf(teste_s[i],s);
		printf("contagem: %d\n",contagem);
		debug("ft_printf: ");
		contagem = ft_printf(teste_s[i],s);
		printf("contagem: %d\n",contagem);
		printf("\n==================================\n");
		i++;
	}
// ######################################################	
	
	char *tested[100];
	int x[100];
	i = 0;
	tested[0] = "%hd\n"; x[0] = -234;
	tested[1] = "%+hd\n"; x[1] = -234;
	tested[2] = "%-hd\n"; x[2] = -234;
	tested[3] = "% hd\n"; x[3] = -234;
	tested[4] = "%+ hd\n"; x[4] = -234;
	tested[5] = "%- hd\n"; x[5] = -234;
	tested[6] = "%20.10hd\n"; x[6] = -234;
	tested[7] = "%+20.10hd\n"; x[7] = -234;
	tested[8] = "%-+20.10hd\n"; x[8] = -234;
	tested[9] = "%- 20.10hd\n"; x[9] = -234;
	n = 10;
	while (i<n)
	{

		printf("\n");
		printf("tested %d\n",i);
		debug("   printf: ");
		contagem = printf(tested[i],(short int)x[i]);
		printf("contagem: %d\n",contagem);
		debug("ft_printf: ");
		contagem = ft_printf(tested[i],(short int)x[i]);
		printf("contagem: %d\n",contagem);
		printf("\n==================================\n");
		i++;
	}
// ######################################################	
	
	char *testeu[100];
	
	i = 0;
	testeu[0] = "%hu\n"; x[0] = 234;
	testeu[1] = "%+hu\n"; x[1] = 234;
	testeu[2] = "%-hu\n"; x[2] = 234;
	testeu[3] = "% hu\n"; x[3] = 234;
	testeu[4] = "%+ hu\n"; x[4] = 234;
	testeu[5] = "%- hu\n"; x[5] = 234;
	testeu[6] = "%20.10hu\n"; x[6] = 234;
	testeu[7] = "%+20.10hu\n"; x[7] = 234;
	testeu[8] = "%-+20.10hu\n"; x[8] = 234;
	testeu[9] = "%- 20.10hu\n"; x[9] = 234;
	n = 10;
	while (i<n)
	{

		printf("\n");
		printf("testeu %d\n",i);
		debug("   printf: ");
		contagem = printf(testeu[i],(unsigned short int)x[i]);
		printf("contagem: %d\n",contagem);
		debug("ft_printf: ");
		contagem = ft_printf(testeu[i],(unsigned short int)x[i]);
		printf("contagem: %d\n",contagem);
		printf("\n==================================\n");
		i++;
	}
	
// ######################################################	
	
	char *testex[100];
	
	i = 0;
	testex[0] = "%X\n"; x[0] = 234;
	testex[1] = "%+X\n"; x[1] = 234;
	testex[2] = "%-X\n"; x[2] = 234;
	testex[3] = "% X\n"; x[3] = 234;
	testex[4] = "%+ X\n"; x[4] = 234;
	testex[5] = "%- X\n"; x[5] = 234;
	testex[6] = "%20.10X\n"; x[6] = 234;
	testex[7] = "%+20.10X\n"; x[7] = 234;
	testex[8] = "%-+20.10X\n"; x[8] = 234;
	testex[9] = "%- 20.10X\n"; x[9] = 234;
	testex[10] = "%X\n"; x[10] = -234;
	testex[11] = "%+X\n"; x[11] = -234;
	testex[12] = "%-X\n"; x[12] = -234;
	testex[13] = "% X\n"; x[13] = -234;
	testex[14] = "%+ X\n"; x[14] = -234;
	testex[15] = "%- X\n"; x[15] = -234;
	testex[16] = "%20.10X\n"; x[16] = -234;
	testex[17] = "%+20.10X\n"; x[17] = -234;
	testex[18] = "%-+20.10X\n"; x[18] = -234;
	testex[19] = "%- 20.10X\n"; x[19] = -234;
	testex[20] = "%#X\n"; x[20] = -234;
	testex[21] = "%#X\n"; x[21] = 234;
	testex[22] = "%X\n"; x[22] = 0;
	testex[23] = "%#X\n"; x[23] = 0;
	testex[24] = "%#2.1X\n"; x[24] = -234;
	testex[25] = "%#2.1X\n"; x[25] = 234;
	testex[26] = "%2.1X\n"; x[26] = 0;
	testex[27] = "%#2.1X\n"; x[27] = 0;
	n = 28;
	while (i<n)
	{

		printf("\n");
		printf("testex %d\n",i);
		debug("   printf: ");
		contagem = printf(testex[i],x[i]);
		printf("contagem: %d\n",contagem);
		debug("ft_printf: ");
		contagem = ft_printf(testex[i],x[i]);
		printf("contagem: %d\n",contagem);
		printf("\n==================================\n");
		i++;
	}
// ######################################################	
	
	char *testep[100];
	int *xp[100];	
	i = 0;
	testep[0] = "%p\n"; xp[0] = &i;
	testep[1] = "%+p\n"; xp[1] = &i;
	testep[2] = "%-p\n"; xp[2] = &i;
	testep[3] = "% p\n"; xp[3] = &i;
	testep[4] = "%+ p\n"; xp[4] = &i;
	testep[5] = "%- p\n"; xp[5] = &i;
	testep[6] = "%20.10p\n"; xp[6] = &i;
	testep[7] = "%+20.10p\n"; xp[7] = &i;
	testep[8] = "%-+20.10p\n"; xp[8] = &i;
	testep[9] = "%- 20.10p\n"; xp[9] = &i;
	testep[10] = "%p\n"; xp[10] = &i;
	testep[11] = "%+p\n"; xp[11] = &i;
	testep[12] = "%-p\n"; xp[12] = &i;
	testep[13] = "% p\n"; xp[13] = &i;
	testep[14] = "%+ p\n"; xp[14] = &i;
	testep[15] = "%- p\n"; xp[15] = &i;
	testep[16] = "%20.10p\n"; xp[16] = &i;
	testep[17] = "%+20.10p\n"; xp[17] = &i;
	testep[18] = "%-+20.10p\n"; xp[18] = &i;
	testep[19] = "%- 20.10p\n"; xp[19] = &i;
	n = 20;
	while (i<n)
	{

		printf("\n");
		printf("testep %d\n",i);
		debug("   printf: ");
		contagem = printf(testep[i],xp[i]);
		printf("contagem: %d\n",contagem);
		debug("ft_printf: ");
		contagem = ft_printf(testep[i],xp[i]);
		printf("contagem: %d\n",contagem);
		printf("\n==================================\n");
		i++;
	}

	printf("tamanho ponteiro int: %lu\n",sizeof(int*));
	printf("tamanho lu int: %lu\n",sizeof(long int));
	long int xy = 140732876678612;
	char *ttt = ft_itoa_base(xy,"0123456789abcdef");
	printf("teste dec: %lu\n",xy);
	printf("teste hex: %s\n",ttt);

	char *testen = "abcde %nabcde %n\n";
	int n1;
	int n2;
	n1 = 1;
	n2 = 2;
		printf("\n");
		printf("testen %d\n",0);
		debug("   printf: ");
		contagem = printf(testen,&n1,&n2);
		printf("n1: %d  n2: %d\n",n1,n2);
		printf("contagem: %d\n",contagem);
		n1 =1; n2 = 2;
		debug("ft_printf: ");
		contagem = ft_printf(testen,&n1,&n2);
		printf("contagem: %d\n",contagem);
		printf("n1: %d  n2: %d\n",n1,n2);
		printf("\n==================================\n");

        i = 23;
		long int ui = UINT_MAX;
        float f = 16.00f;
        printBits(sizeof(i), &i);
		printf("\n");
        printBits(sizeof(ui), &ui);
		printf("\n");
		for (f = 0;f<=16;f=f+1)
		{
			printf("%f :\t",f);
			i = f;
			//printBits(sizeof(i), &i);
			printBits(sizeof(f), &f);
			printf("\n");
		}
		
		
// --------------------------------------------------	  
		
		float ff = 0;
		char *aaa;
		ff = 12.123;
		printf(" === FTOA_INT ===\n");
//		printf("\n ff: %5.10e \n", ff);
//		printf("\n ff: %e \n", ff/10.0);

		aaa = ftoa_int(ff);
		printf("printf:%5.2f\n",ff);
		printf("out:\t%s\n",aaa);

		//ff = 12345.123;
		ff = -123.12345;
		printf(" === FTOA_FRAC ===\n");
		printf("\n ff: %10.10e \n", ff);
		printf("\n ff: %e \n", ff/10.0);

		aaa = ftoa_frac(ff);
		printf("%0.10f\n",ff);
		printf("%0.9f\n",ff);
		printf("%0.8f\n",ff);
		printf("%0.7f\n",ff);
		printf("%0.6f\n",ff);
		printf("%0.5f\n",ff);
		printf("%0.2f\n",ff);
		printf("%0.1f\n",ff);
		printf("%0.0f\n",ff);
		printf("out: %s\n",aaa);


		//ff = 123.456;
		//aaa = ftoa(ff,4);
		//printf("===== FTOA =======\n");
		//printf("printf:\t\t%.4f\n",ff);
		//printf("out:\t\t%s\n",aaa);

// --------------------------------------------------	  
// ######################################################	
	
	char *testef[100];
	float xf[100];	
	float fff = 123.49;

	i = 0;
	testef[0] = "%f\n"; xf[0] = fff;
	testef[1] = "%+f\n"; xf[1] = fff;
	testef[2] = "%-f\n"; xf[2] = fff;
	testef[3] = "% f\n"; xf[3] = fff;
	testef[4] = "%+ f\n"; xf[4] = fff;
	testef[5] = "%- f\n"; xf[5] = fff;
	testef[6] = "%20.10f\n"; xf[6] = fff;
	testef[7] = "%+20.10f\n"; xf[7] = fff;
	testef[8] = "%-+20.10f\n"; xf[8] = fff;
	testef[9] = "%- 20.10f\n"; xf[9] = fff;
	testef[10] = "%f\n"; xf[10] = fff;
	testef[11] = "%+f\n"; xf[11] = fff;
	testef[12] = "%-f\n"; xf[12] = fff;
	testef[13] = "% f\n"; xf[13] = fff;
	testef[14] = "%+ f\n"; xf[14] = fff;
	testef[15] = "%2.0f\n"; xf[15] = fff;
	testef[16] = "%2.1f\n"; xf[16] = fff;
	testef[17] = "%+2.2f\n"; xf[17] = fff;
	testef[18] = "%-+2.3f\n"; xf[18] = fff;
	testef[19] = "%- 2.4f\n"; xf[19] = fff;
	
	testef[20] = "%.0f\n"; xf[20] = 123.4;
	testef[21] = "%.0f\n"; xf[21] = 123.5;
	testef[22] = "%.0f\n"; xf[22] = 123.41;
	testef[23] = "%.0f\n"; xf[23] = 123.49;
	
	n = 24;
	while (i<n)
	{

		printf("\n");
		printf("testef %d\n",i);
		debug("   printf: ");
		contagem = printf(testef[i],xf[i]);
		printf("contagem: %d\n",contagem);
		debug("ft_printf: ");
		contagem = ft_printf(testef[i],xf[i]);
		printf("contagem: %d\n",contagem);
		printf("\n==================================\n");
		i++;
	}


// ######################################################	
	
	char *teste_e[100];
	float xe[100];	
	fff = 9.5678999;

	i = 0;
	teste_e[0] = "%e\n"; xe[0] = fff;
	teste_e[1] = "%+e\n"; xe[1] = fff;
	teste_e[2] = "%-e\n"; xe[2] = fff;
	teste_e[3] = "% e\n"; xe[3] = fff;
	teste_e[4] = "%+ e\n"; xe[4] = fff;
	teste_e[5] = "%- e\n"; xe[5] = fff;
	teste_e[6] = "%20.10e\n"; xe[6] = fff;
	teste_e[7] = "%+20.10e\n"; xe[7] = fff;
	teste_e[8] = "%-+20.10e\n"; xe[8] = fff;
	teste_e[9] = "%- 20.10e\n"; xe[9] = fff;
	teste_e[10] = "%e\n"; xe[10] = fff;
	teste_e[11] = "%+e\n"; xe[11] = fff;
	teste_e[12] = "%-e\n"; xe[12] = fff;
	teste_e[13] = "% e\n"; xe[13] = fff;
	teste_e[14] = "%+ e\n"; xe[14] = fff;
	teste_e[15] = "%2.0e\n"; xe[15] = fff;
	teste_e[16] = "%2.1e\n"; xe[16] = fff;
	teste_e[17] = "%+2.2e\n"; xe[17] = fff;
	teste_e[18] = "%-+2.3e\n"; xe[18] = fff;
	teste_e[19] = "%- 2.4e\n"; xe[19] = fff;
	
	teste_e[20] = "%20.0e\n"; xe[20] = fff;
	teste_e[21] = "%20.1e\n"; xe[21] = fff;
	teste_e[22] = "%20.2e\n"; xe[22] = fff;
	teste_e[23] = "%20.3e\n"; xe[23] = fff;
	
	n = 24;
	while (i<n)
	{

		printf("\n");
		printf("teste_e %d\n",i);
		printf("fs: %s\n",teste_e[i]);
		debug("   printf: ");
		contagem = printf(teste_e[i],xe[i]);
		printf("contagem: %d\n",contagem);
		debug("ft_printf: ");
		contagem = ft_printf(teste_e[i],xe[i]);
		printf("contagem: %d\n",contagem);
		printf("\n==================================\n");
		i++;
	}



		
	debug("==================");
	float ff = 9.5678999;
	printf("printf:\t\t%20.0e\n",ff);
	ft_printf("ftprintf:\t\t%20.0e\n",ff);
		ff = 124.05;
		for (i=0;i<30;i++)
		{
			ff = ff + 1.0/10;
			printf("ff: %2.2f %2.0f\n",ff,ff);
		}

		printf("GET BIT\n");
		printf("%d %d %d %d\n",get_bit(8,3), get_bit(8,2), get_bit(8,1), get_bit(8,0));
	
		for(i = 0; i<= 16; i++)
			debug("i: %d / 3 = %d , resto: %d",i,i/3, i%3);
*/



/*
	Flags podem vir em qqr ordem (criar um array de flags apos ler o %
para usar nas rotinas de formatacao ?)
	Rotina tem que gerar um novo string auxiliar. Se esse string da variavel ficar maior que especificacao dos fields, imprime ele mesmo, senao segue flags. Apaga string auxiliar
	Se sobrar variaveis nao tem problema. Se faltar compilador avisa e imprime lixo.
	Flag nao tem space, sempre termina com um char (excecao . apos f)
*/
/*	c - char ok
	s - string ok
	d - inteiro ok
	i - inteiro ok
	u - unsigned int ok
	x - hexadecimal ok
	p - end ponteiro (hexa) ok
	flags: "-0.*" (4)
	n -
	f - 
	g - 
	e - 
	flags: l ll h hh
	flags (all): "# +" (3)
csdiuxpnfge

*/
/*
- Le caracter ate \0
	- Se for normal, printa
	- Se for %
		- Captura flags
		- Captura comando
		- Processa comando (gera string aux)
		- Aplica flags (formata field etc)
		- Printa cada caracter do string aux
		- Destroi string aux
		- Volta para prox caracter do string
	
Numero:
%[flags][width][.precision][length]specifier
Numero ate . = width
numero apos . = precision
% [+- #0][num ou *][.num ou *][l/ll/h/hh] [c/s/d/i/u/x/X/p/n/f/g/e]
1) enquanto for flag, processa e anda
2) se for digito: processa width
	aux = aux * 10 (comecou com 0)
	aux = aux + digito
3) se for ponto: comeca a processar precision.
	aux2 = aux2 * 10 (comecou com 0)
	aux = aux + digito
4) Se for length l ou h, incrementa contador l ou h
5) Se for conversion: atualiza conversion
Trata conversion

fields:
justification: 0(default) = right. 1 = left
sinal: 0 = "" (printa so - nos negativos). 1 = "+" (printa sinal + de pos), 2 = " " (printa " " ao inves de +)
	conflito ?
pad: 1 = "" (default, pad com " "). 0 = 0 (faz padding com 0).
prefixo: 0 = "" (sem prefixo no x ou sem ponto). 1 = "#", (printa prefixo do x ou ponto decimal dos demais)
width: le do string ou da lista de argumentos (default 0)
precision: le do string ou da lista de argumentos (default 0)
length: 0 = "" (usa defaults de cada conversao)
ponteiro: * valor da lista de argumentos a ser processado (modificado por length)


================
Converte float (s/e/m) em binary string
	Ve tamanho do array para aguentar mantissa vs expoente
	Inicializa essa matriz com os valores binarios
	Aplica o Double Dabble
		1 Cria vetores gdes suficiente
		Transfere dos bits de mantissa para vetor
		Shifta vetores
		Rotina de pega vetor binario 4dig, converte pra int, soma 3 e converte pra bin
		Roda n shifts onde n eh o expoente.
		2 Pegar o que sobrou da mantissa para tratar separdo
			Bolar algoritmo double dabble para traz para ver se funciona
		3 Converter vetor string bcd em string decimal (converte blocos de 4 pra int e + '0' para char ?)


Converte binary string em digitos decimais usando double dabble
Como fazer parte fracionaria ? (algoritmo tipo itoa usando valor grande de int ?)

*/
