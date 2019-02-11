#include "Toutes_fonctions.h"

void	Fourrier(int *f, int n)
{
	unsigned int	nn;
	unsigned int	jj;
	int		tmp;
	int		i;
	int		flag;

	nn = 1 << n;
	jj = nn >> 1;
	flag = 0;
	i = -1;
	while (jj > 0)
	{
		i = 0;
		while (i < nn)
		{
			if (!(flag))
			{
				tmp = f[i] - f[i + jj];
				f[i] += f[i + jj];
				f[i + jj] = tmp;
			}
			if (!((i + 1) % jj))
				flag = (flag) ? 0 : 1;
			i++;
		}
		jj >>= 1;
	}
}

void	Walsh(int *f, int n)
{
	unsigned int	nn;
	unsigned int	jj;
	int		tmp;
	int		i;
	int		flag;

	nn = 1 << n;
	jj = nn >> 1;
	flag = 0;
	i = -1;
	while (++i < (1 << n))
		f[i] = 1 - 2 * f[i];
	while (jj > 0)
	{
		i = 0;
		while (i < nn)
		{
			if (!(flag))
			{
				tmp = f[i] - f[i + jj];
				f[i] += f[i + jj];
				f[i + jj] = tmp;
			}
			if (!((i + 1) % jj))
				flag = (flag) ? 0 : 1;
			i++;
		}
		jj >>= 1;
	}
}

int	resilience_perso(int *f, int n)
{
	int	res;
	int	i;

	i = -1;
	Walsh(f, n);
	while (++i < (1 << n))
	{
		if (f[i] > 0)
			res++;
	}	
	return (res + 1);
}
/*
int	resilience_cor()
{
	int	r;
	int	w;
	int	i;

	r = n;
	Walsh(f, n);
	for (i = (1 << n) - 1, i >= 0, --i)
	{
		if (f[i]!= 0)
		{
			w = poids[i];
			if (w < r)
				r = w;
		}
	}	
	return (r (- 1));
}*/

