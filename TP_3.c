#include "Toutes_fonctions.h"

int	dist_naive(int *f, int *g, int n)
{
	unsigned int	nn;
	int		sum;
	int		i;

	nn = 1 << n;
	i = -1;
	sum = 0;
	while (++i < nn)
		sum += (f[i] + g[i]) % 2;
	return (sum);
}

int	dist1(int *f, int *g, int n)
{
	unsigned int	nn;
	int		sum[1 << n];
	int		i;

	nn = 1 << n;
	i = -1;
	while (++i < nn)
		sum[i] = (f[i] + g[i]) % 2;
	for (i = 0; i < (1 << n); i ++) printf("|%d\t", sum[i]);
	printf("\n");
	Fourrier(sum, n);
	return (sum[0]);
}

int		dist2(int *f, int *g, int n)
{
	unsigned int	nn;
	int		sum[1 << n];
	int		i;

	nn = 1 << n;
	i = -1;
	while (++i < nn)
		sum[i] = (f[i] + g[i]) % 2;
	for (i = 0; i < (1 << n); i ++) printf("|%d\t", sum[i]);
	printf("\n");
	Walsh(sum, n);
	return ((1 << (n - 1)) - (sum[0] / 2));
}

unsigned int	NL(int *f, int n)
{
	int	i;
	int	nn;
	int	max_Walsh;
	
	nn = 1 << n;
	Walsh(f, n);
	max_Walsh = f[0];
	i = 0;
	while (++i < nn)
		if (f[i] > max_Walsh || f[i] < -max_Walsh)
		max_Walsh = (f[i] < 0) ? -f[i] : f[i];
	return ((1 << (n - 1)) - (max_Walsh / 2));
}


