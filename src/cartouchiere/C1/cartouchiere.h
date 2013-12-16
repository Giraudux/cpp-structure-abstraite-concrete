// Alexis Giraudet

#ifndef CARTOUCHIERE_H
#define	CARTOUCHIERE_H

#include <exception>

struct box
{
    bool vide;
    T_ELT elt;
};

struct cartouchiere
{
    box *tab;
    int nb;
};

#endif
