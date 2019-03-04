# include <unistd.h>
# include <stdio.h>

void					ft_print_base_bin(long unsigned int to_print)
{
	char				ret[65];
	long unsigned int	i;
	int					j;

	i = 1;
	j = 64;
	while (j-- > 0)
		ret[63 - j] = (to_print & i << j) ? '1' : '0';
	ret[64] = '\n';
	write(1, ret, 65);
}

void					ft_printpol(long unsigned int to_print)
{
	long unsigned int	i;
	int					j;
	int					flag;

	i = 1;
	j = 64;
	flag = 0;
	while (j-- > 0)
		if (to_print & i << j)
		{
			if (j > 1)
				(flag++) ? printf(" + X ^ %d", j) : printf("X ^ %d", j);
			else if (j == 1)
				(flag) ? printf(" + X") : printf("X");
			else
				(flag) ? printf(" + 1") : printf("1");
		}
	printf("\n");
}

int						ft_deg(long unsigned int a)
{
	long unsigned int	i;
	int					deg;

	i = 1;
	deg = 63;
	while (!((i << deg) & a))
		deg--;
	return (deg);
}

long unsigned int		POLSQR(long unsigned int a)
{
	long unsigned int	i;
	long unsigned int	ret;
	int					j;

	i = 1;
	j = 0;
	ret = 0;
	while (j < 64)
	{
		if ((i << j) & a)
			ret |= (i << 2 * j);
		j++;
	}
	return (ret);
}

long unsigned int		POLMUL(long unsigned int a, long unsigned int b)
{
	long unsigned int	i;
	long unsigned int	ret;
	int					j;

	i = 1;
	j = 0;
	ret = 0;
	while (j < 64)
	{
		if ((i << j) & a)
				ret ^= (b << j);
		j++;
	}
	return (ret);
}

long unsigned int		POLMODDIV(long unsigned int *r, long unsigned int a, long unsigned int b)
{
	long unsigned int	i;
	long unsigned int	ret;
	int					j;
	int					deg;

	i = 1;
	deg = ft_deg(b);
	ret = 0;
	j = 64;
	while (j-- > deg)
	{
		if ((i << j) & a)
		{
			a ^= b << (j - deg);
			ret |= i << (j - deg);
		}
	}
	*r = a;
	return (ret);
}

long unsigned int		POLPOWERMOD(long unsigned int a, long unsigned int b)
{
	long unsigned int	i;
	long unsigned int	ret;
	int					j;
	int					deg_a;
	int					deg_b;

	i = 1;
	if (!(b % 2))
	{
		write(1, "MAUVAIS CHOIX DE B", 18);
	}
	deg_a = ft_deg(a);
	deg_b = ft_deg(b);
	ret = 0;
	j = 0;
	while (j < (deg_a - deg_b + 1))
	{
		if ((i << j) & a)
		{
			a ^= b << j;
			ret |= i << j;
		}
		j++;
	}
	return (ret);
}
/*
int main(void)
{
	long unsigned int	a = 0x1252;
	long unsigned int	b = 0x19;
//	long unsigned int	r[1];
	
	printf("%d \n", sizeof(long int));
	ft_printpol(b);
	ft_printpol(POLPOWERMOD(a, b));
//	ft_print_base_bin(*r);
	return (0);
}*/
