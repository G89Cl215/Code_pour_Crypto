#include	"Toutes_fonctions.h"


void			eucl_step(unsigned long *a, unsigned long *b)
{
	unsigned long	tmp;

	tmp = *b;
	*b = *a % *b;
	*a = tmp;
}

unsigned long	GCD(unsigned long a, unsigned long b)
{
	unsigned long	gcd;

	while ((b))
	{
		gcd = b;
		eucl_step(&a, &b);
	}
	return (gcd);
}

void			POLeucl_step(unsigned long *a, unsigned long *b, unsigned long *quotient)
{
	long unsigned int	i;
	long unsigned int	q;
	long unsigned int	r;
	int					j;
	int					deg;

	i = 1;
	deg = ft_deg(*b);
	q = 0;
	r = *a;
	j = 64;
	while (j-- > deg)
	{
		if ((i << j) & *a)
		{
			r ^= *b << (j - deg);
			q |= i << (j - deg);
		}
	}
	*a = *b;
	*b = r;
	*quotient = q;
}

unsigned long	POLGCD(unsigned long a, unsigned long b)
{
	unsigned long	gcd;
	unsigned long	q;

	gcd = 1;	
	while ((b))
	{
		gcd = b;
		POLeucl_step(&a, &b, &q);
	}
	return (gcd);
}

unsigned long	POLinvMod(unsigned long a, unsigned long b)
{
	unsigned long	inv;
	unsigned long	q;


	inv = 0;	
	while ((b))
	{
		POLeucl_step(&a, &b, &q);
		inv ^= q;
	}
	inv ^= q;
	return (inv);
}

int				POLisIrr(unsigned long a)
{
	int				deg;
	int				ordre;
	unsigned long	Q;
	unsigned long	i;

	i = 1;
	ordre = 2;
	deg = ft_deg(a);
	while (ordre <= deg / 2)
	{
		Q = (1 << (i << ordre)) | 2;

		if (POLGCD(a, Q) == 1)
			ordre++;
		else
			return (0);
					ft_printpol(Q);
	}
	return ((POLGCD(a, 2 << (i << deg) + 2) == a));
}

int				main(void)
{
	unsigned long	a = 0x151;
	unsigned long	b = 0x2c1;
	unsigned long	c = 0x805;
	unsigned long	aes = 0x11b;	

	ft_printpol(aes);
	printf("Le polynome est-il irrecductible ?\n%d\n", POLisIrr(aes));
	return (0);
}
