// Alexis Giraudet

// C2

#ifndef CARTOUCHIERE_H
#define	CARTOUCHIERE_H

#include <iostream>
#include <exception>

struct maillon
{
    maillon *pre;
    maillon *suiv;
    int numero;
    T_ELT elt;
};
//double chaînage, maillons ordonnés par ordre croissant des numéros
struct cartouchiere
{
    maillon *tete;
    maillon *queue;
    int nb;
};

#endif
