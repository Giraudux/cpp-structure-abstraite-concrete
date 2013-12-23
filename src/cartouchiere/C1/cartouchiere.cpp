// Alexis Giraudet

// C1

#include "genericite.h"
#include "cartouchiere.h"
#include "SDAcartouchiere.h"

cartouchiere creerCartouchiere(int n)//throw std::exception
{
    if(n < 1)//taille incorrecte
    {
        throw std::exception();
    }
    else
    {
        cartouchiere c;
        initialiserCartouchiere(c, n);
        return c;
    }
}

void initialiserCartouchiere(cartouchiere &c, int n)//throw std::exception
{
    if(n < 1)//taille incorrecte
    {
        throw std::exception();
    }
    else
    {
        c.nb = n;
        c.tab = new box[n];//allocation du tableau
        //initialisation des cases du tableau
        for(int i=0; i<n; ++i)
        {
            c.tab[i].vide = true;
        }
    }
}

int taille(const cartouchiere &c)
{
    return c.nb;
}

bool estVide(const cartouchiere &c, int p)//throw std::exception
{
    if(p < 0 || p >= c.nb)//indice incorrect
    {
        throw std::exception();
    }
    else
    {
        return c.tab[p].vide;
    }
}

int ajouter(cartouchiere &c,T_ELT t)//throw std::exception
{
    for(int i=0; i<c.nb; ++i)//parcourt les cases du tableau
    {
        if(c.tab[i].vide)//ajoute l'élément dans la première case vide
        {
            c.tab[i].vide = false;
            c.tab[i].elt = t;
            return i;
        }
    }
    throw std::exception();
}

void retirer(cartouchiere &c, int p)//throw std::exception
{
    if(p < 0 || p >= c.nb)//indice incorrect
    {
        throw std::exception();
    }
    else
    {
        c.tab[p].vide = true;
    }
}

T_ELT acceder(const cartouchiere &c, int p)//throw std::exception
{
    if(p < 0 || p >= c.nb || estVide(c,p))//indice incorrect ou case vide
    {
        throw std::exception();
    }
    else
    {
        return c.tab[p].elt;
    }
}

void afficher(const cartouchiere &c)
{
    for(int i=0; i<c.nb; ++i)
    {
        std::cout << i << ": ";
        if(c.tab[i].vide)
        {
            std::cout << "vide";
        }
        else
        {
            std::cout << c.tab[i].elt;
        }
        std::cout << std::endl;
    }
}

void detruire(cartouchiere &c)
{
    delete[] c.tab;
}
