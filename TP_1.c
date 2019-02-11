#include "Toutes_fonctions.h"

void  anf(int *f, int n)
{
  unsigned int  nn;
  unsigned int  jj;
  int           i;
  int           flag;

  nn = 1 << n;
  jj = nn;
  flag = 0;
  while (jj > 1)
  {
    jj >>= 1;
    i = 0;
    while (i < nn)
    {
      if (flag)
          f[i] =  (f[i] + f[i - jj]) % 2;
      if (!((i + 1) % jj))
        flag = (flag) ? 0 : 1;
        i++;
    }
  }
}
/*
int main()
{
  int f[16] = {0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  int n = 4;
  int i = 0;

  anf(f, n);
  for (i = 0; i < (1 << n); i ++) printf("%d", f[i]);
  printf("\n");
}*/
