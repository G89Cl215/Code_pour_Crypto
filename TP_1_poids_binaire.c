#include "Toutes_fonctions.h"

int	poids_binaire(unsigned long x)
{
  int i;
  int res;

  res = 0;
  i = 0;
  while (i < 64)
  {
    if (((unsigned long)1 << i) & x)
      res++;
    i++;
  }
  return (res);
}

int	ft_degre(unsigned long x)
{
  int i = 1;
  int j = 0;
  int res;

  if (!(x))
    return (0);
  while (i < 64)
  {
    if (((((unsigned long)1 << i) - 1) ^ (((unsigned long)1 << (i - 1)) - 1)) & x)
      res = j;
    j++;
    i <<= 1;
  }
  return ((((unsigned long)1 << 63) & x) ? 8 : res);
}
/*
int main(int ac, char **av)
{
  long f = 2;
  printf("le degre %ld est : %d\n", f, ft_degre(f));
  return (0);
}*/
