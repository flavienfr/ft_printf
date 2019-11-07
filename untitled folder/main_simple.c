#include "../ft_printf.h"
#include <stdio.h>

int main(void)
{
	char	a;
	char	b;
	char	*str;
	int		i;
	int		ret;
	int		ret2;
	unsigned int u;

	u = 0;
	a = 'a';
	b = 'b';
	str = "coucou";
	i = 42;
//	ret = printf("char : %c\nstr : %s\ni : %i or i : %d\n   printf : %p\nu : %u\nx : %X\n", a, str, i, i, &str, u, u);
//	ret2 = ft_printf("char : %c\nstr : %s\ni : %i or i : %d\nft_printf : %p\nu : %u\nx : %X\n", b, str, i, i, &str, u, u);
	ft_printf("ft_printf :%20i\n", i);
	fflush(0);
	printf("   printf :%20i\n", i);
	return (0);
}
