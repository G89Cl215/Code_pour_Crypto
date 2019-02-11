#ifndef TOUTES_FONCTIONS_H
# define TOUTES_FONCTIONS_H

# include <stdio.h>

void		anf(int *f, int n);
int		poids_binaire(unsigned long x);
int		ft_degre(unsigned long x);
void		Fourrier(int *f, int n);
void		Walsh(int *f, int n);
int		resilience_perso(int *f, int n);
int		dist_naive(int *f, int *g, int n);
int		dist1(int *f, int *g, int n);
int		dist2(int *f, int *g, int n);
unsigned int	NL(int *f, int n);

#endif
