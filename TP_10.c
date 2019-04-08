#include <stdio.h>
#include "Toutes_fonctions.h"

unsigned long	mulmod(unsigned long a, unsigned long b, unsigned long n)
{
	a %= n;
	b %= n;
	a *= b;
	a %= n;
	return (a);
}

unsigned long	sqrmod(unsigned long a, unsigned long n)
{
	a %= n;
	a *= a;
	a %= n;
	return (a);
}

unsigned long	expmod(unsigned long a, unsigned long exp, unsigned long n)
{
	if (!(exp))
		return (1);
	if (exp % 2)
		return (mulmod(a, expmod(a, exp - 1, n), n));
	return (sqrmod(expmod(a, exp / 2, n), n));
}

int		Test(int n, int a)
{
	return (((n % 2) && (expmod(a, (n - 1) / 2, n) % n == ft_Legendre(a, n))));
}

int		main()
{
	printf("%lu \n", expmod(5, 596, 1234));
}
