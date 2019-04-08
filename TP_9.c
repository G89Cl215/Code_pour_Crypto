#include "Toutes_fonctions.h"
#include <stdio.h>
#include <stdlib.h>

long		ft_pow(long exp)
{
	if (exp % 2)
		return (-1);
	return (1);
}


unsigned long	Euler_phi(unsigned long N)
{
	unsigned long	phi;
	unsigned long	i;

	phi = 1;
	i = 1;
	while (++i < N)
		if (GCD(i, N) == 1)
			phi++;
	return (phi);
}

unsigned long	*ft_sqr_tab(unsigned long N)
{
	unsigned long	i;
	unsigned long	*sqr_tab;

	i = 0;
	if (!(sqr_tab = (unsigned long *)malloc((N - 1) * sizeof(*sqr_tab))))
		return (NULL);
	while (++i < N)
		sqr_tab[i - 1] = (i * i) % N;
	return (sqr_tab);
}

unsigned long	*ft_sqr_res(unsigned long N)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;
	unsigned long	sqr;
	unsigned long	*res_tab;

	i = 0;
	k = 0;
	if (!(res_tab = (unsigned long *)malloc(N * sizeof(*res_tab))))
		return (NULL);
	while (++i < N)
	{
		j = 0;
		if (GCD(i, N) == 1)
		{
			sqr = (i * i) % N;
			while (j < k && res_tab[j] != sqr)
				j++;
			if (j == k)
				res_tab[k++] = sqr;
		}	
	}
	res_tab[k] = 0;
	return (res_tab);
}

long	ft_Legendre(long a, long p)
{
	if (a == 1)
		return (1);
	if ((a % 2))
		return (ft_Legendre(p % a, a) * ft_pow((a - 1) * (p - 1) / 4));
	return (ft_Legendre(a / 2, p) * ft_pow((p * p - 1) / 2));
}
/*
int main()
{
	unsigned long a = 35;
	unsigned long *tab;
	unsigned long	i;

	i = 0;
	tab = ft_sqr_res(a);
	while (++i < a && (tab[i - 1]))	
		printf("tab[%li] = %li\n", i, tab[i - 1]);
	free(tab);
	printf("legendre %li, mod %li, %li \n", 1, 7, ft_Legendre(1, 7));
	printf("legendre %li, mod %li, %li \n", 2, 7, ft_Legendre(2, 7));
	printf("legendre %li, mod %li, %li \n", 3, 7, ft_Legendre(3, 7));
	printf("legendre %li, mod %li, %li \n", 4, 7, ft_Legendre(4, 7));
}*/
