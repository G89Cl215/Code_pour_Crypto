#ifndef TOUTES_FONCTIONS_H
# define TOUTES_FONCTIONS_H

# include <stdio.h>

void				anf(int *f, int n);
int				poids_binaire(unsigned long x);
int				ft_degre(unsigned long x);
void				Fourrier(int *f, int n);
void				Walsh(int *f, int n);
int				resilience_perso(int *f, int n);
int				dist_naive(int *f, int *g, int n);
int				dist1(int *f, int *g, int n);
int				dist2(int *f, int *g, int n);
unsigned int			NL(int *f, int n);
void				ft_print_base_bin(long unsigned int to_print);
void				ft_printpol(long unsigned int to_print);
int				ft_deg(long unsigned int a);
long unsigned int		POLSQR(long unsigned int a);
long unsigned int		POLMUL(long unsigned int a, long unsigned int b);
long unsigned int		POLMODDIV(long unsigned int *r, long unsigned int a, long unsigned int b);
long unsigned int		POLPOWERMOD(long unsigned int a, long unsigned int b);
unsigned long			GCD(unsigned long a, unsigned long b);

#endif
